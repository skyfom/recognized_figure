#include "figure.h"
#include <QDebug>
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

QVector<QPair<int, int>> Figure::recognition(const QVector<QPair<int, int> > &points)
{
    vector_points smooth_figure = smoothing(points);
    qDebug() << "11111111111111111111111111111111111111111111111111";
    qDebug() << smooth_figure;
    return smooth_figure;

    /*
     * нужно найти количество острых углов
     * по этим углам смотрим что за фигура
     * как то так
     *
     */
//    recognitionDirection(points);
//    //не найдена фигура, или мб это линия
//    if (directionBegin.first == -1 || directionBegin.second == -1)
//    {
//        return points;
//    }
//    return points;
//    for (int i = 0; i < points.size(); i++)
//    {
//        ;
//    }
}


vector_points Figure::smoothing(const vector_points &points)
{
    vector_points smooth_figure = points;
    if (points.size() == 1 || points.size() == 0)
        return points;
    //сглаживание калмана (отлично выравнивает, но круг делает угловатым, может оно и к лучшему)
    double coef_kalman = 0.1;
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


    //скользящая средняя взвешенная(плохо выравнивает)
//    vector_points smooth_figure = points;
//    for (int i = 1; i < points.size() - 1; i++)
//    {
//        QPair<int, int> smoothValue;
//        int x_smooth = (points[i-1].first + 2 * points[i].first + points[i+1].first) / 4;
//        int y_smooth = (points[i-1].second + 2 * points[i].second + points[i+1].second) / 4;
//        smoothValue.first = x_smooth;
//        smoothValue.second = y_smooth;
//        smooth_figure[i] = smoothValue;

//    }
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
