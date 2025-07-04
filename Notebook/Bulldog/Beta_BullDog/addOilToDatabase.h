#ifndef ADDOILTODATABASE_H
#define ADDOILTODATABASE_H
#pragma once

#include <QString>
#include <QByteArray>
#include <QDate>

class AddOilToDatabase
{
public:
    static bool addOil(const QString& name, const QString& type, const QString& basin, const QString& formation,
                       const QString& location, const QDate& collectionDate, const QByteArray& chromatogramImage,
                       const QString& chemicalComposition, const QString& viscosity, const QString& density,
                       bool biodegraded, const QString& origin);  // Função para adicionar o óleo no banco de dados
};

#endif // ADDOILTODATABASE_H
