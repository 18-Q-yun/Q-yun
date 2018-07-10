#include "database.h"
#include <QList>

int currentLevel=1;
QString currentDirName;
 dataBase::dataBase()
{

     if(QSqlDatabase::contains("qt_sql_default_connection"))
        m_database = QSqlDatabase::database("qt_sql_default_connection");
     else
        m_database = QSqlDatabase::addDatabase("QMYSQL");
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
     auto success=query.exec("create table userInfo(account  varchar(20)  primary key,password varchar(20),remainSpace int)");
    if(!success){
       qDebug()<<"Fail to create  userInfo";
       qDebug()<<query.lastError().text();

    }
}

void dataBase::insertUserInfo(QString account,QString password)
{
    QSqlQuery query(m_database);
     auto success=query.exec(QString("insert into  userInfo values('%2','%3','%4')").arg(account).arg(password).arg(1));
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

void dataBase::updatePassword(QString account,QString password)
{
    QSqlQuery query(m_database);
     query.exec("update userInfo set password=?  where account=?");
     query.addBindValue(password);
     query.addBindValue(account);
     
}
void dataBase::updateRemainSpace(QString account,QString remainSpace)
{
    QSqlQuery query(m_database);
     query.exec("update userInfo set account=?  where remainSpace=?");
     query.addBindValue(account);
     query.addBindValue(remainSpace);
     
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
         auto success=query.exec(QString("create table %1(filename varchar(100) primary key,lastfilename varchar(100),fileType varchar(20))").arg(tablename));
        if(!success){
           qDebug()<<"Fail to create  "<<tablename;
           qDebug()<<query.lastError().text();

        }
        return tablename;

}

QList<QString> dataBase::selectLevelDir(QString levelDirTableName,QString lastfilename)
{
    QSqlQuery query(m_database);
   auto success=query.exec(QString("select * from %1 where lastfilename='%2'").arg(levelDirTableName).arg(lastfilename));
    if(success){
        qDebug()<<"select "<<levelDirTableName<<"sucees";
    }else{
           qDebug()<<"select "<<levelDirTableName<<"fail";
    }

    QList<QString>  filenames;

    while(query.next()){

           if(query.value(2).toString()=="D"){
           filenames<<query.value(0).toString()+":D";

           }else{
                filenames<<query.value(0).toString();
           }

    }
    return filenames;
}

void dataBase::insertLevelDir(int level,QString account,QString filename ,QString lastfilename,QString fileType)
{
      QSqlQuery query(m_database);
      qDebug()<<level<<" "<<account<<" "<<filename<<" "<<lastfilename<<" "<<fileType;
      QString levelDirTableName=createLevelDirTable(level,account);
      auto success=query.exec(QString("insert into  %1 values('%2','%3','%4')").arg(levelDirTableName).arg(filename).arg(lastfilename).arg(fileType));
    if(!success){
       qDebug()<<"Fail to insert in "<<levelDirTableName;
       qDebug()<<query.lastError().text();
    }
}

void dataBase::updateLevelDir(QString levelDirTableName,QString lastfilename,QString filename)
{
    QSqlQuery query(m_database);
    query.prepare("update ? set filename=? where lastfilename=?");
    query.addBindValue(levelDirTableName );
    query.addBindValue(filename);
    query.addBindValue(lastfilename);

}

void dataBase::deleteLevelDir(QString levelDirTableName,QString filename,QString lastfilename)
{
    QSqlQuery query(m_database);
     query.exec("delete from ? where filename=? and lastfilename=?");
     query.addBindValue(levelDirTableName );
     query.addBindValue(filename);
     query.addBindValue(lastfilename);
}
