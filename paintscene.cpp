#include "paintscene.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

PaintScene::~PaintScene()
{

}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit pressMouseSignal(this->points);
    // При нажатии кнопки мыши отрисовываем эллипс
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(Qt::red));
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();
    qDebug() << previousPoint;
}

void PaintScene::paintFigure(const QVector<QPair<int, int> > & points)
{
    for (int i = 0; i < points.size()-1; i++)
    {
        addLine(points[i].first, points[i].second, points[i+1].first, points[i+1].second,
                QPen(Qt::green,6,Qt::SolidLine,Qt::RoundCap));
    }

}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Отрисовываем линии с использованием предыдущей координаты
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::red,6,Qt::SolidLine,Qt::RoundCap));
    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();
    QPair<int, int> temp;
    if (previousPoint.x() > 960 || previousPoint.x() < 0)
        return;

    if (previousPoint.y() > 500 || previousPoint.y() < 0)
        return;
    temp.first = previousPoint.x();
    temp.second = previousPoint.y();
    this->points.append(temp);
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit releaseMouseSignal(this->points);
}
