#include "figure.h"

Figure::Figure()
{

}

Figure::~Figure()
{

}

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
    recognitionDirection(points);
    //не найдена фигура, или мб это линия
    if (directionBegin.first == -1 || directionBegin.second == -1)
    {
        return points;
    }
    return points;
    for (int i = 0; i < points.size(); i++)
    {
        ;
    }
}


void Figure::stateMachine(int signal)
{
    //сверхну вниз слева направо
    if (this->directionBegin.first == 0 && this->directionBegin.second == 2)
    {
        ;
    }
    //сверху вниз справо налево
    if (this->directionBegin.first == 0 && this->directionBegin.second == 3)
    {
        ;
    }
    //снизу вверх слева напрво
    if (this->directionBegin.first == 1 && this->directionBegin.second == 2)
    {
        ;
    }
    //снизу вверх справо налево
    if (this->directionBegin.first == 1 && this->directionBegin.second == 3)
    {
        ;
    }
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
