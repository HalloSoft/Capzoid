#include "controlwidget.h"
#include "ui_controlwidget.h"

const QString ControlWidget::cConnected = tr("Connected");
const QString ControlWidget::cDisconnected = tr("Disconnected");

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContolWidget)
{
    ui->setupUi(this);

    bool isConnected = false; Q_UNUSED(isConnected);
    //isConnected = connect(ui->buttonConnect, SIGNAL(clicked(bool)), this, SIGNAL(captureImage()));            Q_ASSERT(isConnected);
    //isConnected = connect(ui->buttonContiniousMode, SIGNAL(clicked()), this, SLOT(toggleContiniousMode())); Q_ASSERT(isConnected);
    isConnected = connect(ui->buttonConnect, SIGNAL(clicked()), this, SLOT(startMonitoring()));             Q_ASSERT(isConnected);
    isConnected = connect(&shootTimer, SIGNAL(timeout()), this, SIGNAL(captureImage()));                    Q_ASSERT(isConnected);

    // Defaults
    int index = ui->comboBoxRefreshRate->findText("0.3", static_cast<Qt::MatchFlags>( Qt::MatchExactly));
    ui->comboBoxRefreshRate->setCurrentIndex(index);
}

ControlWidget::~ControlWidget()
{
    delete ui;
}

void ControlWidget::setImageCaptureEnabled(bool enable)
{
    //ui->buttonShoot->setEnabled(enable);
}

void ControlWidget::setConnectionStatus(bool connected)
{
    if(connected)
        ui->labelConnectionStatus->setText(cConnected);
    else
        ui->labelConnectionStatus->setText(cDisconnected);
}

void ControlWidget::startMonitoring()
{
    if(isCameraConnected())
    {
        int refreshrate = 200; // ms
        refreshrate = ui->comboBoxRefreshRate->currentText().toFloat() * 1000.0;
        shootTimer.start(refreshrate);
    }
}

void ControlWidget::toggleContiniousMode()
{
    if(!isContiniousModeActive)
    {
        int milliseconds = 1000;
        bool isConversionOk = false;
        //double secondsFromUi = ui->lineEditTime->text().toFloat(&isConversionOk);
        if(isConversionOk)
        //    milliseconds = static_cast<int>(secondsFromUi * 1000);

        shootTimer.start(milliseconds);
    }
    else
        shootTimer.stop();

    isContiniousModeActive = !isContiniousModeActive;

}

bool ControlWidget::isCameraConnected()
{
    const QString uiConnectionText = ui->labelConnectionStatus->text();
    return (uiConnectionText == cConnected);
}
