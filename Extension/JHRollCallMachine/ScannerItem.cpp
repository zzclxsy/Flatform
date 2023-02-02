#include "ScannerItem.h"
#include <QDebug>
#include <QQuickWindow>
#include <QPainter>
#include <QTimer>
#include <QtMath>
#include <QList>
ScannerItem::ScannerItem(QQuickItem *parent)
    : QQuickPaintedItem (parent)
{
    qsrand(uint (time(nullptr)));
    m_updateTimer = new QTimer(this);
    m_updateTimer->setInterval(14);
    connect(m_updateTimer, &QTimer::timeout, this, [this](){ update(); });

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [=] {
        m_points.clear();

        int index = 0;
        while(true)
        {
            int min = int(qMin(width(), height()));
            QPoint center(int(width() / 2), int(height() / 2));

            int orgPosX = center.x() - min/2;
            int orgPosY = center.y() - min/2;
            int alpha = qrand() % 100 + 40;
            int px = qrand() % int(min);
            int py = qrand() % int(min);
            QPoint pos = QPoint(orgPosX + px, orgPosY +py);
            if (((pos.x() - center.x())*(pos.x() - center.x()))
                    +((pos.y() - center.y())*(pos.y() - center.y())) > (((min/2-7)*(min/2-7))))
            {
                continue;
            }
            m_points.append(Point(pos, alpha));

            index++;
            if (index == 4)
                break;
        }
    });

    timer->start(500);
}

ScannerItem::~ScannerItem()
{

}

void ScannerItem::start()
{
    m_drawable = true;
    m_scanable = true;
    m_angle = 0;
    m_updateTimer->start();
}

void ScannerItem::stop()
{
    m_scanable = false;
    m_updateTimer->stop();
    update();
}

QPoint ScannerItem::scanResult()
{
    update();
    QList<QPoint> Points;
    for (int i = 0;i < m_points.size();i++)
    {
        Points.push_back(m_points.at(i).point);
    }
    return Points[0];
}

void ScannerItem::paint(QPainter *painter)
{
    painter->setRenderHint(QPainter::Antialiasing);

    int min = int(qMin(width(), height()));
    QPoint center(int(width() / 2), int(height() / 2));
    painter->setPen(QPen(Qt::NoPen));
    painter->setBrush(QColor(0,155,201));
    painter->drawEllipse(center, min/2, min/2);

    QPen pen;
    pen.setStyle(Qt::DashDotLine);
    pen.setColor(QColor(255,255,255));
    painter->setPen(pen);
    painter->drawEllipse(center, min / 3, min / 3);
    painter->drawEllipse(center, min / 7, min / 7);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    painter->drawLine(center+QPoint(0,-min),center+QPoint(0,min));
    painter->drawLine(center+QPoint(-min,0),center+QPoint(min,0));

    if (m_drawable) {
        if (m_scanable)
        {
            int diff = int(qAbs(width() - height()) / 2);
            QConicalGradient gradient(width() / 2, height() / 2, m_angle);
            gradient.setColorAt(0, QColor(255,255,255, 255));
            gradient.setColorAt(0.4, QColor(0,178,142, 100));
            gradient.setColorAt(0.7, QColor(0,0,0, 0));
            gradient.setColorAt(1, QColor(0,0,0, 0));
            painter->setBrush(gradient);
            painter->setPen(QPen(Qt::NoPen));
            if (width() > height())
                painter->drawPie(diff, 0, min, min, m_angle * 16, 200 * 16);
            else
                painter->drawPie(0, diff, min, min, m_angle * 16, 200 * 16);

            m_angle -= 8;
            if (m_angle == -360)
                m_angle = 0;

            if (m_points.size() == 0)
                return;
        }

        for(int i = 0; i < m_points.size(); ++i) {

            painter->setPen(QPen(Qt::NoPen));
            painter->setBrush(QColor(15, 45, 188,180));
            painter->drawEllipse(m_points.at(i).point, 10, 10);
        }

    }
}
