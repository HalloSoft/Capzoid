#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDesktopServices>
#include <QDir>
#include <QFileDialog>
#include <QSettings>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    bool isConnected = false; Q_UNUSED(isConnected);
    isConnected = connect(ui->buttonBrowseImagePath, SIGNAL(clicked()), this, SLOT(browseImagePath())); Q_ASSERT(isConnected);

    readSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::accept()
{
    writeSettings();
    QDialog::accept();
}

void SettingsDialog::browseImagePath()
{
    const QString imageDirName = QFileDialog::getExistingDirectory();
    if(!imageDirName.isEmpty())
        ui->lineEditImagePath->setText(imageDirName);
}

void SettingsDialog::writeSettings()
{
    QSettings settings(this);
    settings.beginGroup("savesettings");
    settings.setValue("ImagePath", ui->lineEditImagePath->text());
    settings.endGroup();
}

void SettingsDialog::readSettings()
{
    QSettings settings(this);
    settings.beginGroup("savesettings");
    ui->lineEditImagePath->setText(settings.value("ImagePath", QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).at(0)).toString());
    settings.endGroup();
}
