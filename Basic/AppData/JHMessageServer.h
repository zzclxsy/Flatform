#ifndef JHMESSAGESERVER_H
#define JHMESSAGESERVER_H
#include <QObject>
#include<QList>
#include <QJsonValue>
class JHMessageClient;
class JHMessageServer:public QObject
{
    Q_OBJECT
public:
    JHMessageServer();
    ~JHMessageServer();

    void appendMessageClient(JHMessageClient *);
    void removeMessageClient(JHMessageClient *);
    const QString &GetDomain() const;
    void SetDomain(const QString &newDomain);
    void SendDomainData(QJsonObject &data);

protected:
    void DomainIDChange(QString domain);
    void DomainDataChange(QJsonObject &data);
private:
    QList<JHMessageClient *> m_clients;
    QString m_domainID;
    QJsonValue m_domainData;
};

#endif // JHMESSAGESERVER_H
