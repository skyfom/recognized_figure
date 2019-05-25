#include "triangle.h"

int Triangle::state = 0;

Triangle::Triangle()
{

}


QVector<QPair<int, int> > Triangle::recognition(const QVector<QPair<int, int> > &points)
{
    authenticity = 0;
    recognitionDirection(points);
    if (directionBegin.first == -1 || directionBegin.second == -1)
    {
        return points;
    }
    for (int i = 0; i < points.size(); i++)
    {

    }
    return points;
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
