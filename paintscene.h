#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QPair>
#include <QVector>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PaintScene(QObject *parent = nullptr);
    ~PaintScene();
    void paintFigure(const QVector<QPair<int, int>>&);

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
};

#endif // PAINTSCENE_H
