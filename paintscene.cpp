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
    addEllipse(event->scenePos().x() ,
               event->scenePos().y() ,
               2,
               2,
               QPen(Qt::NoPen),
               QBrush(Qt::red));
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();
    qDebug() << previousPoint;
}

void PaintScene::paintFigure(const QVector<QPair<int, int> > & points, figure fig)
{
//    qDebug() << points;
//    for (int i = 0; i < points.size(); i++)
//    {

//        addLine(points[i].first, points[i].second, points[i].first + 1, points[i].second + 1,
//                QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
//    }


    if (fig == figure::circle)
        {
            addEllipse(points[0].first, points[0].second, points[1].first, points[1].second,
                    QPen(Qt::green, 6, Qt::SolidLine, Qt::RoundCap));
        }
        else
        {
            for (int i = 0; i < points.size()-1; i++)
            {
                addLine(points[i].first, points[i].second, points[i+1].first, points[i+1].second,
                        QPen(Qt::green, 6, Qt::SolidLine, Qt::RoundCap));
            }
            addLine(points[0].first, points[0].second, points[points.size()-1].first, points[points.size()-1].second,
                    QPen(Qt::green, 6, Qt::SolidLine, Qt::RoundCap));

        }





//    if (fig == figure::circle)
//    {
//        int x = points[0].first;
//        int y = points[0].second;

//        int w = std::abs(points[0].first - points[1].first / 2);
//        int h = std::abs(points[0].second - points[1].second / 2);
//        addEllipse(x, y, w, h, QPen(Qt::green, 6, Qt::SolidLine, Qt::RoundCap));
//        if (points.size() == 2)
//        {
//            int x1 = (points[0].first + points[1].first) / 2;
//            int y1 = (points[0].second + points[1].second) / 2;
//            int w = std::abs(points[1].first - points[0].first) * 2;
//            int h = std::abs(points[1].second - points[0].second) * 2;
//            addEllipse(100, 100, 100, 100, QPen(Qt::red,6,Qt::SolidLine,Qt::RoundCap));
//        }
//    }
//    else if (fig == figure::rectangle)
//    {
//        int x = points[0].first;
//        int y = points[0].second;

//        int w = std::abs(points[0].first - points[1].first);
//        int h = std::abs(points[0].second - points[1].second);
//       addRect(x, y, w, h, QPen(Qt::green, 6, Qt::SolidLine, Qt::RoundCap));
//    }
//    for (int i = 0; i < points.size()-1; i++)
//    {
//        addLine(points[i].first, points[i].second, points[i+1].first, points[i+1].second,
//                QPen(Qt::green,6,Qt::SolidLine,Qt::RoundCap));
//    }

}

void PaintScene::paintCircle(const QVector<QPair<int, int>>& points)
{
//    for (int i = 0; i < points.size() -1; i++)
//    {
//        addLine(points[i].first, points[i].second, points[i+1].first, points[i+1].second, QPen(Qt::green,6,Qt::SolidLine,Qt::RoundCap));
//    }
    for (int i = 0; i < points.size(); i++)
    {
       addLine(points[i].first, points[i].second, points[i].first+1, points[i].second+1, QPen(Qt::green,2,Qt::SolidLine,Qt::RoundCap));

    }




}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    // Отрисовываем линии с использованием предыдущей координаты
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::red,2,Qt::SolidLine,Qt::RoundCap));
    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();
    vecTemp.append(previousPoint);

//    if (previousPoint.x() > 960 || previousPoint.x() < 0)
//        return;

//    if (previousPoint.y() > 500 || previousPoint.y() < 0)
//        return;
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    for (int i = 0; i < vecTemp.size(); i++)
    {
        QPair<int, int> temp;
        temp.first = vecTemp[i].rx();
        temp.second = vecTemp[i].ry();
        points.append(temp);
    }
    vecTemp.clear();
    emit releaseMouseSignal(this->points);
}
