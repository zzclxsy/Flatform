#ifndef JHSYSTEMSQLITEACCESS_H
#define JHSYSTEMSQLITEACCESS_H

#include "JHBaseSqliteAccess.h"

typedef struct{
    int id;
    QString userName;
    QString password;
} tb_user;

typedef struct{
    int id;
    QString studentGrade;
    QString studentClass;
    int userIndex;
} tb_class;
Q_DECLARE_METATYPE(tb_class)

typedef struct{
    int id;
    QString studentName;
    QString studentSex;
    QString studentAge;
    QString remark;
    int classIndex;
} tb_student;

typedef struct{
    int id;
    QString chinese;
    QString mathematics;
    QString english;
    QString physics;
    QString chemistry;
    QString biology;
    QString geography;
    QString history;
    QString politics;
    int studentIndex;
    int classIndex;
} tb_score;
class JHSystemSqliteAccess : public JHBaseSqliteAccess
{
public:
    JHSystemSqliteAccess(QString dbName);

    //tb_user
    bool    insertUserToTable(tb_user user);
    bool    removeUserInTable(QString userName);
    bool    updataUserInTable(tb_user user);
    tb_user findUserInTable(QString userName);

    //tb_class
    bool    insertClassToUser(tb_class userClass);
    bool    removeClassInUser(tb_class userClass);
    QVector<tb_class> findClassInUser(tb_user user);

    //tb_student //学生不能同名
    bool    insertStudentToClass(tb_student student);
    bool    updataStudentToClass(tb_student student);
    QVector<tb_student> getStudentInClass(int classID);

private:
    bool checkTable(QString tableName);
};

#endif // JHSYSTEMSQLITEACCESS_H
