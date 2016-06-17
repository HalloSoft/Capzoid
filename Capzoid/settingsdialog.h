#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QStandardPaths>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

protected:
    void accept();

private slots:
    void browseImagePath();

private:
    void writeSettings();
    void readSettings();

    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
