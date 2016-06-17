#include "webcaminput.h"


#include <QDebug>

WebCamInput::WebCamInput()
{
}

WebCamInput::~WebCamInput()
{
    closeCamera();
}

Mat WebCamInput::getImage()
{

    return matrix;

}

void WebCamInput::shoot()
{

    if(capture.isOpened())  // check if we succeeded in opening
    {
        // grab image and convert from BGR to RGB
        capture >> matrix;
        cvtColor(matrix, matrix, CV_BGR2RGB);

        //resize(tempMatrix, tempMatrix, Size(), zoomFactor, zoomFactor);

        if(orientation == fliped)
        {
            flip(matrix, matrix, 0);
            flip(matrix, matrix, 1);
        }

        if(orientation == clockwise)
        {
            transpose(matrix, matrix);
            flip(matrix, matrix, 1);
        }

        if(orientation == countClowise)
        {
            transpose(matrix, matrix);
            flip(matrix, matrix, 0);
        }
    }
    else
    {
        qDebug() << "Camera No" << camIndex << "is not opened";

        Mat tempMatrix(200, 200, CV_8UC3);
        matrix = tempMatrix.clone();
    }

    emit shootingFinished();
}

void WebCamInput::openCamera(int index, Orientation currentOrientation)
{
    camIndex = index;
    orientation = currentOrientation;

    bool openedSuccessfull = false;

    try
    {
        capture.open(camIndex);

        if(capture.isOpened())
        {
            openedSuccessfull = true;
            qDebug() << "CAM: Width of the frames:" << capture.get(CV_CAP_PROP_FRAME_WIDTH);
            qDebug() << "CAM: Height of the frames:" << capture.get(CV_CAP_PROP_FRAME_HEIGHT);
            qDebug() << "CAM: \topen\tindex" << camIndex;
        }
    }
    catch(Exception &exception)
    {
        qDebug() << "\nMessage:" << QString::fromStdString(exception.msg) << endl;
    }

    emit connectionStatusChanged(openedSuccessfull);
}

void WebCamInput::closeCamera()
{
    // this device is closed by the destructor
    capture.release();
    emit connectionStatusChanged(false);

    qDebug() << "CAM: \tclosed";
}
