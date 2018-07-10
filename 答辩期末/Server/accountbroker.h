#ifndef ACCOUNTBROKER_H
#define ACCOUNTBROKER_H
#include "database.h"

class AccountBroker:public dataBase
{
public:
    AccountBroker(){}
    bool verifyAccount(QString userName,QString userPassword);
    void updatePassword(QString userName,QString userPassword);
    void updateRemainSpace(QString userName,int remainSpace);
    void applyAccount(QString userName,QString userPassword);
};

#endif // ACCOUNTBROKER_H
