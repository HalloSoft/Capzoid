#include "controlwidget.h"
#include "ui_controlwidget.h"

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContolWidget)
{
    ui->setupUi(this);

    QValidator *validator = new QDoubleValidator(0.0, 10000.0, 2, this);
    ui->lineEditTime->setValidator(validator);

    bool isConnected = false; Q_UNUSED(isConnected);
    isConnected = connect(ui->buttonShoot, SIGNAL(clicked(bool)), this, SIGNAL(captureImage()));            Q_ASSERT(isConnected);
    isConnected = connect(ui->buttonContiniousMode, SIGNAL(clicked()), this, SLOT(toggleContiniousMode())); Q_ASSERT(isConnected);
    isConnected = connect(&shootTimer, SIGNAL(timeout()), this, SIGNAL(captureImage()));                    Q_ASSERT(isConnected);
}

ControlWidget::~ControlWidget()
{
    delete ui;
}

void ControlWidget::setImageCaptureEnabled(bool enable)
{
    ui->buttonShoot->setEnabled(enable);
}

void ControlWidget::toggleContiniousMode()
{
    if(!isContiniousModeActive)
    {
        int milliseconds = 1000;
        bool isConversionOk = false;
        double secondsFromUi = ui->lineEditTime->text().toFloat(&isConversionOk);
        if(isConversionOk)
            milliseconds = static_cast<int>(secondsFromUi * 1000);

        shootTimer.start(milliseconds);
    }
    else
        shootTimer.stop();

    isContiniousModeActive = !isContiniousModeActive;

}
