#include "JHListModel.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>


JHListModel::JHListModel(QObject *parent)
    : JHSimpleModel(parent)
{

}

JHListModel::~JHListModel()
{
    qDebug() << "JHListModel::~JHListModel";
}

int JHListModel::append(const QString &key, const QJsonObject &data, bool validate)
{
    if (m_nodeMap.contains(key)){
        return -1;
    }

    int result = this->addImpl(key, data);
    if (result > 0 && validate){
        emit nodeAdded(key);
    }
    return result;
}

int JHListModel::insert(int pos, const QString &key, const QJsonObject &data, bool validate)
{
    if (m_nodeMap.contains(key)){
        return -1;
    }

    JHSimpleNode * node = new JHSimpleNode(this, key);
    node->setData(data);

    m_nodeMap.insert(key, node);
    m_nodeList.insert(pos, node);

    if (validate){
        emit nodeInserted(key, pos);
    }

    return m_nodeMap.count();
}

int JHListModel::count()
{
    return m_nodeList.count();
}

int JHListModel::removeFirst(bool validate)
{
    if (m_nodeList.isEmpty()){
        return -1;
    }
    JHSimpleNode * node = m_nodeList.first();

    if (validate){
        emit this->nodeAboutToRemove(node->getNodeId());
    }

    m_nodeList.removeFirst();
    m_nodeMap.remove(node->getNodeId());
    m_trash.insert(node->getNodeId(), node);

    if (validate){
        emit this->nodeRemoved(node->getNodeId());
    }

    return m_nodeList.count();
}

int JHListModel::removeLast(bool validate)
{
    if (m_nodeList.isEmpty()){
        return -1;
    }
    JHSimpleNode * node = m_nodeList.last();

    if (validate){
        emit this->nodeAboutToRemove(node->getNodeId());
    }

    m_nodeList.removeLast();
    m_nodeMap.remove(node->getNodeId());
    m_trash.insert(node->getNodeId(), node);

    if (validate){
        emit this->nodeRemoved(node->getNodeId());
    }

    return m_nodeList.count();
}

QString JHListModel::at(int index) const
{
    JHSimpleNode * node = this->nodeAt(index);
    return node ? node->getNodeId() : QString();
}

void JHListModel::dump(const QString &filePath)
{
    qDebug() << "JHListModel::dump" << filePath;

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)){
        QJsonArray arr;
        for (int i = 0; i < m_nodeList.count(); ++i){
            arr.append(m_nodeList.at(i)->getData());
        }
        QByteArray d = QJsonDocument(arr).toJson(QJsonDocument::Indented);

        file.write(d);
        file.close();
    }else{
        qCritical() << "JHListModel::dump, open file failed," << filePath;
    }
}

JHSimpleNode * JHListModel::nodeAt(int index) const
{
    return index < m_nodeList.count() ? m_nodeList.at(index) : Q_NULLPTR;
}

const QList<JHSimpleNode *>& JHListModel::dataList() const
{
    return m_nodeList;
}

int JHListModel::addImpl(const QString &key, const QJsonObject &data)
{
    JHSimpleNode * node = new JHSimpleNode(this, key);
    node->setData(data);

    m_nodeMap.insert(key, node);
    m_nodeList.append(node);

    return m_nodeMap.count();
}

int JHListModel::removeImpl(const QString &key)
{
    JHSimpleNode * node = m_nodeMap.value(key);
    Q_ASSERT(node);

    m_nodeList.removeOne(node);
    m_trash.insert(node->getNodeId(), node);
    m_nodeMap.remove(key);

    return m_nodeMap.count();
}

void JHListModel::clearImpl()
{
    m_nodeList.clear();
    JHSimpleModel::clearImpl();
}
