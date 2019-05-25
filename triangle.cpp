#include "triangle.h"

int Triangle::state = 0;

Triangle::Triangle()
{

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



int Triangle::recognition(QVector<QPair<int, int> > &points)
{
    authenticity = 0;
    recognitionDirection(points);
    if (directionBegin.first == -1 || directionBegin.second == -1)
    {
        return authenticity;
    }
    for (int i = 0; i < points.size(); i++)
    {

    }
}

void Triangle::stateMachine(int signal)
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
