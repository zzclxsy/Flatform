#ifndef JHSMAPI_H
#define JHSMAPI_H

#include <QObject>
#include "JHAccountManager.h"
#include "JHStudentListModel.h"
class JHSMApi:public QObject
{
    Q_OBJECT
    Q_PROPERTY(JHAccountManager* AccountManager READ getAccountManager)
    Q_PROPERTY(JHStudentListModel* studentModel READ getStudentModelManager NOTIFY studentModelManagerChanged)

public:
    JHSMApi();
    void initialize();
    JHAccountManager *getAccountManager();
    JHStudentListModel *getStudentModelManager();
private:
    JHAccountManager *mp_accountManager;
    JHStudentListModel *mp_studentListModel;
signals:
    void studentModelManagerChanged();
};

#endif // JHSMAPI_H
