#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

#include <QMainWindow>
#include <QTimer>
#include <qfiledialog.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <opencv2/aruco.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <qmessagebox.h>

using namespace cv;
using namespace std;

namespace Ui {
class boardGenerator;
}

class boardGenerator : public QMainWindow
{
    Q_OBJECT


public slots:
    int createBoard();
    int saveBoard();

public:
    explicit boardGenerator(QWidget *parent = 0);
    ~boardGenerator();

    QImage imdisplay;  //This will create QImage which is shown in Qt label
    QTimer* Timer;   // A timer is needed in GUI application



private:
    Ui::boardGenerator *ui;
    Mat boardImage;
};

#endif // BOARDGENERATOR_H
