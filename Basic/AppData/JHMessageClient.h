#ifndef JHMESSAGECLIENT_H
#define JHMESSAGECLIENT_H
#include <QString>
#include <QObject>
#include <QJsonObject>
class JHMessageClient:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString domainID READ getDomainID WRITE setDomainID)
    Q_PROPERTY(QJsonObject domainData READ getDomainData WRITE setDomainData NOTIFY domainDataChanged)
    Q_PROPERTY(QStringList filter READ getFilter WRITE setFilter)

public:
    JHMessageClient();
    ~JHMessageClient();
    const QString &getDomainID() const;
    void setDomainID(const QString &newDomain);

    const QJsonObject &getDomainData() const;
    void setDomainData(const QJsonObject newDomainData);

    const QStringList &getFilter() const;
    void setFilter(const QStringList &newFilter);

    void handleServerData(QJsonObject &data);

signals:
    void domainIDChanged(QString domain);
    void domainDataChanged(QJsonObject &data);

    void hasDomainData(QJsonObject domainData);


private:
    QString m_domainID;
    QJsonObject m_domainData;
    QStringList m_filter;
};

#endif // JHMESSAGECLIENT_H
