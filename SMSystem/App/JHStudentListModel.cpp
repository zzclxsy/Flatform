#include "JHStudentListModel.h"
#include <QDebug>
#include <Framework/Framework.h>
#include "AppData/JHAppData.h"
#include <QtConcurrent>
#include <QThread>
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

    m_sqlData.clear();
    mb_handle = true;

    m_thread = QtConcurrent::run(this,&JHStudentListModel::handleSqlData);
}

JHStudentListModel::~JHStudentListModel()
{
    mb_handle = false;
    m_thread.waitForFinished();
}
//如果后续发现sql增删改查耗时严重可以将其放到线程里面进行操作
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
    QString key = QString("%1_%2").arg(m_keyID).arg(m_maxID);
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

    sSqlData sqldata;
    sqldata.data = info;
    sqldata.operate = 0;

    m_mutex.lock();
    m_sqlData.push_back(sqldata);
    m_mutex.unlock();
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

    sSqlData sqldata;
    sqldata.data = info;
    sqldata.operate = 1;
    m_mutex.lock();
    m_sqlData.push_back(sqldata);
    m_mutex.unlock();
}

void JHStudentListModel::deleteStudent(int index)
{
    int id =  mp_list->nodeAt(index)->toJsonObject().value("ID").toInt();
    mp_list->remove(mp_list->nodeAt(index)->getNodeId(),true);

    tb_student info;
    info.id = id;

    sSqlData sqldata;
    sqldata.data = info;
    sqldata.operate = 2;

    m_mutex.lock();
    m_sqlData.push_back(sqldata);
    m_mutex.unlock();
}

void JHStudentListModel::handleSqlData()
{
    while (mb_handle) {
        if (m_sqlData.isEmpty()){
            QThread::msleep(100);
            continue;
        }
        m_mutex.lock();
        sSqlData sqlData = m_sqlData.takeFirst();
        m_mutex.unlock();
        qDebug()<<"sqlData:"<<sqlData.data.remark<<sqlData.data.studentName<<m_sqlData.size();
        switch (sqlData.operate) {
        case 0://增加学生信息
            mp_sqldata->insertStudentToClass(sqlData.data);
            break;
        case 1://修改学生信息
            mp_sqldata->updataStudentToClass(sqlData.data);
            break;
        case 2://删除学生信息
            mp_sqldata->removeStudentInClass(sqlData.data.id);
            break;

        default:
            break;
        }
    }
}
