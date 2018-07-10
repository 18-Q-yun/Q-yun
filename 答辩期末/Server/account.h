#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
class Account
{
public:
    Account();
    Account(QString userName,QString userPassword,QString remainSpace):
        _userName{userName},_userPassword{userPassword},_remainSpace{remainSpace}
    {}
private:
    QString _userName;
    QString _userPassword;
    QString _remainSpace;
};
#endif // ACCOUNT_H
