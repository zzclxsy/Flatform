#ifndef OBJECTMGR_H
#define OBJECTMGR_H
#include "./Interface/IManager.h"
#include "./Interface/IFactory.h"
#include <QObject>
#include <QJsonObject>
#include <map>
#include <QString>
#include <QHash>
class ObjectMgr
        :public QObject,
         public IManager
{
    Q_OBJECT

public:
    Q_INVOKABLE int registerUIElement(const QString& typeCode, const QJsonObject& info);
    Q_INVOKABLE QJsonObject getElementInfo(const QString& typeCode);
    Q_INVOKABLE QString getElementURL(const QString& typeCode);

private:
    QHash<QString, QJsonObject> m_elements;

public:
    ObjectMgr();

    virtual void addFactory(const std::string& tc, IFactory * f)
    {
        m_factorys.insert(std::make_pair(tc, f));
    }

    virtual IFactory * removeFactory(const std::string& tc)
    {
        IFactory * result = nullptr;
        auto it = m_factorys.find(tc);
        if (it != m_factorys.end()){
            result = it->second;
            m_factorys.erase(it);
        }
        return result;
    }

    virtual IObject * create(const std::string& tc);

    virtual IObject * getService(const std::string& tc);
    virtual void removeService(const std::string& tc);

    template <typename T>
    T * getXService(const std::string& tc)
    {
        return dynamic_cast<T *>(this->getService(tc));
    }

protected:
    std::map<std::string, IFactory *> m_factorys;
    std::map<std::string, IObject *> m_services;
};

#endif // OBJECTMGR_H
