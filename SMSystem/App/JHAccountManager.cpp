#include "JHAccountManager.h"
#include "Framework/Framework.h"
#include "JHSqlite/JHDatabaseModule.h"
#include <QDebug>
QString JHAccountManager::registerAccount(QString userName, QString password)
{
    QString result = "succeed";
    do{
        if (mp_sqldata->findUserInTable(userName).userName.isEmpty() == false){
            result = "已存在该账户";
            break;
        }

        tb_user user = {0,userName,password};
        if (mp_sqldata->insertUserToTable(user) == false){
            result = "注册失败";
            break;
        }
    }while(0);
    return result;
}

QString JHAccountManager::loginAccount(QString userName, QString password)
{
    QString result = "succeed";
    do{
        tb_user user = mp_sqldata->findUserInTable(userName);
        if (user.userName.isEmpty()){
            result = "不存在该账户";
            break;
        }

        if (user.password != password){
            result = "密码错误";
            break;
        }
    }while(0);
    return result;
}

QString JHAccountManager::updataAccount(QString password)
{
    QString errorText;
    return errorText;
}

QString JHAccountManager::deleteAccount(QString userName)
{
    QString errorText;
    return errorText;
}

QString JHAccountManager::addNewClassToUser(QString userName, QString studentGrade, QString studentClass)
{
    QString result = "succeed";

    do{
        tb_user user = mp_sqldata->findUserInTable(userName);
        if (user.userName.isEmpty()){
            result = "不存在该账户";
            break;
        }

        bool isExist = false;
        QVector<tb_class> usclass =  mp_sqldata->findClassInUser(user);
        for (int i=0; i < usclass.size(); i++)
        {
            if (usclass[i].studentClass == studentClass
                    &&usclass[i].studentGrade == studentGrade){
                isExist = true;
                break;
            }
        }
        if (isExist){
            result = "已存在该班级";
            break;
        }

        tb_class uclass;
        uclass.studentClass = studentClass;
        uclass.studentGrade = studentGrade;
        uclass.userIndex = user.id;

        if(mp_sqldata->insertClassToUser(uclass) == false){
            result = "添加班级失败";
            break;
        }

    }while(0);
    return result;
}

QVariantList JHAccountManager::getUeserTotalClass(QString userName)
{
    QVariantList totallClass;
    QVector<tb_class> usclass =  mp_sqldata->findClassInUser(mp_sqldata->findUserInTable(userName));
    for (int i = 0;  i < usclass.length(); i++)
    {
        QJsonObject data;
        data["class"] = usclass[i].studentClass;
        data["grade"] = usclass[i].studentGrade;
        data["classID"] = usclass[i].id;
        totallClass.append(data);
    }
    return totallClass;
}

JHAccountManager::JHAccountManager(QObject *parent) : QObject(parent)
{
    mp_sqldata =Framework::getApp()->getObjectManager()->getXService<JHSystemSqliteAccessServer>("JHSystemSqliteAccessServer")->systemSqlApi();
}
