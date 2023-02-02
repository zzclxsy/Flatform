#include "JHStudentListModel.h"
#include "JHSqlite/JHDatabaseModule.h"
#include <QDebug>
#include <Framework/Framework.h>
#include "AppData/JHAppData.h"
JHStudentListModel::JHStudentListModel(QObject *parent)
{
    m_keyID = "student";
    m_maxID = 0;
    mp_list = new JHListModel;
    this->setDataSource(mp_list);

    QJsonObject roleMap;
    roleMap["A"]= "index";
    roleMap["B"]= "name";
    roleMap["C"]="chinese";
    roleMap["D"]= "mathematics";
    roleMap["E"]= "english";
    roleMap["F"]= "score";
    roleMap["G"]= "remark";

    roleMap["H"]= "sex";
    roleMap["i"]= "age";
    this->setRoleMap(roleMap);

    mp_sqldata =Framework::getApp()->getObjectManager()->getXService<JHSystemSqliteAccessServer>("JHSystemSqliteAccessServer")->systemSqlApi();
}

void JHStudentListModel::initialize()
{
    QString classID= Framework::getApp()->getAppData()->getShareData("classID");
    QVector<tb_student> studentData = mp_sqldata->getStudentInClass(classID.toInt());

    for (auto it = studentData.begin(); it != studentData.end(); it++)
    {
        QJsonObject data;
        data["name"] = it->studentName;
        data["sex"] = it->studentSex.toInt();
        data["remark"]= it->remark;
        data["chinese"]=-1;
        data["mathematics"]= -1;
        data["english"]= -1;
        data["score"]= 0;


        data["ID"] = it->id;

        QString key = QString("%1_%2").arg(m_keyID).arg(mp_list->count());
        mp_list->append(key,data);

        if (m_maxID < it->id){
            m_maxID = it->id;
        }
    }

}

void JHStudentListModel::addStudent(QJsonObject studentInfo)
{
    QString key = QString("%1_%2").arg(m_keyID).arg(mp_list->count());
    QString classID= Framework::getApp()->getAppData()->getShareData("classID");
    m_maxID++;

    tb_student info;
    info.id = m_maxID;
    info.studentName = studentInfo["name"].toString();
    info.studentSex = studentInfo["sex"].toString();
    info.remark = studentInfo["remark"].toString();
    info.classIndex = classID.toInt();

    studentInfo["ID"] = m_maxID;
    mp_list->append(key,studentInfo,true);

//    mp_sqldata->insertStudentToClass(info);
}

void JHStudentListModel::updataStudentInfo(int index, QString key, QString value)
{
    QJsonObject data = mp_list->nodeAt(index)->getData();
    int id = data["ID"].toInt();
    data[key] = value;

    mp_list->update(mp_list->nodeAt(index)->getNodeId(),data,true);

    tb_student info;
    info.id = id;
    info.studentName = data["name"].toString();
    info.studentSex = data["sex"].toString();
    info.remark = data["remark"].toString();
//    mp_sqldata->updataStudentToClass(info);

}

void JHStudentListModel::deleteStudent(int index)
{
    mp_list->remove(mp_list->nodeAt(index)->getNodeId(),true);
}
