#include "JHMessageServer.h"
#include "JHMessageClient.h"
#include <QDebug>
JHMessageServer::JHMessageServer()
{

}

JHMessageServer::~JHMessageServer()
{
}

void JHMessageServer::appendMessageClient(JHMessageClient *client)
{
    connect(client, &JHMessageClient::domainIDChanged, this, &JHMessageServer::DomainIDChange);
    connect(client, &JHMessageClient::domainDataChanged, this, &JHMessageServer::DomainDataChange);

    if (m_clients.contains(client) == false)
        m_clients.append(client);
}

void JHMessageServer::removeMessageClient(JHMessageClient *client)
{
    m_clients.removeOne(client);
}

const QString &JHMessageServer::GetDomain() const
{
    return m_domainID;
}

void JHMessageServer::SetDomain(const QString &newDomain)
{
    if (m_domainID == newDomain)
        return;
    qDebug()<<"HMessageServer::SetDomain"<<newDomain;
    m_domainID = newDomain;
}

void JHMessageServer::SendDomainData(QJsonObject &data)
{
    m_domainData = data;
    foreach(JHMessageClient *client, m_clients)
    {
        client->handleServerData(data);
    }
}

void JHMessageServer::DomainIDChange(QString domainID)
{
    if (domainID != m_domainID)
    {
        qDebug()<<"JHMessageServer::DomainChange"<<domainID<<m_domainID;
        JHMessageClient *client = static_cast<JHMessageClient *>(sender());
        disconnect(client, &JHMessageClient::domainIDChanged, this, &JHMessageServer::DomainIDChange);
        m_clients.removeOne(client);
    }
}

void JHMessageServer::DomainDataChange(QJsonObject &data)
{
    if (m_domainData != data){
        SendDomainData(data);
    }
}
