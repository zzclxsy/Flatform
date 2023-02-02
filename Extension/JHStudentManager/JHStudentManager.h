#ifndef JHSTUDENTMANAGER_H
#define JHSTUDENTMANAGER_H

#include <QQuickItem>

class JHStudentManager : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(JHStudentManager)

public:
    explicit JHStudentManager(QQuickItem *parent = nullptr);
    ~JHStudentManager() override;
};

#endif // JHSTUDENTMANAGER_H
