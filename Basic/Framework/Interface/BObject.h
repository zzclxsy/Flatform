#ifndef BOBJECT_H
#define BOBJECT_H


#include "IManager.h"
#include "IObject.h"

//此处需要用IObject作为基类的原因：下面是假设没有IObject的情况
//BObject 里面用到了m_manager函数，IManager里面提前包含了BObject头文件，这会
//导致一个问题，初始化BObject类的时候，IManager是没有进行定义的，就会出现符号未定义等错误


//所以IObject是真正的基类，BObject是其派生出来方便查找其他服务的一个功能派生类
class BObject
        : public IObject
{
protected:
    IManager * m_manager;

public:
    BObject(): m_manager(nullptr){}
    virtual ~BObject(){}

    virtual void setManager(IManager * m){ m_manager = m; }

    template <typename T>
    T * getService(const std::string& tc)
    {
        IObject * p = m_manager->getService(tc);
        if (p){
            return dynamic_cast<T *>(p);
        }
        return nullptr;
    }
};


#endif // BOBJECT_H
