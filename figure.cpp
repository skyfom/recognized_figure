#include "figure.h"

Figure::Figure()
{

}

QPair<int, int> Figure::recognitionDirection(const QVector<QPair<int, int> > &points)
{
    int up_down = -1;
    int right_left = -1;
    QPair<int, int> temp1 = points[0];
    QPair<int, int> temp2 = points[1];
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
    this->directionBegin.first = up_down;
    this->directionBegin.second = right_left;
}
