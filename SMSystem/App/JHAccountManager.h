#ifndef JHACCOUNTMANAGER_H
#define JHACCOUNTMANAGER_H

#include <QObject>
#include <QVariantList>
#include <QJsonObject>
class JHSystemSqliteAccess;
class JHAccountManager : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE QString registerAccount(QString userName,QString password);
    Q_INVOKABLE QString loginAccount(QString userName,QString password);
    Q_INVOKABLE QString updataAccount(QString password);
    Q_INVOKABLE QString deleteAccount(QString userName);

    Q_INVOKABLE QString addNewClassToUser(QString userName,QString studentGrade,QString studentClass);
    Q_INVOKABLE QVariantList getUeserTotalClass(QString userName);


public:
    explicit JHAccountManager(QObject *parent = nullptr);

private:
    JHSystemSqliteAccess *mp_sqldata;
signals:

};

#endif // JHACCOUNTMANAGER_H
