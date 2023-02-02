#ifndef JHAPPDATA_H
#define JHAPPDATA_H

#include "Framework/Interface/BObject.h"
#include "Framework/Interface/IFactory.h"
#include "JHApi/IJHAppData.h"
#include <QObject>
#include <QMap>
#include <QJsonValue>
#include "JHDataModel/JHListModel.h"
class JHMessageClient;
class JHMessageServer;
class JHAppData :
        public QObject,
        public IJHAppData,
        public BObject
{
    Q_OBJECT
    Q_PROPERTY(JHListModel * slotStateData READ getSlotStateData NOTIFY slotStateDataChanged)

public:
    Q_INVOKABLE void sendDomainData(QString domain,QJsonObject data) override;
    Q_INVOKABLE void addShareData(QString dataName, QString data);
    Q_INVOKABLE QString getShareData(QString dataName);

public:
    JHAppData();
    virtual bool initialize() override;
    virtual void terminal() override;

    void createMessageServer(QString domainID) override;
    void appendMessageClient(JHMessageClient *client, QString domainID) override;
    void removeMessageClient(JHMessageClient *client, QString domainID) override;

    JHListModel *getSlotStateData() const;

signals:
    void slotStateDataChanged();

private:
    QMap<QString, JHMessageServer*> m_messageServers;//key :domain
    QString m_cardDomain;
    QMap<QString ,QString > m_shareData;
    JHListModel *m_slotStateData;
};

X_FACTORY_DECL(JHAppData)


#endif // JHAPPDATA_H
