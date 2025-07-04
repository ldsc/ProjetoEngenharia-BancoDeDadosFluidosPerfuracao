#include "compareoilswidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

CompareOilsWidget::CompareOilsWidget(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

void CompareOilsWidget::setupUI()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel(tr("Comparar Óleos"), this));
    btnCompare = new QPushButton(tr("Comparar"), this);
    btnBack = new QPushButton(tr("Voltar"), this);

    layout->addWidget(btnCompare);
    layout->addWidget(btnBack);

    connect(btnBack, &QPushButton::clicked, this, &CompareOilsWidget::onBackClicked);
    connect(btnCompare, &QPushButton::clicked, this, &CompareOilsWidget::onCompareClicked);
}

void CompareOilsWidget::onBackClicked()
{
    emit backToMenu();
}

void CompareOilsWidget::onCompareClicked() { /* implementar */ }
