#include "mainwindow.h"
#include "oilibrarywidget.h"
#include "addoilwidget.h"
#include "compareoilswidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    oilLibraryWidget(new OilLibraryWidget(this)),
    addOilWidget(new AddOilWidget(this)),
    compareOilsWidget(new CompareOilsWidget(this))
{
    mainMenuWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(mainMenuWidget);

    QPushButton* btnLib = new QPushButton(tr("Biblioteca de Óleos"), this);
    QPushButton* btnAdd = new QPushButton(tr("Adicionar Novo Óleo"), this);
    QPushButton* btnCmp = new QPushButton(tr("Comparar Óleos"), this);

    layout->addWidget(btnLib);
    layout->addWidget(btnAdd);
    layout->addWidget(btnCmp);

    setCentralWidget(mainMenuWidget);

    connect(btnLib, &QPushButton::clicked, this, &MainWindow::showOilLibrary);
    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::showAddOil);
    connect(btnCmp, &QPushButton::clicked, this, &MainWindow::showCompareOils);

    // Voltar de cada widget para o menu principal
    connect(oilLibraryWidget, &OilLibraryWidget::backToMenu, this, &MainWindow::showMainMenu);
    connect(addOilWidget, &AddOilWidget::backToMenu, this, &MainWindow::showMainMenu);
    connect(compareOilsWidget, &CompareOilsWidget::backToMenu, this, &MainWindow::showMainMenu);
}

void MainWindow::setCentralTo(QWidget* widget)
{
    setCentralWidget(widget);
}

void MainWindow::showOilLibrary()
{
    setCentralTo(oilLibraryWidget);
}

void MainWindow::showAddOil()
{
    setCentralTo(addOilWidget);
}

void MainWindow::showCompareOils()
{
    setCentralTo(compareOilsWidget);
}

void MainWindow::showMainMenu()
{
    setCentralTo(mainMenuWidget);
}
