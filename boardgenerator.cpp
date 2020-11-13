#include "boardgenerator.h"
#include "ui_boardgenerator.h"

boardGenerator::boardGenerator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boardGenerator)
{
    Timer = new QTimer(this);
    Timer->start(); //Will start the timer
    ui->setupUi(this);
    connect(ui->generateBoard, SIGNAL (released()), this, SLOT (createBoard()));
    connect(ui->saveBoard, SIGNAL (released()), this, SLOT (saveBoard()));
}

boardGenerator::~boardGenerator()
{
    delete ui;
}

int boardGenerator::createBoard()

{
        int markersX = ui->xCount->text().toInt();
        int markersY = ui->yCount->text().toInt();
        int markerLength = ui->markerLength->text().toInt();
        int markerSeparation = ui->markerSeparation->text().toInt();
        int dictionaryId = ui->Dictionary->text().toInt();
        int startMarker = ui->StartIndex->text().toInt();

        int margins = markerSeparation;
        try
        {
            int borderBits = 1;

            int top, bottom, left, right;

            int sizeX = markersX * markerLength + markersX * markerSeparation + markerSeparation;
            int sizeY = markersY * markerLength + markersY * markerSeparation + markerSeparation;

            ui->actualSize->setText(QString::number(sizeX) + " x " + QString::number(sizeY) + "px");

            Size imageSize;
            imageSize.width = markersX * (markerLength + markerSeparation) - markerSeparation + 2 * margins;
            imageSize.height =
                markersY * (markerLength + markerSeparation) - markerSeparation + 2 * margins;

            Ptr<aruco::Dictionary> dictionary =
                aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME(dictionaryId));

            Ptr<aruco::GridBoard> board = aruco::GridBoard::create(markersX, markersY, float(markerLength),
                                                              float(markerSeparation), dictionary, startMarker);
            // show created board
            board->draw(imageSize, boardImage, margins, borderBits);
            cvtColor(boardImage, boardImage, COLOR_BGR2RGB);

            QImage imdisplay((uchar*)boardImage.data, boardImage.cols, boardImage.rows, boardImage.step, QImage::Format_RGB888);
            //imdisplay.save("file:///home/ubuntu/Desktop/image.jpg");

            top = 1; bottom = top;
            left = 1; right = left;
            Mat dst;
            copyMakeBorder( boardImage, dst, top, bottom, left, right, BORDER_CONSTANT, 1);
            boardImage = dst;

            ui->display_image->setPixmap(QPixmap::fromImage(imdisplay.scaledToHeight(500)));
        }
        catch(cv::Exception e)
        {
            QMessageBox m;

            m.setText(QString::fromStdString(e.what()));
            m.exec();
            return 0;
        }
        return 1;

}

int boardGenerator::saveBoard()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),QDir::currentPath());

    try
    {
        cv::imwrite(fileName.toStdString(), boardImage);
    }
    catch(cv::Exception e)
    {
        QMessageBox m;

        m.setText(QString::fromStdString(e.what()));
        m.exec();
        return 0;
    }
    return 1;
}
