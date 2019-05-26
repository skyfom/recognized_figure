#include "figure.h"
#include <QDebug>
#include <math.h>

Figure::Figure()
{

}

Figure::~Figure()
{

}

int Figure::state = 0;

QVector<QPair<int, int>> Figure::rightFigure(const QVector<QPair<int, int>> &points){
    return points;
}
//в сцене перевернутый y
//сначала надо понять как был начат треугольник, сверху вниз или снизу вверх, справа на лево или слева направо
// за это будет отвечать direction - first - up or down, second - right or left
// 0 - сверху вниз
// 1 - снизу вверх
// 2 - слева направо
// 3 - справа налево
/*
 *  сигналы:
 * 0 - увеличение по икс и умеьшение по y
 * 1 - уменьшение по икс и ув
 *
 * состояния:
 * 0 - увеличение по икс и уменьшение по y
 * 1 -
 */

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
    int x_okr = 40;
    int y_okr = 40;
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
    bool change_po_x = false;
    bool change_direction = false;
    bool oneMoreMinus = false;
    for (int i = 0; i < pointsSin.size() - 4; i+=3)
    {

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
                        //Запись индексов
                        break;
                    }
                }
            }
            else
            {
                if (isEqual(pointsSin[j].second, pointsSin[j+1].second))
                {
                    if (!isEqual(pointsSin[j].first, pointsSin[j+1].first))
                    {
                        change_po_x = true;
                        countChangeDirection++;

                        //запись индексов
                        break;
                    }
                }
            }
        }
    }
    qDebug() << countChangeDirection;
    //это вынести в другую функцию, просто щас проверка
    if (countChangeDirection >= 4)
        qDebug() << "Я думаю, что это КРУГ!";
    else if (countChangeDirection >= 3) {
        qDebug() << "Я думаю, что это ПРЯМОУГОЛЬНИК!";
    }
    else if (countChangeDirection >= 2)
        qDebug() << "Я думаю, что это ТРЕУГОЛЬНИК";
    else {
        qDebug() << "Я думаю, что это просто линия";
    }
    qDebug() << isolation(points);

    return indexesChangeDirection;
}

QVector<QPair<int, int>> Figure::recognition(const QVector<QPair<int, int> > &points)
{
    vector_points smooth_figure = smoothing(points);
    qDebug() << "11111111111111111111111111111111111111111111111111";
    //qDebug() << smooth_figure;
    this->findChangeDirection(smooth_figure);

    return smooth_figure;

    /*
     * нужно найти количество острых углов
     * по этим углам смотрим что за фигура
     * как то так
     * если одна ось становиться наподвижной(считаем погрешность в сотую(тысячную)) а другая изменяется, то поменялось направление
     * там где поменялось направление записываем индекс в какой нибудь массив, чтоб по этим точкам отстроить правильную фигуру(кроме круга)
     * в случае с кругом, посчитаем точку центра примерную, и от нее что то будем делать
     *
     */

}


vector_points Figure::smoothing(const vector_points &points)
{
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
