#ifndef FIGURE_H
#define FIGURE_H

#include <QVector>
#include <QPair>

enum figure {rectangle, circle, line, triangle};

class Figure
{
public:
    Figure();
    virtual ~Figure();
    virtual QVector<QPair<int, int>> recognition(const QVector<QPair<int, int>>& points);

protected:

    virtual QPair<int, int> recognitionDirection(const QVector<QPair<int, int>>& points);
    QVector<QPair<int, int>> rightFigure(const QVector<QPair<int, int>>&);
    int authenticity;
    static int state; //уже внутри
    static int globalState; //как была начата фигура

    QPair<int, int> directionBegin;
    void stateMachine(int signal);
private:

};

#endif // FIGURE_H
