#pragma once

#include <QWidget>
#include <QPushButton>

class CompareOilsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CompareOilsWidget(QWidget* parent = nullptr);

signals:
    void backToMenu();

private slots:
    void onBackClicked();
    void onCompareClicked();

private:
    QPushButton* btnCompare;
    QPushButton* btnBack;

    void setupUI();
};
