#ifndef FIGURE_H
#define FIGURE_H
#define PI 3.14159265359

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
    figure getTypeFigure();
    QVector<QPair<int, int>> rightFigure(const QVector<QPair<int, int>> &points, const QVector<int> &indexesChangeDirection);

protected:
    QVector<int> findChangeDirection(const vector_points& points); //возвращает индексы где произошла смена направления
    virtual QPair<int, int> recognitionDirection(const vector_points& points);


    QPair<int, int> directionBegin;
    void stateMachine(int signal);
private:
    bool isolation(const vector_points&);
    QVector<QPair<double, double>> getSinVector(const vector_points&);
    bool isEqual(double a, double b);
    vector_points smoothing(const vector_points&);
    figure type;
    void choiceTypeFigure(int countChangeDirection, const vector_points& points);



};

#endif // FIGURE_H
