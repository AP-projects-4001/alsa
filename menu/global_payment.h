#ifndef GLOBAL_PAYMENT_H
#define GLOBAL_PAYMENT_H


class global_Payment
{
public:
    global_Payment();
protected:
    virtual void increas() = 0;
    virtual void set()= 0;
};

#endif // GLOBAL_PAYMENT_H
