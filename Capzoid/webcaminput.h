#ifndef CAMINPUT_H
#define CAMINPUT_H

//#include "opencv/cv.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/videoio.hpp"

#include <QObject>

//#include "abstractinput.h"

using namespace cv;

/**
* This class connects the picture source with the programm
* it reprisents an input device
*/
class WebCamInput : public QObject/*, CapAbstractInput */
{
    Q_OBJECT

public:
    /** Constructor */
    WebCamInput();

    /** Destructor */
    ~WebCamInput();

    /**
     * Gets a new IplImage from source
     */
    Mat getImage();

    /**
     * shoot an image with camera device */
    void shoot();

    /** opens the cam */
    void openCamera(int index = 0);

    /** closes the cam */
    void closeCamera();

signals:
    void shootingFinished();

private:

    VideoCapture capture;
    Mat matrix;
    int camIndex;
};

#endif //CAMINPUT_H
