#pragma once

#include <QWidget>
#include <QPushButton>

class AddOilWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddOilWidget(QWidget* parent = nullptr);

signals:
    void backToMenu();

private slots:
    void onBackClicked();
    void onSaveClicked();
    void onQuantifyAutoClicked();
    void onUploadClicked();

private:
    QPushButton* btnSave;
    QPushButton* btnBack;
    QPushButton* btnQuantifyAuto;
    QPushButton* btnUpload;

    void setupUI();
};
