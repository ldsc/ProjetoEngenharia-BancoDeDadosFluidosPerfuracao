#include "oilibrarywidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

OilLibraryWidget::OilLibraryWidget(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
    loadOils();
}

void OilLibraryWidget::setupUI()
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    oilTable = new QTableWidget(this);
    oilTable->setColumnCount(3);
    oilTable->setHorizontalHeaderLabels({tr("Nome"), tr("Tipo"), tr("Ações")});

    mainLayout->addWidget(oilTable);

    QHBoxLayout* btnLayout = new QHBoxLayout;
    btnEdit = new QPushButton(tr("Editar"), this);
    btnDelete = new QPushButton(tr("Excluir"), this);
    btnExport = new QPushButton(tr("Exportar"), this);
    btnBack = new QPushButton(tr("Voltar"), this);

    btnLayout->addWidget(btnEdit);
    btnLayout->addWidget(btnDelete);
    btnLayout->addWidget(btnExport);
    btnLayout->addWidget(btnBack);

    mainLayout->addLayout(btnLayout);

    connect(btnBack, &QPushButton::clicked, this, &OilLibraryWidget::onBackClicked);
    connect(btnEdit, &QPushButton::clicked, this, &OilLibraryWidget::onEditClicked);
    connect(btnDelete, &QPushButton::clicked, this, &OilLibraryWidget::onDeleteClicked);
    connect(btnExport, &QPushButton::clicked, this, &OilLibraryWidget::onExportClicked);
}

void OilLibraryWidget::loadOils()
{
    oilTable->setRowCount(2);
    oilTable->setItem(0, 0, new QTableWidgetItem("Óleo 1"));
    oilTable->setItem(0, 1, new QTableWidgetItem("Tipo A"));
    oilTable->setItem(1, 0, new QTableWidgetItem("Óleo 2"));
    oilTable->setItem(1, 1, new QTableWidgetItem("Tipo B"));
}

void OilLibraryWidget::onBackClicked()
{
    emit backToMenu();
}

void OilLibraryWidget::onEditClicked() { /* implementar */ }
void OilLibraryWidget::onDeleteClicked() { /* implementar */ }
void OilLibraryWidget::onExportClicked() { /* implementar */ }

#include "oilibrarywidget.h"
#include "databaseconnection.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>

void OilLibraryWidget::loadOils()
{
    // Conectar ao banco de dados
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("oils.db");

    if (!db.open()) {
        qDebug() << "Erro ao abrir o banco de dados!";
        return;
    }

    // Preparar consulta para carregar óleos
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

