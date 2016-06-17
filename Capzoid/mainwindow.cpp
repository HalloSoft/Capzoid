#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aboutbox.h"
#include "webcaminput.h"

#include "opencv2/opencv.hpp"

#include <QDebug>
#include <QDateTime>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    camera = new WebCamInput;

    ui->setupUi(this);

    bool isConnected = false; Q_UNUSED(isConnected);
    isConnected = connect(ui->controlWidget, SIGNAL(connectionRequested(int,bool)), this, SLOT(connectCamera(int,bool))); Q_ASSERT(isConnected);
    isConnected = connect(ui->controlWidget, SIGNAL(captureImage()), this, SLOT(displayPreview())); Q_ASSERT(isConnected);
    isConnected = connect(camera, SIGNAL(connectionStatusChanged(bool)), ui->controlWidget, SLOT(setConnectionStatus(bool))); Q_ASSERT(isConnected);


    isConnected = connect(ui->controlWidget, SIGNAL(triggered()), this, SLOT(saveImage())); Q_ASSERT(isConnected);
    //Menu
    isConnected = connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(openAboutBox())); Q_ASSERT(isConnected);

    //Test
    //camera->openCamera();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::displayPreview()
{
    camera->shoot();
    cv::Mat imageMat = camera->getImage();

    QImage image(imageMat.data, imageMat.cols, imageMat.rows, QImage::Format_RGB888);
    QPixmap p = QPixmap::fromImage(image);
    ui->label->setPixmap(p);

    //qDebug() << "Refresh:" << QTime::currentTime();
}

void MainWindow::connectCamera(int index, bool connect)
{
    if(connect)
        camera->openCamera(index);
    else
        camera->closeCamera();
}

void MainWindow::saveImage()
{
    const QString timeString = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    const QString fileName = QString("Capzoid-%1.jpg").arg(timeString);
    QFile file(fileName);

    bool success = false;
    if(file.open(QIODevice::WriteOnly))
    {
        cv::Mat imageMat = camera->getImage();

        QImage image(imageMat.data, imageMat.cols, imageMat.rows, QImage::Format_RGB888);
        QPixmap pixmap = QPixmap::fromImage(image);
        success = pixmap.save(&file, "JPG");
    }

    if(success)
        ui->statusBar->showMessage(tr("Saved as %1").arg(fileName));
    else
        ui->statusBar->showMessage(tr("Error saving file"));


    qDebug() << "save" << success ;
}

void MainWindow::openAboutBox()
{
    AboutBox aboutBox(this);
    aboutBox.exec();
}
