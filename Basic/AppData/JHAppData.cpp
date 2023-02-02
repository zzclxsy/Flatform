#include "JHAppData.h"
#include "JHMessageServer.h"
#include "JHMessageClient.h"
#include <QDebug>
#include <QQmlEngine>

X_FACTORY_IMPL(JHAppData)
JHAppData::JHAppData()
{
    m_slotStateData = new JHListModel(this);
}

bool JHAppData::initialize()
{
    return true;
}

void JHAppData::terminal()
{

}

void JHAppData::createMessageServer(QString domainID)
{
    if (m_messageServers.contains(domainID) == false) {
        m_messageServers.insert(domainID, new JHMessageServer());
        m_messageServers[domainID]->SetDomain(domainID);
        return;
    }

    qWarning()<<"JHAppData::CreateDomain:"<<"已存在该domain";
}

void JHAppData::appendMessageClient(JHMessageClient *client, QString domainID)
{
    if (m_messageServers.contains(domainID) == false){
        createMessageServer(domainID);
    }

    m_messageServers.value(domainID)->appendMessageClient(client);
}

void JHAppData::removeMessageClient(JHMessageClient *client, QString domainID)
{
    auto it = m_messageServers.find(domainID);
    if (it != m_messageServers.end())
    {
        m_messageServers.value(domainID)->removeMessageClient(client);
    }
}

void JHAppData::sendDomainData(QString domain, QJsonObject data)
{
    auto it = m_messageServers.find(domain);
    if (it != m_messageServers.end())
    {
        m_messageServers.value(domain)->SendDomainData(data);
    }
}

void JHAppData::addShareData(QString dataName, QString data)
{
    m_shareData.insert(dataName,data);
}

QString JHAppData::getShareData(QString dataName)
{
    if (m_shareData.contains(dataName)){
        return m_shareData[dataName];
    }
    return "";
}


JHListModel *JHAppData::getSlotStateData() const
{
    return m_slotStateData;
}
