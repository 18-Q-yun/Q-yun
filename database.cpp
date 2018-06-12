#include "database.h"
int currentLevel=1;
QString currentDirName;
 dataBase::dataBase( QSqlDatabase dataBase)
{
  dataBase=QSqlDatabase::addDatabase("QMYSQL");
  m_database=dataBase;
}

void dataBase::initDataBase()
{
    m_database.setHostName("localhost");
    m_database.setUserName("root");
    m_database.setPassword("");
    m_database.setDatabaseName("userYun");
    bool ok=m_database.open();
    if(ok)
    {
      qDebug()<<"open database success";
    }
    else
    {
      qDebug()<<"error open database";
    }
}

void dataBase::createUserInfoTable()
{
    initDataBase();
    QSqlQuery query(m_database);
    auto success=query.exec("create table userInfo(account varchar(20) primary key,password varchar(20))");
    if(!success){
       qDebug()<<"Fail to create  userInfo";
       qDebug()<<query.lastError().text();

    }
}

void dataBase::insertUserInfo(QString account,QString password)
{
    QSqlQuery query(m_database);

    query.prepare("insert into userInfo values(?,?)");
    query.addBindValue(account);
    query.addBindValue(password);
    auto success=query.exec();
    if(!success){
       qDebug()<<"Fail to insert in userInfo";

    }
}

QString dataBase::selectUserInfo(QString account)
{
   QSqlQuery query(m_database);
   query.prepare("select * from userInfo where account=?");
   query.addBindValue(account);
   query.exec();
   query.next();
   qDebug()<<query.value(1).toString();
   return query.value(1).toString();
}

void dataBase::updateUserInfo(QString account,QString password)
{
    QSqlQuery query(m_database);
     query.exec("update userInfo set password=? where account=?");
     query.addBindValue(password);
     query.addBindValue(account);
}

void dataBase::deleteUserInfo(QString account)
{
    QSqlQuery query(m_database);
     query.prepare("delete from userInfo where account=?");
     query.addBindValue(account);
     query.exec();
}

QString dataBase::createLevelDirTable(int level,QString account)
{
     QSqlQuery query(m_database);

      QString tablename;
//      query.prepare("create table ?(filename varchar(20) primary key,lastfilename varchar(20))");

       switch (level) {
       case 1:

            tablename=account+"firstDir";
           break;
       case 2:

            tablename=account+"secondDir";
          break;
       case 3:

           tablename=account+"thirdDir";
          break;
       case 4:

           tablename=account+"fourthDir";
          break;
       case 5:

            tablename=account+"fifthDir";
          break;
       case 6:
            tablename=account+"sixDir";
          break;
       case 7:

            tablename=account+"seventhDir";
          break;
       case 8:

            tablename=account+"eighthDir";
          break;
       default:
           break;
       }
         auto success=query.exec(QString("create table %1(filename varchar(20) primary key,lastfilename varchar(20))").arg(tablename));
        if(!success){
           qDebug()<<"Fail to create  "<<tablename;
           qDebug()<<query.lastError().text();

        }
        return tablename;

}

QSqlQuery dataBase::selectLevelDir(QString levelDirTableName)
{
    QSqlQuery query(m_database);
    query.prepare("select * from ?");
    query.addBindValue(levelDirTableName);
    query.exec();
    return query;
}

void dataBase::insertLevelDir(QString levelDirTableName,QString filename ,QString lastfilename)
{
      QSqlQuery query(m_database);
      auto success=query.exec(QString("insert into  %1 values('%2','%3')").arg(levelDirTableName).arg(filename).arg(lastfilename));
    if(!success){
       qDebug()<<"Fail to insert in "<<levelDirTableName;
       qDebug()<<query.lastError().text();


    }
}

void dataBase::updateLevelDir(QString levelDirTableName,int id,QString filename)
{
    QSqlQuery query(m_database);
    query.prepare("update ? set filename=? where id=?");
    query.addBindValue(levelDirTableName );
    query.addBindValue(filename);
    query.addBindValue(id );

}

void dataBase::deleteLevelDir(QString levelDirTableName,int id)
{
    QSqlQuery query(m_database);
     query.exec("delete from ? where id=?");
     query.addBindValue(levelDirTableName);
     query.addBindValue(id);
}
