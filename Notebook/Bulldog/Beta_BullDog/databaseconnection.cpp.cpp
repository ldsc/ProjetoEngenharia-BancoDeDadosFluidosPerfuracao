#include "databaseconnection.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool DatabaseConnection::createDatabase()
{
    // Conectar ao banco de dados SQLite (o Qt criará o arquivo se ele não existir)
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("oils.db"); // Nome do arquivo do banco de dados

    if (!db.open()) {
        qDebug() << "Erro ao abrir o banco de dados:" << db.lastError().text();
        return false;
    }

    // Criar a tabela de óleos
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS oils ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "name TEXT NOT NULL, "
                              "type TEXT NOT NULL, "
                              "basin TEXT NOT NULL, "
                              "formation TEXT NOT NULL, "
                              "location TEXT NOT NULL, "
                              "collection_date DATE NOT NULL, "
                              "chromatogram_image BLOB, "
                              "chemical_composition TEXT, "
                              "viscosity TEXT, "
                              "density TEXT, "
                              "biodegraded BOOLEAN, "
                              "origin TEXT)");

    if (!success) {
        qDebug() << "Erro ao criar a tabela de óleos:" << query.lastError().text();
        return false;
    }

    return true;
}
