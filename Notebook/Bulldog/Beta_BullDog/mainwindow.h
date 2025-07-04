#pragma once

#include <QMainWindow>

class OilLibraryWidget;
class AddOilWidget;
class CompareOilsWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void showOilLibrary();
    void showAddOil();
    void showCompareOils();
    void showMainMenu();

private:
    OilLibraryWidget* oilLibraryWidget;
    AddOilWidget* addOilWidget;
    CompareOilsWidget* compareOilsWidget;

    QWidget* mainMenuWidget;
    void setCentralTo(QWidget* widget);
};
