#ifndef JHSTUDENTLISTMODEL_H
#define JHSTUDENTLISTMODEL_H
#include "JHDataModel/JHListModel.h"
#include "JHDataModel/JHListViewModel.h"
#include "JHSqlite/JHDatabaseModule.h"
#include <QObject>
#include <QJsonObject>
#include <QMutex>
#include <QFuture>
class JHSystemSqliteAccess;
class JHStudentListModel : public JHListViewModel
{
    Q_OBJECT
    typedef struct{
        tb_student data;
        char operate;
    }sSqlData;
public:
    explicit JHStudentListModel(QObject *parent = nullptr);
    ~JHStudentListModel();
    Q_INVOKABLE void initialize();
    Q_INVOKABLE void addStudent(QJsonObject studentInfo);
    Q_INVOKABLE void updataStudentInfo(int index,QString key,QString value);
    Q_INVOKABLE void deleteStudent(int index);

private:
    void handleSqlData();

private:
    JHListModel *mp_list;
    JHSystemSqliteAccess *mp_sqldata;
    QString m_keyID;
    int m_maxID;
    bool mb_handle;
    QVector<sSqlData> m_sqlData;
    QMutex m_mutex;
    QFuture<void> m_thread;
};

#endif // JHSTUDENTLISTMODEL_H
