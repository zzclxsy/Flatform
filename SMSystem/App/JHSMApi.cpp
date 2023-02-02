#include "JHSMApi.h"
#include <QDebug>

JHSMApi::JHSMApi()
{
    mp_studentListModel = nullptr;
}


void JHSMApi::initialize()
{
    mp_accountManager = new JHAccountManager;
    mp_studentListModel = new JHStudentListModel();
}

JHAccountManager *JHSMApi::getAccountManager()
{
    return mp_accountManager;
}

JHStudentListModel *JHSMApi::getStudentModelManager()
{
    return mp_studentListModel;
}
