#ifndef JHSIMPLENODE_H
#define JHSIMPLENODE_H


#include <QObject>
#include <QJsonObject>
#include <QJsonValue>
#include <QVariant>

class JHSimpleNode
        : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nodeId READ getNodeId NOTIFY nodeIdChanged)
public:
    explicit JHSimpleNode(QObject *parent, const QString& id);
    virtual ~JHSimpleNode();

    QString getNodeId();
    QVariant toVariant();

    Q_INVOKABLE void setData(const QJsonObject& data);
    Q_INVOKABLE void setProperty(const QString& name, const QJsonValue& value);
    Q_INVOKABLE QJsonObject update(const QJsonObject& data);

    Q_INVOKABLE const QJsonObject& getData() const;
    Q_INVOKABLE bool hasProperty(const QString& name) const;
    Q_INVOKABLE QJsonValue getProperty(const QString& name) const;
    Q_INVOKABLE QString getString(const QString& name) const;
    Q_INVOKABLE qint64 getLongLong(const QString& name) const;

    Q_INVOKABLE virtual QJsonObject toJsonObject();

signals:
    void nodeIdChanged();

protected:
    QString m_nodeId;
    QJsonObject m_data;
};

#endif // JHSIMPLENODE_H
