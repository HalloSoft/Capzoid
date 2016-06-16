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
        Mat tempMatrix;

        capture >> tempMatrix;

        //resize(tempMatrix, tempMatrix, Size(), zoomFactor, zoomFactor);

        //cvtColor(tempMatrix, tempMatrix,CV_BGR2RGB);
//        transpose(tempMatrix, tempMatrix);
//        flip(tempMatrix, tempMatrix, 1);
//        flip(tempMatrix, tempMatrix, 0);


        // make a copy to pass away
        matrix = tempMatrix.clone();
    }
    else
    {
        qDebug() << "Capture cannot be opened";
        Mat tempMatrix(200, 200, CV_8UC3);
        matrix = tempMatrix.clone();
    }

    emit shootingFinished();
}

void WebCamInput::openCamera(int index)
{
    camIndex = index;

    try
    {
        capture.open(camIndex);

        if(capture.isOpened())
        {
            qDebug() << "CAM: Width of the frames:" << capture.get(CV_CAP_PROP_FRAME_WIDTH);
            qDebug() << "CAM: Height of the frames:" << capture.get(CV_CAP_PROP_FRAME_HEIGHT);
            qDebug() << "CAM: \topen\tindex" << camIndex;
        }
    }
    catch(Exception &exception)
    {
        qDebug() << "\nMessage:" << QString::fromStdString(exception.msg) << endl;
    }
}

void WebCamInput::closeCamera()
{
    // this device is closed by the destructor
    capture.release();
    qDebug() << "CAM: \tclosed";
}
