#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <QVector>
#include <QPair>
#include "figure.h"

class Triangle : Figure
{
public:
    Triangle();
    QVector<QPair<int, int> > recognition(const QVector<QPair<int, int>>& points) override;

protected:
private:

    static int state; //уже внутри
//    static int globalState; //как была начата фигура

    //QPair<int, int> directionBegin;
    void stateMachine(int signal);

};

#endif // TRIANGLE_H
