#include "dbmanager.h"


DBManager* DBManager::instance = NULL;

DBManager::DBManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../course-work.Calendar/DB.db");
}

DBManager* DBManager::getInstance()
{
    if (instance == NULL)
        instance = new DBManager();
    return instance;
}

QSqlQueryModel* DBManager::selectQuery(int mode)
{
    db.open();

    QSqlQueryModel* model = new QSqlQueryModel();

    switch (mode)
    {
    case QUERY_SELECT_FROM_DATA_BY_BIRTH_MONTH:
    {
        QDate data = QDate::currentDate();
        model->setQuery("SELECT lastName FROM Data WHERE birthMonth = " + QString::number(data.month()));
        break;
    }
    case QUERY_SELECT_FROM_DATA:
    {
        model->setQuery("SELECT lastName FROM Data ");
        break;
    }
    case QUERY_SELECT_EMAILS_FROM_PERSONAL_EMAIL:
    {
        model->setQuery("SELECT email FROM PersonalEmail");
        break;
    }
    case QUERY_SELECT_NAMES_FROM_CONGRATULATIONS_TEXT:
    {
        model->setQuery("SELECT idCongratulationsText FROM CongratulationsText ");
        break;
    }
    default:
    {
        std::cout << "Error in DBManager::selectQuery: query not found! Check mode" << std::endl;
        break;
    }
    }

    db.close();

    return model;
}

bool DBManager::addRecordToData(QString lastName, QString firstName, QString patronimicName, QString email, QDate date, QTime hoursReminder, QDate userReminderDate, QTime userReminderTime)
{
    db.open();
    QSqlQuery query;
    query.prepare("INSERT INTO Data ( lastName, firstName, patronimicName, email, birthDay, birthMonth, BirthYear, timeSend, userReminderDate, userReminderTime)"
                  "VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ? )");
    query.addBindValue(lastName);
    query.addBindValue(firstName);
    query.addBindValue(patronimicName);
    query.addBindValue(email);
    query.addBindValue(date.day());
    query.addBindValue(date.month());
    query.addBindValue(date.year());
    query.addBindValue(hoursReminder);
    query.addBindValue(userReminderDate);
    query.addBindValue(userReminderTime);
    bool execBool = query.exec();
    db.close();
    return execBool;
}

void DBManager::addRecordToPersonalEmail( QString email)
{
    db.open();
    QSqlQueryModel* model = new QSqlQueryModel();
    const QString query = QString("INSERT INTO PersonalEmail (email) VALUES (\"" + email +"\")");
    model->setQuery(query);
    db.close();
}

QString DBManager::getTextFor(int idText)
{
    db.open();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT сongratulationsText FROM CongratulationsText "
                    "WHERE idCongratulationsText = " + QString::number(idText));
    db.close();
    return model->record(0).value(0).toString();
}

//QSqlTableModel* DBManager::getCurrentModel()
//{
//    db.open();
//    QSqlTableModel* model;

//    model = new QSqlTableModel(NULL,db);
//    model->setTable("Data");
//    model->setFilter(QString("birthMonth=%1").arg(month));
//    model->select();

//    db.close();
//    return model;
//}
