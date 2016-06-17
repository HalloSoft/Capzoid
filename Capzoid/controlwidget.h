#ifndef CONTOLWIDGET_H
#define CONTOLWIDGET_H

#include <QTimer>
#include <QWidget>

namespace Ui {
class ContolWidget;
}

class ControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWidget(QWidget *parent = 0);
    ~ControlWidget();

    void setImageCaptureEnabled(bool enable);

public slots:
    /** set the connection status */
    void setConnectionStatus(bool connected);

private slots:
    void connectCamera();
    void startMonitoring();
    void toggleContiniousMode();

signals:
    void connectionRequested(int index, bool connect = true);
    void captureImage();

private:
    bool isCameraConnected();

    Ui::ContolWidget *ui;

    static const QString cConnected;
    static const QString cDisconnected;

    bool   isContiniousModeActive = false;
    QTimer shootTimer;
};

#endif // CONTOLWIDGET_H
