#include "addOilToDatabase.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool AddOilToDatabase::addOil(const QString& name, const QString& type, const QString& basin, const QString& formation,
                              const QString& location, const QDate& collectionDate, const QByteArray& chromatogramImage,
                              const QString& chemicalComposition, const QString& viscosity, const QString& density,
                              bool biodegraded, const QString& origin)
{
    // Conectar ao banco de dados
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("oils.db");

    if (!db.open()) {
        qDebug() << "Erro ao abrir o banco de dados!";
        return false;
    }

    // Preparar a consulta SQL para inserir os dados
    QSqlQuery query;
    query.prepare("INSERT INTO oils (name, type, basin, formation, location, collection_date, chromatogram_image, "
                  "chemical_composition, viscosity, density, biodegraded, origin) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    query.addBindValue(name);
    query.addBindValue(type);
    query.addBindValue(basin);
    query.addBindValue(formation);
    query.addBindValue(location);
    query.addBindValue(collectionDate);
    query.addBindValue(chromatogramImage);  // Para armazenar a imagem em formato binário
    query.addBindValue(chemicalComposition);
    query.addBindValue(viscosity);
    query.addBindValue(density);
    query.addBindValue(biodegraded);
    query.addBindValue(origin);

    // Executar a consulta
    if (!query.exec()) {
        qDebug() << "Erro ao inserir os dados:" << query.lastError().text();
        return false;
    }

    return true;
}
