
#include "mainwindow.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.graphicsView->setScene(&scene);
    QImage inputImg(":/MainWindow/test.jpg");
    QImage rtnImg = this->smooth(inputImg, 5);
    QGraphicsPixmapItem *image_item = new QGraphicsPixmapItem(QPixmap::fromImage(rtnImg));
    scene.addItem(image_item);
    ui.graphicsView->setScene(&scene);
}

void MainWindow::closeEvent(QCloseEvent* e)
{
}

void MainWindow::paintEvent(QPaintEvent *e)
{
}

QImage MainWindow::smooth(QImage inputImg, int tap)
{
    QImage rtnImg(inputImg.width(), inputImg.height(), inputImg.format());
    float num = tap * tap;
    tap /= 2;

    for(int i = 0; i < inputImg.height(); i++)
    {
        for (int j = 0; j < inputImg.width(); j++)
        {
            float sumR = 0;
            float sumG = 0;
            float sumB = 0;
            for (int m = -tap; m <= tap; m++)
            {
                for (int n = -tap; n <= tap; n++)
                {
                    int y = i + m;
                    int x = j + n;
                    if (y < 0)
                    {
                        y = 0;
                    }
                    else if (y > inputImg.height())
                    {
                        y = inputImg.height();
                    }

                    if (x < 0)
                    {
                        x = 0;
                    }
                    else if (x > inputImg.width())
                    {
                        x = inputImg.width();
                    }
                    sumR += inputImg.pixelColor(x, y).red();
                    sumG += inputImg.pixelColor(x, y).green();
                    sumB += inputImg.pixelColor(x, y).blue();
                }
            }
            sumR /= num;
            sumG /= num;
            sumB /= num;
            if (sumR < 0)
            {
                sumR = 0;
            }
            else if (sumR > 255)
            {
                sumR = 255;
            }
            if (sumG < 0)
            {
                sumG = 0;
            }
            else if (sumG > 255)
            {
                sumG = 255;
            }
            if (sumB < 0)
            {
                sumB = 0;
            }
            else if (sumB > 255)
            {
                sumB = 255;
            }
            rtnImg.setPixel(j, i, qRgb(sumR, sumG, sumB));
        }
    }
    return rtnImg;
}

