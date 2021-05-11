#include "mypainter.h"

#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QtCore/qmath.h>

#define vCount 7

int graphRadius = 300; //радиус графа
int vertexRadius = 40; //радиус узла
double pi = 3.1415;
int HeightText = 30;
int xPadding = 600;               //отступ от вертикали
int yPadding = 400;               //отступ от горизонтали
double peakAngleRadians = pi / 8; //угол раствора стрелки
int peakLength = 24;              //длина кончика стрелки

int adjMatrix[vCount][vCount] =
{
    {0, 0, 0, 26, 9, 0, 0},
    {0, 0, 0, 17, 0, 0, 23},
    {0, 0, 0, 0, 13, 5, 0},
    {26, 17, 0, 0, 0, 42, 0},
    {9, 0, 13, 0, 0, 0, 30},
    {0, 0, 5, 42, 0, 0, 19},
    {0, 23, 0, 0, 30, 19, 0},
};

myPainter::myPainter()
{
    front = QBrush(QColor(127, 255, 212));
    back = QBrush(QColor(200, 200, 200));
    textPen = QPen(QColor(33, 33, 33));

    glFont.setPixelSize(HeightText);
}

void myPainter::draw(QPainter *painter, QPaintEvent *event)
{
    painter->fillRect(event->rect(), back);
    painter->setBrush(front);
    painter->setPen(textPen);
    painter->setFont(glFont);
    textPen.setWidth(4);

    for (int i = 0; i < vCount; i++)
    {
        //угор (полярная система координат)
        double polarAngle = pi * 3 / 2 + pi * 2 / vCount * i;

        //координаты узла графа (декартова система координат)
        int xc = cos(polarAngle) * graphRadius + xPadding;
        int yc = sin(polarAngle) * graphRadius + yPadding;

        //координаты текста (номер вершины)
        int c1 = xc - 20,
            c2 = yc - HeightText / 2,
            c3 = 40,
            c4 = HeightText;

        QString text;
        text.setNum(i + 1);
        painter->drawEllipse(QRectF(xc - vertexRadius, yc - vertexRadius, 2 * vertexRadius, 2 * vertexRadius));
        painter->drawText(QRect(c1, c2, c3, c4), Qt::AlignCenter, text);
        for (int k = 0; k < vCount; k++)
        {
            if (adjMatrix[i][k] != 0)
            {
                //линия
                double a2 = pi * 3 / 2 + pi * 2 / vCount * k;
                double xc2 = cos(a2) * graphRadius + xPadding;
                double yc2 = sin(a2) * graphRadius + yPadding;

                double l = sqrt((xc2 - xc) * (xc2 - xc) + (yc2 - yc) * (yc2 - yc));

                int xl1 = (xc2 - xc) / l * vertexRadius + xc;
                int yl1 = (yc2 - yc) / l * vertexRadius + yc;

                int xl2 = xc2 - (xc2 - xc) / l * vertexRadius;
                int yl2 = yc2 - (yc2 - yc) / l * vertexRadius;

                painter->drawLine(xl1, yl1, xl2, yl2);

                //стрелка
                double peakBaseAngleRadians;

                if (xc2 == xl2 && yl2 < yc2)
                    peakBaseAngleRadians = pi * 3 / 2;

                else if (yc2 == yl2 && xl2 < xc2)
                    peakBaseAngleRadians = pi;

                else if (xc2 == xl2 && yl2 > yc2)
                    peakBaseAngleRadians = pi / 2;

                else if (yc2 == yl2 && xl2 > xc2)
                    peakBaseAngleRadians = 0;

                else if (xl2 > xc2 && yl2 < yc2)
                    peakBaseAngleRadians = atan((yc2 - yl2) / (xc2 - xl2)) + pi * 2;

                else if (xl2 < xc2 && yl2 < yc2)
                    peakBaseAngleRadians = atan((yc2 - yl2) / (xc2 - xl2)) + pi;

                else if (xl2 < xc2 && yl2 > yc2)
                    peakBaseAngleRadians = atan((yc2 - yl2) / (xc2 - xl2)) + pi;

                else if (xl2 > xc2 && yl2 > yc2)
                    peakBaseAngleRadians = atan((yc2 - yl2) / (xc2 - xl2));

                int xs1 = cos(peakBaseAngleRadians + peakAngleRadians) * peakLength + xl2,
                    ys1 = sin(peakBaseAngleRadians + peakAngleRadians) * peakLength + yl2,
                    xs2 = cos(peakBaseAngleRadians - peakAngleRadians) * peakLength + xl2,
                    ys2 = sin(peakBaseAngleRadians - peakAngleRadians) * peakLength + yl2;

                painter->drawLine(xl2, yl2, xs1, ys1);
                painter->drawLine(xl2, yl2, xs2, ys2);

                //текст
                c1 = (xl2 + xl1) / 2 - 20;
                c2 = (yl2 + yl1) / 2 - HeightText / 2 - 20;
                c3 = 40;
                c4 = HeightText;

                text.setNum(adjMatrix[i][k]);
                painter->drawText(QRect(c1, c2, c3, c4), Qt::AlignCenter, text);
            }
        }
    }
}
