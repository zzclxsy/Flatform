#ifndef JHLISTVIEWMODEL_H
#define JHLISTVIEWMODEL_H
#include <QAbstractListModel>
#include "JHListModel.h"

class JHListViewModel:public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(JHListModel * dataSource READ getDataSource WRITE setDataSource NOTIFY dataSourceChanged)
    Q_PROPERTY(QJsonObject roleMap READ getRoleMap WRITE setRoleMap NOTIFY roleMapChanged)
public:
    JHListViewModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    JHListModel *getDataSource() const;
    void setDataSource(JHListModel *newDataSource);

    const QJsonObject &getRoleMap() const;
    void setRoleMap(const QJsonObject &newRoleMap);


public slots:
    void onModelDestroyed(QObject *obj);
    void onModelChanged();
    void onNodeAdded(const QString& nodeId);
    void onNodeInserted(const QString& nodeId, int pos);
    void onNodeAboutToRemove(const QString& nodeId);
    void onNodeRemoved(const QString& nodeId);
    void onNodeChanged(const QString& nodeId, const QJsonObject& updatedData);


signals:
    void dataSourceChanged();

    void roleMapChanged();

private:
    JHListModel *m_dataSource;
    QJsonObject m_roleMap;
};

#endif // JHLISTMODEL_H
