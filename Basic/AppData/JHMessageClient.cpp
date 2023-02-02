#include "JHMessageClient.h"
#include "../Framework/Framework.h"
#include "JHAppData.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonParseError>
#include "../Framework/Utility.h"
#include "AppData/JHAppData.h"
JHMessageClient::JHMessageClient()
{

}

JHMessageClient::~JHMessageClient()
{
    Framework::getApp()->getObjectManager()->getXService<JHAppData>("JHAppDataServer")->removeMessageClient(this,m_domainID);
}


const QString &JHMessageClient::getDomainID() const
{
    return m_domainID;
}

void JHMessageClient::setDomainID(const QString &newDomainID)
{
    qDebug()<<"JHMessageClient::SetDomain:"<<newDomainID;
    if (m_domainID == newDomainID)
        return;

    m_domainID = newDomainID;
    Framework::getApp()->getObjectManager()->getXService<JHAppData>("JHAppDataServer")->appendMessageClient(this, m_domainID);
    emit domainIDChanged(m_domainID);
}


const QJsonObject &JHMessageClient::getDomainData() const
{
    return m_domainData;
}

void JHMessageClient::setDomainData(const QJsonObject newDomainData)
{
    if (m_domainData == newDomainData)
        return;

    m_domainData = newDomainData;
    emit domainDataChanged(m_domainData);
}

const QStringList &JHMessageClient::getFilter() const
{
    return m_filter;
}

void JHMessageClient::setFilter(const QStringList &newFilter)
{
    if (m_filter == newFilter)
        return;

    m_filter = newFilter;
}

void JHMessageClient::handleServerData(QJsonObject &data)
{
    if (m_domainData == data)
        return;

    QJsonObject newRoot;

    foreach(QString filter, m_filter){
        if (data.contains(filter)){
            newRoot[filter] = data.value(filter);
        }
    }

    if (newRoot.isEmpty() == false){
        m_domainData = data;
        emit hasDomainData(newRoot);
    }
}
