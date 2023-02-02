#ifndef JHLISTMODEL_H
#define JHLISTMODEL_H

#include <QObject>
#include "JHSimpleModel.h"

class JHListModel
        : public JHSimpleModel
{
    Q_OBJECT
public:
    explicit JHListModel(QObject *parent = Q_NULLPTR);
    virtual ~JHListModel();

    Q_INVOKABLE virtual int append(const QString& key, const QJsonObject& data, bool validate=false);
    Q_INVOKABLE virtual int insert(int pos, const QString& key, const QJsonObject& data, bool validate=false);
    Q_INVOKABLE int count();
    Q_INVOKABLE int removeFirst(bool validate=false);
    Q_INVOKABLE int removeLast(bool validate=false);
    Q_INVOKABLE QString at(int index) const;

//    Q_INVOKABLE QString matchOne(const QString& name, const QString& regExp);
//    Q_INVOKABLE QStringList matchMany(const QString& name, const QString& regExp);

    Q_INVOKABLE virtual void dump(const QString& filePath);

public:
    JHSimpleNode * nodeAt(int index) const;
    const QList<JHSimpleNode *>& dataList() const;

signals:
    void nodeInserted(const QString& nodeId, int pos);

protected:

protected:
    virtual int addImpl(const QString& key, const QJsonObject& data);
    virtual int removeImpl(const QString& key);
    virtual void clearImpl();

protected:
    QList<JHSimpleNode *> m_nodeList;
};

#endif // JHLISTMODEL_H
