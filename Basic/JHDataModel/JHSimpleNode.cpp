#include "JHSimpleNode.h"
#include <QDebug>


JHSimpleNode::JHSimpleNode(QObject *parent, const QString& id)
    : QObject(parent)
{
    m_nodeId = id;
    m_data.insert("_id", m_nodeId);
}

JHSimpleNode::~JHSimpleNode()
{

}

QString JHSimpleNode::getNodeId()
{
    return m_nodeId;
}

QVariant JHSimpleNode::toVariant()
{
//    qDebug() << "JHSimpleNode::toVariant" << m_data;
    return QVariant(m_data);
}

void JHSimpleNode::setData(const QJsonObject &data)
{
    m_data = data;
    m_data.insert("_id", m_nodeId);
}

void JHSimpleNode::setProperty(const QString &name, const QJsonValue &value)
{
    Q_ASSERT(name != QString("_id"));
    m_data.insert(name, value);
}

QJsonObject JHSimpleNode::update(const QJsonObject &data)
{
    QJsonObject result;
    QJsonObject::const_iterator it = data.begin();
    for (; it != data.end(); ++it){
        //Q_ASSERT(it.key() != QString("_id"));
        if (m_data.value(it.key()) == it.value()){
            continue;
        }else{
            m_data.insert(it.key(), it.value());
            result.insert(it.key(), it.value());
        }
    }
    return result;
}

const QJsonObject& JHSimpleNode::getData() const
{
    return m_data;
}

bool JHSimpleNode::hasProperty(const QString &name) const
{
    return m_data.contains(name);
}

QJsonValue JHSimpleNode::getProperty(const QString &name) const
{
    return m_data.value(name);
}

QString JHSimpleNode::getString(const QString &name) const
{
    QJsonValue v = m_data.value(name);
    switch (v.type()) {
    case QJsonValue::Null:
        return "";
    case QJsonValue::Bool:
        return v.toBool() ? "true" : "false";
    case QJsonValue::Double:
        return QString::number(v.toDouble());
    case QJsonValue::String:
        return v.toString();
    default:
        break;
    }
    return "";
}

qint64 JHSimpleNode::getLongLong(const QString &name) const
{
    QJsonValue v = m_data.value(name);
    switch (v.type()) {
    case QJsonValue::Null:
        return 0;
    case QJsonValue::Bool:
        return v.toBool() ? 1 : 0;
    case QJsonValue::Double:
        return (qint64)v.toDouble();
    case QJsonValue::String:
        return v.toString().toLongLong();
    default:
        break;
    }
    return 0;
}

QJsonObject JHSimpleNode::toJsonObject()
{
    return m_data;
}
