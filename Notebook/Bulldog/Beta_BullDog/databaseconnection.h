#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#pragma once

#include <QString>
#include <QByteArray>
#include <QDate>

class DatabaseConnection
{
public:
    static bool createDatabase();  // Função para criar o banco de dados e a tabela
};

#endif // DATABASECONNECTION_H
