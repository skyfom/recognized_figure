#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QPair>
#include <QVector>
#include "figure.h"

//enum figure {rectangle, circle, line, triangle};

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PaintScene(QObject *parent = nullptr);
    ~PaintScene();
    void paintFigure(const QVector<QPair<int, int>>&points, figure fig);
    void paintCircle(const QVector<QPair<int, int>>& points);

private:
    QPointF previousPoint;

signals:
    void pressMouseSignal(QVector<QPair<int, int>>&);
    void releaseMouseSignal(const QVector<QPair<int, int>>&);
private:

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QVector<QPair<int, int>> points;



    QVector<QPointF> vecTemp;
};

#endif // PAINTSCENE_H
