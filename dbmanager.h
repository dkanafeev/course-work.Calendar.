#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include <QDebug>
#include <QDate>
#include <QMessageBox>

#include <iostream>

/**
 * @class DBManager
 * @brief The DBManager class
 */
class DBManager
{
private:
    QSqlDatabase db;
    static DBManager* instance;

public:
    enum QUERY_NAMES
    {
        QUERY_SELECT_EMAILS_FROM_PERSONAL_EMAIL,
        QUERY_SELECT_FROM_DATA_BY_BIRTH_MONTH,
        QUERY_SELECT_FROM_DATA,
        QUERY_SELECT_NAMES_FROM_CONGRATULATIONS_TEXT
    };
    DBManager();
    ~DBManager();

    static DBManager*   getInstance();

    /// получение моделей по модификатору из перечисления
    QSqlQueryModel* selectQuery(int mode);

    /// ???
    //QSqlTableModel* getCurrentModel();

    /// получение самих тектов для
    QString getTextFor(int idText);

    /// запись данных о новом собитии (д/р)
    bool addRecordToData(QString lastName, QString firstName, QString patronimicName, QString email, QDate date, QTime hoursReminder, QDate userReminderDate, QTime userReminderTime);

    /// Добавить почту в таблицу почт пользователя
    void addRecordToPersonalEmail( QString email );
};

#endif // DBMANAGER_H
