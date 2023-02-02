#include "JHSimpleModel.h"
#include <QJsonDocument>
#include <QFile>
#include <QDebug>


JHSimpleModel::JHSimpleModel(QObject *parent)
    : QObject(parent)
{
    m_enableSignals = true;
}

JHSimpleModel::~JHSimpleModel()
{

}

int JHSimpleModel::add(const QString &key, const QJsonObject &data, bool validate)
{
    if (m_nodeMap.contains(key)){
        qCritical() << "JHSimpleModel::add, duplicate key detected.";
        return -1;
    }

    int result = this->addImpl(key, data);
    if (validate){
        emit nodeAdded(key);
    }

    return result;
}

int JHSimpleModel::remove(const QString &key, bool validate)
{
    if (!m_nodeMap.contains(key)){
        qCritical() << "JHSimpleModel::remove, node not exists.";
        return -1;
    }

    if (validate){
        emit nodeAboutToRemove(key);
    }
    int result = this->removeImpl(key);
    if (validate){
        emit nodeRemoved(key);
    }

    return result;
}

QJsonObject JHSimpleModel::update(const QString &key, const QJsonObject &data, bool validate)
{
    JHSimpleNode * node = m_nodeMap.value(key);
    if (!node){
        return QJsonObject();
    }

    QJsonObject updatedData = node->update(data);
    if (!updatedData.isEmpty() && validate){
        emit nodeChanged(key, updatedData);
    }

    return updatedData;
}

int JHSimpleModel::count()
{
    return m_nodeMap.count();
}

bool JHSimpleModel::contains(const QString &key)
{
    return m_nodeMap.contains(key);
}

void JHSimpleModel::clear()
{
    this->clearImpl();

    emit modelChanged();
}

QStringList JHSimpleModel::keys() const
{
    QStringList result;
    QHash<QString, JHSimpleNode *>::const_iterator it = m_nodeMap.begin();
    for (; it != m_nodeMap.end(); ++it){
        result.append(it.key());
    }
    return result;
}

QJsonObject JHSimpleModel::getData(const QString &key)
{
    JHSimpleNode * node = m_nodeMap.value(key);
    if (!node){
        return QJsonObject();
    }
    return node->getData();
}

QJsonValue JHSimpleModel::getProperty(const QString &key, const QString &name)
{
    JHSimpleNode * node = m_nodeMap.value(key);
    if (!node){
        return QJsonValue();
    }
    return node->getProperty(name);
}

QString JHSimpleModel::findOne(const QString &name, const QJsonValue &value)
{
    JHSimpleNode * node = this->findNode(name, value);
    return node ? node->getNodeId() : QString();
}

QString JHSimpleModel::findOne(const QJsonObject& condition)
{
    JHSimpleNode * node = this->findNode(condition);
    return node ? node->getNodeId() : QString();
}

QStringList JHSimpleModel::findMany(const QString &name, const QJsonValue &value)
{
    QStringList result;
    QList<JHSimpleNode *> nodes = this->findNodes(name, value);
    for (int i = 0; i < nodes.count(); ++i){
        result.append(nodes.at(i)->getNodeId());
    }
    return result;
}

QStringList JHSimpleModel::findMany(const QJsonObject& condition)
{
    QStringList result;
    QList<JHSimpleNode *> nodes = this->findNodes(condition);
    for (int i = 0; i < nodes.count(); ++i){
        result.append(nodes.at(i)->getNodeId());
    }
    return result;
}

int JHSimpleModel::updateMany(const QJsonObject &condition, const QJsonObject &data, bool validate)
{
    int cc = 0;
    QJsonObject t;
    QHash<QString, JHSimpleNode *>::iterator it = m_nodeMap.begin();
    for (; it != m_nodeMap.end(); ++it){
        bool matchResult = this->match(it.value(), condition);
        if (matchResult){
            t = it.value()->update(data);
            if (!t.isEmpty()){
                cc += 1;
            }
        }
    }
    if (cc > 0 && validate){
        this->invalidate();
    }
    return cc;
}

void JHSimpleModel::invalidate()
{
    emit this->modelChanged();

    this->clearTrash();
}

//void JHSimpleModel::enableSignals(bool enable)
//{
//    m_enableSignals = enable;
//}

void JHSimpleModel::dump(const QString &filePath)
{
    qDebug() << "JHSimpleModel::dump" << filePath;

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)){
        QJsonObject obj;
        QHash<QString, JHSimpleNode *>::iterator it = m_nodeMap.begin();
        for (; it != m_nodeMap.end(); ++it){
            obj.insert(it.key(), it.value()->getData());
        }
        QByteArray d = QJsonDocument(obj).toJson(QJsonDocument::Indented);

        file.write(d);
        file.close();
    }else{
        qCritical() << "JHSimpleModel::dump, open file failed," << filePath;
    }
}

JHSimpleNode * JHSimpleModel::getNode(const QString &key) const
{
    return m_nodeMap.value(key);
}

JHSimpleNode * JHSimpleModel::findNode(const QString &name, const QJsonValue &value) const
{
    QHash<QString, JHSimpleNode *>::const_iterator it = m_nodeMap.begin();
    for (; it != m_nodeMap.end(); ++it){
        JHSimpleNode * node = it.value();
        QJsonValue v = node->getProperty(name);
        if (value == v){
            return node;
        }
    }
    return Q_NULLPTR;
}

JHSimpleNode * JHSimpleModel::findNode(const QJsonObject& condition) const
{
    QHash<QString, JHSimpleNode *>::const_iterator it = m_nodeMap.begin();
    for (; it != m_nodeMap.end(); ++it){
        JHSimpleNode * node = it.value();
        QJsonObject::const_iterator it2 = condition.begin();
        bool match = true;
        for (; it2 != condition.end(); ++it2){
            if (node->getProperty(it2.key()) != it2.value()){
                match = false;
                break;
            }
        }
        if (match){
            return node;
        }
    }
    return Q_NULLPTR;
}

QList<JHSimpleNode *> JHSimpleModel::findNodes(const QString& name, const QJsonValue& value) const
{
    QList<JHSimpleNode *> result;

    QHash<QString, JHSimpleNode *>::const_iterator it = m_nodeMap.begin();
    for (; it != m_nodeMap.end(); ++it){
        JHSimpleNode * node = it.value();
        QJsonValue v = node->getProperty(name);
        if (value == v){
            result.append(node);
        }
    }
    return result;
}

QList<JHSimpleNode *> JHSimpleModel::findNodes(const QJsonObject& condition) const
{
    QList<JHSimpleNode *> result;

    QHash<QString, JHSimpleNode *>::const_iterator it = m_nodeMap.begin();
    for (; it != m_nodeMap.end(); ++it){
        JHSimpleNode * node = it.value();
        QJsonObject::const_iterator it2 = condition.begin();
        bool match = true;
        for (; it2 != condition.end(); ++it2){
            if (node->getProperty(it2.key()) != it2.value()){
                match = false;
                break;
            }
        }
        if (match){
            result.append(node);
        }
    }
    return result;
}

bool JHSimpleModel::match(JHSimpleNode *node, const QJsonObject &condition) const
{
    bool matchResult = true;
    QJsonObject::const_iterator it2 = condition.begin();
    for (; it2 != condition.end(); ++it2){
        if (node->getProperty(it2.key()) != it2.value()){
            matchResult = false;
            break;
        }
    }
    return matchResult;
}

void JHSimpleModel::clearTrash()
{
    QHash<QString, JHSimpleNode *>::iterator it = m_trash.begin();
    for (; it != m_trash.end(); ++it){
        it.value()->deleteLater();
    }
    m_trash.clear();
}

void JHSimpleModel::deleteFromTrash(const QString &key)
{
    JHSimpleNode * node = m_trash.value(key);
    if (node){
        m_trash.remove(key);
        node->deleteLater();
    }
}

int JHSimpleModel::addImpl(const QString &key, const QJsonObject &data)
{
    JHSimpleNode * node = new JHSimpleNode(this, key);
    node->setData(data);

    m_nodeMap.insert(key, node);

    return m_nodeMap.count();
}

int JHSimpleModel::removeImpl(const QString &key)
{
    JHSimpleNode * node = m_nodeMap.value(key);
    Q_ASSERT(node);

    m_trash.insert(node->getNodeId(), node);
    m_nodeMap.remove(key);

    return m_nodeMap.count();
}

void JHSimpleModel::clearImpl()
{
    QHash<QString, JHSimpleNode *>::iterator it = m_nodeMap.begin();
    for (; it != m_nodeMap.end(); ++it){
        m_trash.insert(it.key(), it.value());
    }
    m_nodeMap.clear();
}
