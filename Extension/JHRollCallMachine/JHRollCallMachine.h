#ifndef JHROLLCALLMACHINE_H
#define JHROLLCALLMACHINE_H

#include <QQuickItem>

class JHRollCallMachine : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(JHRollCallMachine)

public:
    explicit JHRollCallMachine(QQuickItem *parent = nullptr);
    ~JHRollCallMachine() override;
};

#endif // JHROLLCALLMACHINE_H
