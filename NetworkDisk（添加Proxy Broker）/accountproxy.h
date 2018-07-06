#ifndef ACCOUNTPROXY_H
#define ACCOUNTPROXY_H
#include "database.h"
#include "account.h"
#include "accountbroker.h"
#include <QString>
class AccountProxy
{
public:
    AccountProxy();
    void updatePassword(QString request);
    void verifyAccount(QString request);
    void updateRemainSpace(QString request);
    void applyAccount(QString request);

};

#endif // ACCOUNTPROXY_H
