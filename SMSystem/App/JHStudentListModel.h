#ifndef JHSTUDENTLISTMODEL_H
#define JHSTUDENTLISTMODEL_H
#include "JHDataModel/JHListModel.h"
#include "JHDataModel/JHListViewModel.h"
#include <QObject>
#include <QJsonObject>
class JHSystemSqliteAccess;
class JHStudentListModel : public JHListViewModel
{
    Q_OBJECT
public:
    explicit JHStudentListModel(QObject *parent = nullptr);
    Q_INVOKABLE void initialize();
    Q_INVOKABLE void addStudent(QJsonObject studentInfo);
    Q_INVOKABLE void updataStudentInfo(int index,QString key,QString value);
    Q_INVOKABLE void deleteStudent(int index);
private:
    JHListModel *mp_list;
    JHSystemSqliteAccess *mp_sqldata;
    QString m_keyID;
    int m_maxID;
};

#endif // JHSTUDENTLISTMODEL_H
