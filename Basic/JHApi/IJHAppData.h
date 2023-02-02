#ifndef IJHAPPDATA_H
#define IJHAPPDATA_H
#include <QString>
#include <QJsonObject>
class JHMessageClient;
class IJHAppData{
public:
    virtual void createMessageServer(QString domainID) = 0;
    virtual void appendMessageClient(JHMessageClient *client, QString domainID) = 0;
    virtual void removeMessageClient(JHMessageClient *client, QString domainID) = 0;
    virtual void sendDomainData(QString domainID,QJsonObject  data) = 0;
};

#endif // IJHAPPDATA_H
