#include "figure.h"
#include <QDebug>
#include <math.h>

Figure::Figure()
{

}

Figure::~Figure()
{

}


QVector<QPair<int, int>> Figure::rightFigure(const QVector<QPair<int, int>> &points, const QVector<int> &indexesChangeDirection)
{
    vector_points rightFig;
    if (this->type != figure::circle && this->type != figure::line)
    {
        rightFig.append(points[0]);
        for (int i = 0; i < indexesChangeDirection.size(); i++)
        {
           QPair<int, int> convert;
           int index = indexesChangeDirection[i];
           convert.first = points[index].first;
           convert.second = points[index].second;
           rightFig.append(convert);
        }
        rightFig.append(points[0]);
    }
    else if (this->type == figure::circle)
    {
        rightFig.append(points[0]);
        rightFig.append(points[points.size() / 2]);
    }
    return rightFig;

}

bool Figure::isEqual(double a, double b)
{
    double epsilon = 0.0000001;
    if (std::fabs(a - b) < epsilon)
    {
        return true;
    }
    return false;
}

QVector<QPair<double, double>> Figure::getSinVector(const vector_points &points)
{
    QVector<QPair<double, double>> pointsSin;
    for (int i = 0; i < points.size(); i++)
    {
        QPair<double, double> point;
        point.first = sin(points[i].first * PI / 180.0);
        point.second = sin(points[i].second * PI / 180.0);
        pointsSin.append(point);
    }
    return pointsSin;
}

bool Figure::isolation(const vector_points &points)
{
    //если точка конца лежит в окрестости точки начала
    int x_okr = 100;
    int y_okr = 100;
    if (std::abs(points[0].first - points[points.size()-1].first) <= x_okr &&
            std::abs(points[0].second - points[points.size()-1].second) <= y_okr)
        return true;
    return false;
}

QVector<int> Figure::findChangeDirection(const vector_points &points)
{
    QVector<int> indexesChangeDirection;
    QVector<QPair<double, double>> pointsSin = this->getSinVector(points);
    int countChangeDirection = 0;
    bool change_po_x;
    bool oneMoreMinus = false;
    for (int i = 0; i < pointsSin.size() - 4; i+=3)
    {
        if (!oneMoreMinus)
        {
            if (isEqual(pointsSin[i].first, pointsSin[i+2].first))
            {
                if (!isEqual(pointsSin[i].second, points[i+2].second))
                {
                    change_po_x = false;
                    oneMoreMinus = true;
                }
                else {
                    continue;
                }
            }
            else if (isEqual(pointsSin[i].second, pointsSin[i+2].second)) {
                if (!isEqual(pointsSin[i].first, points[i+2].first))
                {
                    change_po_x = true;
                    oneMoreMinus = true;
                }
                else {
                    continue;
                }

            }

        }

        for (int j = i; j < i + 4; j++)
        {

            if (change_po_x)
            {
                if (isEqual(pointsSin[j].first, pointsSin[j+1].first))
                {
                    if (!isEqual(pointsSin[j].second, pointsSin[j+1].second))
                    {
                        change_po_x = false;
                        countChangeDirection++;
                        indexesChangeDirection.append(i);
                        break;
                    }
                }
            }
            else if (!change_po_x)
            {
                if (isEqual(pointsSin[j].second, pointsSin[j+1].second))
                {
                    if (!isEqual(pointsSin[j].first, pointsSin[j+1].first))
                    {
                        change_po_x = true;
                        countChangeDirection++;
                        indexesChangeDirection.append(i);
                        break;
                    }
                }
            }

        }
    }
//    qDebug() << countChangeDirection;
//    //это вынести в другую функцию, просто щас проверка
//    if (countChangeDirection >= 4)
//        qDebug() << "Я думаю, что это КРУГ!";
//    else if (countChangeDirection >= 3) {
//        qDebug() << "Я думаю, что это ПРЯМОУГОЛЬНИК!";
//    }
//    else if (countChangeDirection >= 2)
//        qDebug() << "Я думаю, что это ТРЕУГОЛЬНИК";
//    else {
//        qDebug() << "Я думаю, что это просто линия";
//    }
//    qDebug() << isolation(points);

    return indexesChangeDirection;
}

void Figure::choiceTypeFigure(int countChangeDirection, const vector_points &points)
{
    if (countChangeDirection >= 4)
    {
        if (isolation(points))
            this->type = figure::circle;
        else {
            this->type = figure::line;
        }
    }

    else if (countChangeDirection >= 3) {
        this->type = figure::rectangle;
    }
    else if (countChangeDirection >= 2){
        this->type = figure::triangle;
    }
    else {
        this->type = figure::line;
    }
}

figure Figure::getTypeFigure()
{
    return this->type;
}

QVector<QPair<int, int>> Figure::recognition(const QVector<QPair<int, int> > &points)
{
    vector_points smooth_figure = smoothing(points);
    qDebug() << "11111111111111111111111111111111111111111111111111";
    QVector<int> indexChangeDirection = this->findChangeDirection(smooth_figure);
    int countChangeDirection = indexChangeDirection.size();
    this->choiceTypeFigure(countChangeDirection, smooth_figure);
    if (this->type == figure::line)
        return points;
    else {
        return this->rightFigure(smooth_figure, indexChangeDirection);
    }


}


vector_points Figure::smoothing(const vector_points &points)
{
    //return points;
    vector_points smooth_figure = points;
    if (points.size() == 1 || points.size() == 0)
        return points;
    //сглаживание калмана
    double coef_kalman = 0.11;
    int x_smooth_past = coef_kalman * points[0].first + (1 - coef_kalman) ;
    x_smooth_past = points[0].first;
    int y_smooth_past = coef_kalman * points[0].second + (1 - coef_kalman);
    y_smooth_past = points[0].second;
    for (int i = 0; i < points.size()-1; i++)
    {
        QPair<int, int> smoothValue;
        int x_smooth = coef_kalman * points[i+1].first + (1 - coef_kalman) * x_smooth_past;
        int y_smooth = coef_kalman * points[i+1].second + (1-coef_kalman) * y_smooth_past;
        smoothValue.first = x_smooth;
        smoothValue.second = y_smooth;
        x_smooth_past = x_smooth;
        y_smooth_past = y_smooth;
        smooth_figure[i] = smoothValue;
    }
    return smooth_figure;
}


void Figure::stateMachine(int signal)
{

//    //сверхну вниз слева направо
//    if (this->directionBegin.first == 0 && this->directionBegin.second == 2)
//    {
//        ;
//    }
//    //сверху вниз справо налево
//    if (this->directionBegin.first == 0 && this->directionBegin.second == 3)
//    {
//        ;
//    }
//    //снизу вверх слева напрво
//    if (this->directionBegin.first == 1 && this->directionBegin.second == 2)
//    {
//        ;
//    }
//    //снизу вверх справо налево
//    if (this->directionBegin.first == 1 && this->directionBegin.second == 3)
//    {
//        ;
//    }
}

QPair<int, int> Figure::recognitionDirection(const QVector<QPair<int, int> > &points)
{
    int up_down = -1;
    int right_left = -1;
    QPair<int, int> temp1 = points[0];
    QPair<int, int> temp2 = points[1];
    QPair<int, int> directionBegin;
    if (temp1.second > temp2.second)
        up_down = 0;
    else {
        up_down = 1;
    }
    if (temp1.first > temp2.first)
        right_left = 3;
    else {
        right_left = 2;
    }
    directionBegin.first = up_down;
    directionBegin.second = right_left;
    return directionBegin;
}
