#ifndef FIGURE_H
#define FIGURE_H
#define PI 3.14159265359

#include <QVector>
#include <QPair>

enum figure {rectangle, circle, line, direct_triangle, triangle, ufo};
//enum direction {right, left, diagonal};
typedef QVector<QPair<int, int>> vector_points;
typedef QPair<int, int> Point;
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
   // bool isCircle(const vector_points&points);
    void removeSamePoints(QVector<int> &indexChangeDirection, const vector_points& points);
    bool isolation(const vector_points&);
    QVector<QPair<double, double>> getSinVector(const vector_points&);
    bool isEqual(double a, double b);
    vector_points smoothing(const vector_points&);
    figure type;
    void choiceTypeFigure(int countChangeDirection, const vector_points& points);

    int getIndexMaxY(const vector_points&points, const QVector<int> &indexesChangeDirection);
    int getIndexMinY(const vector_points&points, const QVector<int> &indexesChangeDirection);
    int getIndexMaxX(const vector_points&points, const QVector<int> &indexesChangeDirection);
    int getIndexMinX(const vector_points&points, const QVector<int> &indexesChangeDirection);

    bool isEqual(int a, int b);

    QPair<int, int> centerMass(const vector_points&points);
    vector_points findArc(const vector_points&points, QPair<int, int> center);
    vector_points findArcSecond(const vector_points&points, QPair<int, int> center);
    vector_points findArcVector(const vector_points&points);
    vector_points finalPoints(const vector_points&points1, const vector_points&points2);
    bool isCircle(const vector_points&points);
    vector_points getRightCircle(const vector_points&points);




};

#endif // FIGURE_H
