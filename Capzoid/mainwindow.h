#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class WebCamInput;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void displayPreview();

    // menu
    void openAboutBox();

private:
    Ui::MainWindow *ui;

    WebCamInput *camera = 0;
};

#endif // MAINWINDOW_H
