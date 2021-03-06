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
    void connectCamera(int index, bool connect);
    void saveImage();

    // menu
    void openAboutBox();
    void openSettingsDialog();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void writeSettings();
    void readSettings();

    Ui::MainWindow *ui;

    WebCamInput *camera = 0;
};

#endif // MAINWINDOW_H
