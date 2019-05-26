#ifndef FIGURE_H
#define FIGURE_H

#include <QVector>
#include <QPair>

enum figure {rectangle, circle, line, triangle};
typedef QVector<QPair<int, int>> vector_points;
class Figure
{
public:
    Figure();
    virtual ~Figure();
    virtual QVector<QPair<int, int>> recognition(const vector_points& points);

protected:

    virtual QPair<int, int> recognitionDirection(const vector_points& points);
    QVector<QPair<int, int>> rightFigure(const vector_points&);

    QPair<int, int> directionBegin;
    void stateMachine(int signal);
private:
    vector_points smoothing(const vector_points&);
    int authenticity;
    static int state; //уже внутри
    static int globalState; //как была начата фигура


};

#endif // FIGURE_H
