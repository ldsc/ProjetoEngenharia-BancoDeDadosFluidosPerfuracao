#ifndef OILIBRARYWIDGET_H
#define OILIBRARYWIDGET_H
#pragma once

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>

class OilLibraryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OilLibraryWidget(QWidget *parent = nullptr);

private slots:
    void onBackClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onExportClicked();

private:
    void setupUI();       // Função para configurar a interface do usuário
    void loadOils();      // Função para carregar os óleos da base de dados

    QTableWidget* oilTable;   // Tabela onde os óleos serão exibidos
    QPushButton* btnEdit;     // Botão para editar óleo
    QPushButton* btnDelete;   // Botão para excluir óleo
    QPushButton* btnExport;   // Botão para exportar os óleos
    QPushButton* btnBack;     // Botão para voltar ao menu

signals:
    void backToMenu();  // Sinal para voltar ao menu principal
};

#endif // OILIBRARYWIDGET_H
