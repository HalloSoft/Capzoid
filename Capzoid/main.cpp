#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Scary HalloSoft");
    QCoreApplication::setOrganizationDomain("hallosoft.de");
    QCoreApplication::setApplicationName("Hallos Inspection Tool");

    // Version
    QString versionString = QString("%1.%2.%3.%4").arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_REVISION).arg(VERSION_BUILD);
    a.setApplicationVersion(versionString);

    qDebug() << "Capziod-Version" << versionString;

    MainWindow w;
    w.show();

    return a.exec();
}
