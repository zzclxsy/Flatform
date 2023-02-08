#include "JHSystemSqliteAccess.h"
#include <QDebug>
JHSystemSqliteAccess::JHSystemSqliteAccess(QString dbName):JHBaseSqliteAccess(dbName)
{
    QStringList execStrs;
    execStrs << QString ("PRAGMA recursive_triggers = ON;");
    /* 检查群组表是否存在 */
    if (!checkTable(QString("user_tb")))
    {
        execStrs << QString("create table user_tb(		\
                                id integer primary key,		\
                            userName varchar(128) default '',\
                            userPassword varchar(128) default ''\
                            );");
    }



    if (!checkTable(QString("class_tb")))
    {
        execStrs << QString("create table class_tb(		\
                                id integer primary key,		\
                            grade varchar(128) default '',\
                            class varchar(128) default '',\
                            userIndex int default 0\
                            );");
    }

    if (!checkTable(QString("student_tb")))
    {
        execStrs << QString("create table student_tb(		\
                                id integer primary key,		\
                            studentName varchar(128) default '',\
                            sex varchar(128) default '',\
                            age varchar(128) default '',\
                            remark varchar(1024) default '',\
                            classIndex int default 0\
                            );");
    }

    if (!checkTable(QString("score_tb")))
    {
        execStrs << QString("create table score_tb(		\
                                id integer primary key,		\
                            chinese varchar(128) default '',\
                            mathematics varchar(128) default '',\
                            english varchar(128) default '',\
                            physics varchar(128) default '',\
                            chemistry varchar(128) default '',\
                            biology varchar(128) default '',\
                            geography varchar(128) default '',\
                            history varchar(128) default '',\
                            politics varchar(128) default '',\
                            testDate varchar(128) default '',\
                            studentIndex int default 0,\
                            classIndex int default 0\
                            );");
    }

    //=====================================创建触发器==========================================


    //========================================================================================
    if (execStrs.count() <= 0)
        return;

    transaction();

    for (const QString &execStr: qAsConst(execStrs))
    {
        qDebug()<<execStr;
        write(execStr);
    }

    commit();
}

bool JHSystemSqliteAccess::insertUserToTable(tb_user user)
{
    QString execStr = QString("insert into user_tb values(NULL,'%1', '%2');")
            .arg(user.userName).arg(user.password);

    return write(execStr);
}

bool JHSystemSqliteAccess::removeUserInTable(QString userName)
{
    QString execStr = QString("delete from user_tb where userName='%1';")
                .arg(userName);

    return write(execStr);
}

bool JHSystemSqliteAccess::updataUserInTable(tb_user user)
{
    QString exec = QString ("update user_tb set userPassword='%1' where userName = '%2';")
            .arg(user.password).arg(user.userName);

    return write(exec);
}

tb_user JHSystemSqliteAccess::findUserInTable(QString userName)
{
    QString exec = QString ("select * from user_tb where userName = '%1';")
            .arg(userName);

    tb_user user;

    QList<QStringList> retList;

    if (read(exec, retList) == false || retList.count() == 0)
            return user;

    user.id = retList.at(0).at(0).toUInt();
    user.userName = retList.at(0).at(1);
    user.password = retList.at(0).at(2);
    return user;
}

bool JHSystemSqliteAccess::insertClassToUser(tb_class userClass)
{
    QString execStr = QString("insert into class_tb values(NULL,'%1', '%2', '%3');")
            .arg(userClass.studentGrade).arg(userClass.studentClass).arg(userClass.userIndex);

    return write(execStr);
}

bool JHSystemSqliteAccess::removeClassInUser(tb_class userClass)
{
    QString execStr = QString("delete from class_tb where userIndex='%1' and grade='%2' and class='%3';")
                .arg(userClass.userIndex).arg(userClass.studentGrade).arg(userClass.studentClass);

    return write(execStr);
}

QVector<tb_class> JHSystemSqliteAccess::findClassInUser(tb_user user)
{
    QString exec = QString ("select * from class_tb where userIndex = '%1';")
            .arg(user.id);

   QVector<tb_class> userclass;

    QList<QStringList> retList;

    if (read(exec, retList) == false || retList.count() == 0)
            return userclass;

    for (int i = 0; i < retList.size(); i++)
    {
        tb_class uclass;
        uclass.id =             retList.at(i).at(0).toUInt();
        uclass.studentGrade =   retList.at(i).at(1);
        uclass.studentClass =   retList.at(i).at(2);
        uclass.userIndex =      retList.at(i).at(3).toUInt();
        userclass.append(uclass);
    }

    return userclass;
}

bool JHSystemSqliteAccess::insertStudentToClass(tb_student student)
{
    QString execStr = QString("insert into student_tb values(NULL,'%1', '%2', '%3','%4','%5');")
            .arg(student.studentName).arg(student.studentSex).arg(student.studentAge).arg(student.remark).arg(student.classIndex);

    return write(execStr);
}

bool JHSystemSqliteAccess::updataStudentToClass(tb_student student)
{
    QString exec = QString ("update student_tb set studentName='%1',sex='%2',age='%3',remark='%4' where id = '%5';")
            .arg(student.studentName).arg(student.studentSex).arg("").arg(student.remark).arg(student.id);

    return write(exec);
}

QVector<tb_student> JHSystemSqliteAccess::getStudentInClass(int classID)
{
    QString exec = QString ("select * from student_tb where classIndex = '%1';")
            .arg(classID);

   QVector<tb_student> userclass;

    QList<QStringList> retList;

    if (read(exec, retList) == false || retList.count() == 0)
            return userclass;

    for (int i = 0; i < retList.size(); i++)
    {
        tb_student uclass;
        uclass.id =             retList.at(i).at(0).toUInt();
        uclass.studentName =    retList.at(i).at(1);
        uclass.studentSex =     retList.at(i).at(2);
        uclass.studentAge =     retList.at(i).at(3);
        uclass.remark = retList.at(i).at(4);

        userclass.append(uclass);
    }

    return userclass;
}

bool JHSystemSqliteAccess::removeStudentInClass(int id)
{
    QString execStr = QString("delete from student_tb where id='%1';")
                .arg(id);

    return write(execStr);
}


bool JHSystemSqliteAccess::checkTable(QString tableName)
{
    QList<QStringList> retList;
    /* 检查表是否存在 */
    QString checkStr = QString("select * from %1;").arg(tableName);
    qint32 ret = read(checkStr, retList);
    if (!ret)
        return false;
    else
        return true;
}
