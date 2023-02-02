#ifndef JHSIMPLEMODEL_H
#define JHSIMPLEMODEL_H

#include <QObject>
#include <QHash>
#include <QSet>
#include "JHSimpleNode.h"


class JHSimpleModel
        : public QObject
{
    Q_OBJECT
public:
    explicit JHSimpleModel(QObject *parent = Q_NULLPTR);
    virtual ~JHSimpleModel();

    Q_INVOKABLE virtual int add(const QString& key, const QJsonObject& data, bool validate=false);
    Q_INVOKABLE virtual int remove(const QString& key, bool validate=false);
    Q_INVOKABLE virtual QJsonObject update(const QString& key, const QJsonObject& data, bool validate=false);

    Q_INVOKABLE int count();
    Q_INVOKABLE bool contains(const QString& key);
    Q_INVOKABLE void clear();

    Q_INVOKABLE QStringList keys() const;
    Q_INVOKABLE QJsonObject getData(const QString& key);
    Q_INVOKABLE QJsonValue getProperty(const QString& key, const QString& name);

    Q_INVOKABLE QString findOne(const QString& name, const QJsonValue& value);
    Q_INVOKABLE QString findOne(const QJsonObject& condition);
    Q_INVOKABLE QStringList findMany(const QString& name, const QJsonValue& value);
    Q_INVOKABLE QStringList findMany(const QJsonObject& condition);
    Q_INVOKABLE int updateMany(const QJsonObject& condition, const QJsonObject& data, bool validate=false);

    Q_INVOKABLE void invalidate();
//    Q_INVOKABLE void enableSignals(bool enable);

    Q_INVOKABLE virtual void dump(const QString& filePath);

    JHSimpleNode * getNode(const QString& key) const;
    JHSimpleNode * findNode(const QString& name, const QJsonValue& value) const;
    JHSimpleNode * findNode(const QJsonObject& condition) const;
    QList<JHSimpleNode *> findNodes(const QString& name, const QJsonValue& value) const;
    QList<JHSimpleNode *> findNodes(const QJsonObject& condition) const;
    bool match(JHSimpleNode * node, const QJsonObject& condition) const;
    void clearTrash();
    void deleteFromTrash(const QString& key);

signals:
    void modelChanged();
    void nodeAdded(const QString& nodeId);
    void nodeAboutToRemove(const QString& nodeId);
    void nodeRemoved(const QString& nodeId);
    void nodeChanged(const QString& nodeId, const QJsonObject& updatedData);

protected:
    virtual int addImpl(const QString& key, const QJsonObject& data);
    virtual int removeImpl(const QString& key);
    virtual void clearImpl();

protected:
    QHash<QString, JHSimpleNode *> m_nodeMap;
    bool m_enableSignals;
    QHash<QString, JHSimpleNode *> m_trash;
};

#endif // JHSIMPLEMODEL_H
