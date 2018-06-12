#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QString>
#include <QObject>
class dataBase: public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE  dataBase(QSqlDatabase dataBase);
    Q_INVOKABLE void initDataBase(void);
    Q_INVOKABLE void createUserInfoTable();
    Q_INVOKABLE void insertUserInfo(QString account, QString password);
    Q_INVOKABLE QString selectUserInfo(QString account);
    Q_INVOKABLE void updateUserInfo(QString account,QString password);
    Q_INVOKABLE void deleteUserInfo(QString account);
    Q_INVOKABLE QString createLevelDirTable(int level, QString account);
    Q_INVOKABLE QSqlQuery selectLevelDir(QString levelDirTableName);
    Q_INVOKABLE void insertLevelDir(QString levelDirTableName,QString filename, QString lastfilename);
   Q_INVOKABLE void  updateLevelDir(QString levelDirTableName,int id,QString filename);
    Q_INVOKABLE void deleteLevelDir(QString levelDirTableName, int id);
private:
    QSqlDatabase m_database;
};

#endif // DATABASE_H
