#ifndef FIGURE_H
#define FIGURE_H

#include <QVector>
#include <QPair>

class Figure
{
public:
    Figure();
    virtual ~Figure();
    virtual int recognition(QVector<QPair<int, int>>& points) = 0;

protected:
    virtual QPair<int, int> recognitionDirection(const QVector<QPair<int, int>>& points);
    int authenticity;
    static int state; //уже внутри
    static int globalState; //как была начата фигура

    QPair<int, int> directionBegin;
    void stateMachine(int signal);
private:

};

#endif // FIGURE_H
