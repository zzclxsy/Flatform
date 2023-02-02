#ifndef JHQMLCONTROLS_H
#define JHQMLCONTROLS_H


#include <QQuickItem>

class JHQmlControls : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(JHQmlControls)

public:
    explicit JHQmlControls(QQuickItem *parent = nullptr);
    ~JHQmlControls() override;
};


#endif // JHQMLCONTROLS_H
