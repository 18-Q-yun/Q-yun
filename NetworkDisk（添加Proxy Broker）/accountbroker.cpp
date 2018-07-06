#include "accountbroker.h"


bool AccountBroker::verifyAccount(QString userName,QString userPassword)
{
    QString rightUserPassword=selectUserInfo(userName);
    if(rightUserPassword==userPassword){
        return true;
    }else{
        return false;
    }
}

void AccountBroker::updateRemainSpace(QString userName,int remainSpace)
{
       updateRemainSpace(userName,remainSpace);
}
void AccountBroker::updatePassword(QString userName,QString userPassword)
{
    updatePassword(userName,userPassword);
}

void AccountBroker::applyAccount(QString userName, QString userPassword)
{
    insertUserInfo(userName,userPassword);
}
