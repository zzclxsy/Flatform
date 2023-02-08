#include "JHListViewModel.h"
#include <QDebug>
#include <QJsonObject>

const int ID_ROLE = Qt::UserRole + 1;
const int STATUS_ROLE = Qt::UserRole + 2;
const int CC_ROLE = Qt::UserRole + 3;
const int INDEX_ROLE = Qt::UserRole + 4;
const int MODEL_ROLE = Qt::UserRole + 5;

JHListViewModel::JHListViewModel()
{

}

int JHListViewModel::rowCount(const QModelIndex &parent) const
{
    return m_dataSource->count();
}

QVariant JHListViewModel::data(const QModelIndex &index, int role) const
{
    int rowIndex = index.row();

    JHSimpleNode * node = m_dataSource->nodeAt(rowIndex);
    if (!node){
        return QVariant(QString());
    }

    switch (role) {
    case ID_ROLE:
        return node->getNodeId();
    case STATUS_ROLE:
        return QVariant(QString(""));
    case CC_ROLE:
        return m_roleMap.count();
    case INDEX_ROLE:
        return index.row();
    case MODEL_ROLE:
    {
        QJsonObject data;
        QJsonObject::const_iterator it = m_roleMap.begin();
        for (; it != m_roleMap.end(); ++it){
            QString roleName = it.key();
            QString srcRoleName = it.value().toString();
            QJsonValue roleValue = node->getProperty(srcRoleName);
            data.insert(roleName, roleValue);
            data.insert(srcRoleName, roleValue);


        }
        return QVariant(data);
    }
    default:
        break;
    }
    return QVariant(QString());
}

QHash<int, QByteArray> JHListViewModel::roleNames() const
{
    QHash<int, QByteArray> roleMap;

    roleMap.insert(ID_ROLE, "Rid");
    roleMap.insert(STATUS_ROLE, "status");
    roleMap.insert(CC_ROLE, "NCols");
    roleMap.insert(INDEX_ROLE, "index");
    roleMap.insert(MODEL_ROLE, "data");

    return roleMap;
}


JHListModel *JHListViewModel::getDataSource() const
{
    return m_dataSource;
}

void JHListViewModel::setDataSource(JHListModel *dataSource)
{
    if (m_dataSource == dataSource){
        return;
    }
    if (m_dataSource){
        m_dataSource->disconnect(this,0,0,0);
    }
    m_dataSource = dataSource;

    emit dataSourceChanged();

    if (!m_dataSource){
        return;
    }

    connect(m_dataSource,
            SIGNAL(destroyed(QObject*)),
            this,
            SLOT(onModelDestroyed(QObject*)));
    connect(m_dataSource,
            SIGNAL(modelChanged()),
            this,
            SLOT(onModelChanged()));


    connect(m_dataSource,
            SIGNAL(nodeAdded(QString)),
            this,
            SLOT(onNodeAdded(QString)));
    connect(m_dataSource,
            SIGNAL(nodeInserted(QString, int)),
            this,
            SLOT(onNodeInserted(QString, int)));
    connect(m_dataSource,
            SIGNAL(nodeAboutToRemove(QString)),
            this,
            SLOT(onNodeAboutToRemove(QString)));
    connect(m_dataSource,
            SIGNAL(nodeRemoved(QString)),
            this,
            SLOT(onNodeRemoved(QString)));
    connect(m_dataSource,
            SIGNAL(nodeChanged(QString, QJsonObject)),
            this,
            SLOT(onNodeChanged(QString, QJsonObject)));
}

const QJsonObject &JHListViewModel::getRoleMap() const
{
    return m_roleMap;
}

void JHListViewModel::setRoleMap(const QJsonObject &newRoleMap)
{
    if (m_roleMap == newRoleMap)
        return;
    m_roleMap = newRoleMap;
    emit roleMapChanged();
}

void JHListViewModel::onModelDestroyed(QObject * obj)
{
    m_dataSource = Q_NULLPTR;

    this->beginResetModel();
    this->endResetModel();
}

void JHListViewModel::onModelChanged()
{
//    this->invalidate();
//    emit displayCountChanged();
}

void JHListViewModel::onNodeAdded(const QString& )
{

    Q_ASSERT(m_dataSource);

    // notify changes
    int row =m_dataSource->count() - 1;
    this->beginInsertRows(this->index(0).parent(), row, row);
    this->endInsertRows();
}

void JHListViewModel::onNodeInserted(const QString& , int pos)
{
    Q_ASSERT(m_dataSource);

    this->beginInsertRows(this->index(0).parent(), pos, pos);
    this->endInsertRows();

}

void JHListViewModel::onNodeAboutToRemove(const QString& nodeId)
{
    Q_ASSERT(m_dataSource);

    JHSimpleNode * node = m_dataSource->getNode(nodeId);
    if (!node){
        return;
    }

   int i1 = m_dataSource->dataList().indexOf(node);

   this->beginRemoveRows(this->index(0).parent(), i1, i1);
   this->endRemoveRows();
}

void JHListViewModel::onNodeRemoved(const QString& nodeId)
{
    Q_ASSERT(m_dataSource);
    m_dataSource->deleteFromTrash(nodeId);
    emit removeData();
}

void JHListViewModel::onNodeChanged(const QString& nodeId, const QJsonObject& )
{
    JHSimpleNode * node = m_dataSource->getNode(nodeId);
    int row = m_dataSource->dataList().indexOf(node);
    if (row < 0){
        return;
    }

    QModelIndex index = this->index(row);
    emit dataChanged(index, index);
}

