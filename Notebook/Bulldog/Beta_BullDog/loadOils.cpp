void loadOils()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("oils.db");

    if (!db.open()) {
        qDebug() << "Erro ao abrir o banco de dados!";
        return;
    }

    QSqlQuery query("SELECT * FROM oils");
    while (query.next()) {
        QString name = query.value("name").toString();
        QString type = query.value("type").toString();

        // Adicionar os dados à tabela de óleos
        int row = oilTable->rowCount();
        oilTable->insertRow(row);
        oilTable->setItem(row, 0, new QTableWidgetItem(name));
        oilTable->setItem(row, 1, new QTableWidgetItem(type));
    }
}
