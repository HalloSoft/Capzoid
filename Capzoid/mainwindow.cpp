#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "webcaminput.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WebCamInput i;
    i.openCamera();


}

MainWindow::~MainWindow()
{
    delete ui;
}
