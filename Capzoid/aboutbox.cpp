#include "aboutbox.h"
#include "ui_aboutbox.h"

#include "opencv2/opencv.hpp"

AboutBox::AboutBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutBox)
{
    ui->setupUi(this);


    QString appVersionString = QString("%1.%2.%3.%4").arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_REVISION).arg(VERSION_BUILD);
    ui->labelVersion->setText(QString("%1").arg(appVersionString));
    ui->labelQtVersion->setText(QString("%1").arg(QT_VERSION_STR));
    ui->labelOpenCvVersion->setText(QString("%1.%2").arg(CV_MAJOR_VERSION).arg(CV_MINOR_VERSION));
}

AboutBox::~AboutBox()
{
    delete ui;
}
