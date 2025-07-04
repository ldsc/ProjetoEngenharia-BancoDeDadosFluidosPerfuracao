#include "addoilwidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

AddOilWidget::AddOilWidget(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

void AddOilWidget::setupUI()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel(tr("Adicionar Novo Óleo"), this));
    btnUpload = new QPushButton(tr("Upload Cromatograma"), this);
    btnQuantifyAuto = new QPushButton(tr("Quantificar Automaticamente"), this);
    btnSave = new QPushButton(tr("Salvar"), this);
    btnBack = new QPushButton(tr("Voltar"), this);

    layout->addWidget(btnUpload);
    layout->addWidget(btnQuantifyAuto);
    layout->addWidget(btnSave);
    layout->addWidget(btnBack);

    connect(btnBack, &QPushButton::clicked, this, &AddOilWidget::onBackClicked);
    connect(btnSave, &QPushButton::clicked, this, &AddOilWidget::onSaveClicked);
    connect(btnQuantifyAuto, &QPushButton::clicked, this, &AddOilWidget::onQuantifyAutoClicked);
    connect(btnUpload, &QPushButton::clicked, this, &AddOilWidget::onUploadClicked);
}

void AddOilWidget::onBackClicked()
{
    emit backToMenu();
}

void AddOilWidget::onSaveClicked() { /* implementar */ }
void AddOilWidget::onQuantifyAutoClicked() { /* implementar */ }
void AddOilWidget::onUploadClicked() { /* implementar */ }
