#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "webcaminput.h"

#include "opencv2/opencv.hpp"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    camera = new WebCamInput;

    ui->setupUi(this);

    bool isConnected = false; Q_UNUSED(isConnected);
    isConnected = connect(ui->controlWidget, SIGNAL(captureImage()), this, SLOT(displayPreview())); Q_ASSERT(isConnected);

    //Test
    camera->openCamera();

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

    qDebug() << "Shot!";


}
