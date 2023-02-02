#include "ObjectMgr.h"
#include <QDebug>
ObjectMgr::ObjectMgr()
{

}

IObject * ObjectMgr::create(const std::string &tc)
{
    auto it = m_factorys.find(tc);
    if (it != m_factorys.end()){
        IObject * p = it->second->create();
        p->setManager(this);

        if (!p->initialize()){
            qWarning()<<QString(tc.c_str())+" initialize fail";
            delete p;
            p = nullptr;
        }
        return p;
    }
    return nullptr;
}

IObject * ObjectMgr::getService(const std::string &tc)
{
    auto it1 = m_services.find(tc);
    if (it1 != m_services.end()){
        return it1->second;
    }

    auto it2 = m_factorys.find(tc);
    if (it2 != m_factorys.end()){
        IObject * p = it2->second->create();
        p->setManager(this);
        if (!p->initialize()){
            qWarning()<<QString(tc.c_str())+" initialize fail";
            delete p;
            return nullptr;
        }
        m_services.insert(std::make_pair(tc, p));
        return p;
    }
    return nullptr;
}

void ObjectMgr::removeService(const std::string &tc)
{
    auto it = m_services.find(tc);
    if (it != m_services.end()){
        it->second->terminal();
        delete it->second;
        m_services.erase(it);
    }
}




int ObjectMgr::registerUIElement(const QString &typeCode, const QJsonObject &info)
{
    if (!m_elements.contains(typeCode)){
        m_elements.insert(typeCode, info);
        return m_elements.count();
    }
    return -1;
}

QJsonObject ObjectMgr::getElementInfo(const QString &typeCode)
{
    return m_elements.value(typeCode);
}

QString ObjectMgr::getElementURL(const QString &typeCode)
{
    return m_elements.value(typeCode).value(typeCode).toString();
}

