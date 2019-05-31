#include "figure.h"
#include <QDebug>
#include <math.h>

Figure::Figure()
{

}

Figure::~Figure()
{

}

int Figure::getIndexMaxX(const vector_points &points, const QVector<int> &indexesChangeDirection)
{
    int tempY = indexesChangeDirection[0];
    for (int i = 0; i < indexesChangeDirection.size() - 1; i++)
    {
        if (points[indexesChangeDirection[i]].first > points[indexesChangeDirection[i+1]].first)
            tempY = indexesChangeDirection[i];
    }
    return tempY;
}

int Figure::getIndexMinX(const vector_points &points, const QVector<int> &indexesChangeDirection)
{
    //int indexMax;
    int tempY = indexesChangeDirection[0];
    for (int i = 0; i < indexesChangeDirection.size() - 1; i++)
    {
        if (points[indexesChangeDirection[i]].first < points[indexesChangeDirection[i+1]].first)
            tempY = indexesChangeDirection[i];
    }
    return tempY;
}

int Figure::getIndexMaxY(const vector_points&points, const QVector<int> &indexesChangeDirection)
{
    //int indexMax;
    int tempY = indexesChangeDirection[0];
    for (int i = 0; i < indexesChangeDirection.size() - 1; i++)
    {
        if (points[indexesChangeDirection[i]].second > points[indexesChangeDirection[i+1]].second)
            tempY = indexesChangeDirection[i];
    }
    return tempY;
}

int Figure::getIndexMinY(const vector_points&points, const QVector<int> &indexesChangeDirection)
{
    //int indexMax;
    int tempY = indexesChangeDirection[0];
    for (int i = 0; i < indexesChangeDirection.size() - 1; i++)
    {
        if (points[indexesChangeDirection[i]].second < points[indexesChangeDirection[i+1]].second)
            tempY = indexesChangeDirection[i];
    }
    return tempY;
}


QVector<QPair<int, int>> Figure::rightFigure(const QVector<QPair<int, int>> &points, const QVector<int> &indexesChangeDirection)
{
    vector_points rightFig;
    for (int i = 0; i < indexesChangeDirection.size(); i++)
    {
        QPair<int, int> temp;
        temp.first = points[indexesChangeDirection[i]].first;
        temp.second = points[indexesChangeDirection[i]].second;
        rightFig.append(temp);
    }
//    if (this->type == figure::rectangle || this->type == figure::circle)
//    {
//            //нужна левая верхняя и правая нижняя
//        QPair<int, int> convertLeftUp;
//        QPair<int, int> convertRightDown;
//        int x1 = points[getIndexMinX(points, indexesChangeDirection)].first;
//        int y1 = points[getIndexMinY(points, indexesChangeDirection)].second;
//        int x2 = points[getIndexMaxX(points, indexesChangeDirection)].first;
//        int y2 = points[getIndexMaxY(points, indexesChangeDirection)].second;
//        convertLeftUp.first = x1;
//        convertLeftUp.second = y1;
//        convertRightDown.first = x2;
//        convertRightDown.second = y2;
//        rightFig.append(convertLeftUp);
//        rightFig.append(convertRightDown);

//    }
//    else if (this->type == figure::triangle)
//    {
//        rightFig.append(points[0]);
//        for (int i = 0; i < indexesChangeDirection.size(); i++)
//        {
//            rightFig.append(points[indexesChangeDirection[i]]);
//        }
//        rightFig.append(points[0]);
//    }
    return rightFig;

}

bool Figure::isEqual(int a, int b)
{
    if (std::abs(a - b) < 2)
        return true;
    else return false;
}

bool Figure::isEqual(double a, double b)
{
    double epsilon = 0.000001;
    if (std::fabs(a - b) < epsilon)
    {
        return true;
    }
    return false;
}

QVector<QPair<double, double>> Figure::getSinVector(const vector_points &points)
{
    QVector<QPair<double, double>> pointsSin;
    for (int i = 0; i < points.size(); i++)
    {
        QPair<double, double> point;
        point.first = sin(points[i].first * PI / 180.0);
        point.second = sin(points[i].second * PI / 180.0);
        pointsSin.append(point);
    }
    return pointsSin;
}

bool Figure::isolation(const vector_points &points)
{
    //если точка конца лежит в окрестости точки начала
    int x_okr = 100;
    int y_okr = 100;
    if (std::abs(points[0].first - points[points.size()-1].first) <= x_okr &&
            std::abs(points[0].second - points[points.size()-1].second) <= y_okr)
        return true;
    return false;
}

QVector<int> Figure::findChangeDirection(const vector_points &points)
{
    QVector<int> indexesChangeDirection;
    int countDirection = 0;
    bool initBeginDirection = false;
    //direction dir;
    // посмотреть первые четрые точки и узнать начальное направление движение линиии (cначала диагональ потом по икс потом по y)
    // исходя из направлени
    for (int i = 0; i < points.size() - 1; i++)
    {
        if (!initBeginDirection)
        {
            bool flagDontDirection = false; // флаг того, что условие определение начального движения не выполнилось
            for (int j = 0; j < 4; j++)
            {
               ;
            }
        }

    }






//    QVector<int> indexesChangeDirection;
//    QVector<QPair<double, double>> pointsSin = this->getSinVector(points);
//    int countChangeDirection = 0;
//    bool change_po_x;
//    bool oneMoreMinus = false;
//    bool flag = false; //почему то вначале ставит две точки, ну или не в начале???
//    for (int i = 0; i < pointsSin.size() - 4; i+=3)
//    {
//        if (!oneMoreMinus)
//        {
//            if (isEqual(pointsSin[i].first, pointsSin[i+3].first))
//            {
//                if (!isEqual(pointsSin[i].second, points[i+3].second))
//                {
//                    change_po_x = false;
//                    oneMoreMinus = true;
//                }
//                else {
//                    continue;
//                }
//            }
//            else if (isEqual(pointsSin[i].second, pointsSin[i+2].second)) {
//                if (!isEqual(pointsSin[i].first, points[i+2].first))
//                {
//                    change_po_x = true;
//                    oneMoreMinus = true;
//                }
//                else {
//                    continue;
//                }

//            }
//        }
//        for (int j = i; j < i + 4; j++)
//        {
//            if (change_po_x)
//            {
//                if (isEqual(pointsSin[j].first, pointsSin[j+1].first))
//                {
//                    if (!isEqual(pointsSin[j].second, pointsSin[j+1].second))
//                    {
//                        change_po_x = false;

//                        countChangeDirection++;
//                        indexesChangeDirection.append(i);

//                        break;
//                    }
//                }
//            }
//            else if (!change_po_x)
//            {
//                if (isEqual(pointsSin[j].second, pointsSin[j+1].second))
//                {
//                    if (!isEqual(pointsSin[j].first, pointsSin[j+1].first))
//                    {
//                        change_po_x = true;
//                        countChangeDirection++;
//                        indexesChangeDirection.append(i);
//                        break;
//                    }
//                }
//            }

//        }
//    }
    return indexesChangeDirection;
}

void Figure::choiceTypeFigure(int countChangeDirection, const vector_points &points)
{
    if (countChangeDirection >= 4)
    {
        this->type = figure::circle;
//        if (isolation(points))
//            this->type = figure::circle;
//        else {
//            this->type = figure::line;
//        }
    }

    else if (countChangeDirection >= 3) {
        this->type = figure::rectangle;
    }
    else if (countChangeDirection >= 2){
        this->type = figure::triangle;
    }
    else {
        this->type = figure::line;
    }
}

figure Figure::getTypeFigure()
{
    return this->type;
}

void Figure::removeSamePoints(QVector<int> &indexChangeDirection, const vector_points& points)
{
    for (int i = 0; i < indexChangeDirection.size()-1; i++)
    {
        if (points[indexChangeDirection[i]].first == points[indexChangeDirection[i+1]].first &&
                points[indexChangeDirection[i]].second == points[indexChangeDirection[i+1]].second)
        {
            qDebug() << "ERASE SAME POINTS!";
            indexChangeDirection.erase(indexChangeDirection.begin() + i);
        }
    }
}

QPair<int, int> Figure::centerMass(const vector_points &points)
{
    QPair<int, int> center;
    int x_sum = 0;
    int y_sum = 0;
    for (int i = 0; i < points.size(); i++)
    {
        x_sum += points[i].first;
        y_sum += points[i].second;
    }
    center.first = x_sum / points.size();
    center.second = y_sum / points.size();
    return center;
}

vector_points Figure::findArc(const vector_points &points, QPair<int, int> center)
{
    int line1 = 0;
    int line2 = 0;
    int line3 = 0;
    int line4 = 0;
    vector_points arcs;
    Point arc1;
    Point arc2;
    Point arc3;
    Point arc4;
    //первая проверка четвертей
    for (int i = 0; i < points.size(); i++)
    {
        if (center.first < points[i].first && center.second < points[i].second)
        {
            if (line1 < sqrt(pow((center.first - points[i].first),2) + pow((center.second-points[i].second),2)))
            {
                line1 = sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
                arc1.first = points[i].first;
                arc1.second = points[i].second;
            }

        }
        if (center.first > points[i].first && center.second < points[i].second)
        {
            if (line2 < sqrt(pow((center.first - points[i].first),2) + pow((center.second-points[i].second),2)))
            {
                line2 = sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
                arc2.first = points[i].first;
                arc2.second = points[i].second;
            }
        }
        if (center.first > points[i].first && center.second > points[i].second)
        {
            if (line3 < sqrt(pow((center.first - points[i].first),2) + pow((center.second-points[i].second),2)))
            {
                line3 = sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
                arc3.first = points[i].first;
                arc3.second = points[i].second;
            }
        }
        if (center.first < points[i].first && center.second > points[i].second)
        {
            if (line4 < sqrt(pow((center.first - points[i].first),2) + pow((center.second-points[i].second),2)))
            {
                line4 = sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
                arc4.first = points[i].first;
                arc4.second = points[i].second;
            }
        }
    }
    arcs.append(arc1);
    arcs.append(arc2);
    arcs.append(arc3);
    arcs.append(arc4);
    return arcs;
}

vector_points Figure::findArcSecond(const vector_points &points, QPair<int, int> center)
{
    int line1 = 0;
    int line2 = 0;
    int line3 = 0;
    int line4 = 0;
    vector_points arcs;
    Point arc1;
    Point arc2;
    Point arc3;
    Point arc4;
    for (int i=0; i < points.size();i++)
    {
           if (points[i].second > center.second+std::abs(center.first - points[i].first))
           {
               if (line1 < sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2)))
               {
                   line1 = sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
                   arc1.first = points[i].first;
                   arc1.second = points[i].second;
               }

           }
           else if (points[i].second < center.second - std::abs(center.first - points[i].first))
           {
               if (line2 < sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2)))
               {
                   line2 = sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
                   arc2.first = points[i].first;
                   arc2.second = points[i].second;
               }
           }
           else if (points[i].second > center.second - std::abs(center.first - points[i].first) && points[i].second < center.second +
                    std::abs(center.first - points[i].first) && center.first > points[i].first)
           {
               if (line3 < sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2)))
               {
                   line3 = sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
                   arc3.first = points[i].first;
                   arc3.second = points[i].second;
               }
           }
           else if (points[i].second > center.second - std::abs(center.first - points[i].first) &&
                    points[i].second < center.second + std::abs(center.first - points[i].first) && center.first < points[i].first)
           {
               if (line4 < sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2)))
               {
                   line4 = sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
                   arc4.first = points[i].first;
                   arc4.second = points[i].second;
               }
           }
    }
    arcs.append(arc1);
    arcs.append(arc2);
    arcs.append(arc3);
    arcs.append(arc4);
    return arcs;
}

vector_points Figure::finalPoints(const vector_points &points1, const vector_points &points2)


{
    //вернет вектор точек которые совпадают в обоих векторах
    vector_points final;
    for (int i = 0; i < points1.size(); i++)
    {
        for (int j = 0; j < points2.size(); j++)
        {
            if (points1[i].first == points2[j].first && points1[i].second == points2[j].second)
                final.append(points1[i]);
        }
    }
    return final;

}
vector_points Figure::getRightCircle(const vector_points &points)
{
    vector_points rightFig;
    Point center = centerMass(points);
    Point w_h;
    Point x1_y1;
    double radius=0;
    //rightFig.append(center);
    for (int i=0; i < points.size(); i++)
    {
        radius += sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
    }
    radius = radius / points.size();
    x1_y1.first = center.first - radius;
    x1_y1.second = center.second - radius;
    w_h.first = radius*2;//std::abs(points[points.size()/2].first - center.first / 2);
    w_h.second = radius*2;//w_h.first;

    rightFig.append(x1_y1);
    rightFig.append(w_h);
    return rightFig;
}
vector_points Figure::findArcVector(const vector_points &arr)
{
    int count90Arc = 0;
    double CkPr,Mod1, Mod2;
    double aX,aY,bX,bY;
    vector_points arcs;
    int count = arr.size();
    int indexDirectArc = 0;




    for (int i=0; i < count - 6; i++)
    {
        aX = arr[i+3].first-arr[i].first;
        aY = arr[i+3].second-arr[i].second;
        bX = arr[i+6].first-arr[i+3].first;
        bY = arr[i+6].second-arr[i+3].second;
        Mod1 = sqrt(pow(aX,2)+pow(aY,2));
        Mod2 = sqrt(pow(bX,2)+pow(bY,2));
        CkPr = aX*bX+aY*bY;
       qDebug() << acos( CkPr / ( Mod1*Mod2 ) )* 180.0 / PI;
//        if ((acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) >= 20 && (acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) <= 150 && i!=0)
//        {
//            Point arc;
//                       arc.first = arr[i+3].first;
//                       arc.second = arr[i+3].second;
//                       arcs.append(arc);
//                       i+=20;
//        }


        qDebug() << acos(CkPr/(Mod1*Mod2)* 180.0 / PI);
        if ((acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) >= 70 && (acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) <= 120 && i!=0 && i+6<count-1)
        {
            count90Arc++;
            Point arc;
            arc.first = arr[i+3].first;
            arc.second = arr[i+3].second;
            arcs.append(arc);
            indexDirectArc = arcs.size() - 1;
            i+=20;
        }
        else  if ((acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) >= 30 && (acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) <= 70 && i!=0 && i+6<count-1)
        {
            Point arc;
            arc.first = arr[i+3].first;
            arc.second = arr[i+3].second;
            arcs.append(arc);
            i+=20;
        }
        else if ((acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) >= 120 && (acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) <= 140 && i!=0 && i+6<count-1)
        {
            Point arc;
            arc.first = arr[i+3].first;
            arc.second = arr[i+3].second;
            arcs.append(arc);
            i+=20;
        }
    }
    if (isolation(arr))
    {
        aX = arr[count-1].first-arr[count-4].first;
        aY = arr[count-1].second-arr[count-4].second;
        bX = arr[3].first-arr[0].first;
        bY = arr[3].second-arr[0].second;
        Mod1 = sqrt(pow(aX,2)+pow(aY,2));
        Mod2 = sqrt(pow(bX,2)+pow(bY,2));
        CkPr = aX*bX+aY*bY;
       qDebug() << acos( CkPr / ( Mod1*Mod2 ) )* 180.0 / PI;

        //qDebug() << acos(CkPr/(Mod1*Mod2)* 180.0 / PI);
        if ((acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) >= 80 && (acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) <= 120 )
        {

            count90Arc++;
            Point arc;
            arc.first = arr[0].first;
            arc.second = arr[0].second;
            arcs.append(arc);
            indexDirectArc = arcs.size() - 1;
           // i+=20;
        }
        else  if ((acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) >= 30 && (acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) <= 80 )
        {
            Point arc;
            arc.first = arr[0].first;
            arc.second = arr[0].second;
            arcs.append(arc);
         //   i+=20;
        }
        else if ((acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) >= 120 && (acos( CkPr / ( Mod1*Mod2 ) ) * 180.0 / PI) <= 130 )
        {
            Point arc;
            arc.first = arr[0].first;
            arc.second = arr[0].second;
            arcs.append(arc);
            //i+=20;
        }

    }

    double line1 = 0;
    double line2 = 0;
    double line3 = 0;
    double line4 = 0;
    double line5 = 0;
    double line6 = 0;
    if (arcs.size() == 4)
    {
        line1 = sqrt(pow((arcs[1].first-arcs[0].first),2) + pow((arcs[1].second-arcs[0].second),2));
        line2 = sqrt(pow((arcs[2].first-arcs[1].first),2) + pow((arcs[2].second-arcs[1].second),2));
        line3 = sqrt(pow((arcs[3].first-arcs[2].first),2) + pow((arcs[3].second-arcs[2].second),2));
        line4 = sqrt(pow((arcs[3].first-arcs[0].first),2) + pow((arcs[3].second-arcs[0].second),2));

        line5 = (line1+line3)/2;
        line6 = (line2+line4)/2;
        if (line1 <= line5+line5*0.4 && line1 >= line5-line5*0.4  && line3 <= line5+line5*0.4 && line3 >= line5-line5*0.4 && line2 <= line6+line6*0.4 && line2 >= line6-line6*0.4 && line4 <= line6+line6*0.4 && line4 >= line6-line6*0.4)
        {
            this->type = figure::rectangle;
        }
        else if (isCircle(arr)) this->type = figure::circle;
        else this->type = figure::ufo;
       // else this->type = figure::triangle;


    }
    else if (arcs.size() == 3)
    {
        if (count90Arc == 1)
        {

            if (indexDirectArc != arcs.size() - 1)
            {
                Point temp = arcs[arcs.size() - 1];
                arcs[arcs.size()-1] = arcs[indexDirectArc];
                arcs[indexDirectArc] = temp;
            }


            line1 = sqrt(pow((arcs[2].first-arcs[0].first),2) + pow((arcs[2].second-arcs[0].second),2));
            line2 = sqrt(pow((arcs[2].first-arcs[1].first),2) + pow((arcs[2].second-arcs[1].second),2));
            line3 = sqrt(pow((arcs[1].first-arcs[0].first),2) + pow((arcs[1].second-arcs[0].second),2));
            if (line3 <= (sqrt(pow(line1, 2)+ pow(line2,2))+sqrt(pow(line1, 2)+ pow(line2,2))*0.3) &&
                    line3 >= (sqrt(pow(line1, 2)+ pow(line2,2))-sqrt(pow(line1, 2)+ pow(line2,2))*0.3))
            {
                this->type = figure::direct_triangle;
            }
           // else if (isCircle(arr)) this->type = figure::circle;
            else this->type = figure::triangle;


        }

       // else if (isCircle(arr)) this->type = figure::circle;
        else this->type = figure::triangle;

    }
    else if (arcs.size() <= 2 || arcs.size() > 4)
    {
        //if (arcs.size()==0 || arcs.size()==1) this->type = figure::circle;
        // else if (isCircle(arr)) this->type = figure::circle;
        if (isCircle(arr)) this->type = figure::circle;
        else this->type = figure::ufo;
          //else this->type = figure::line;
    }
        //this->type = figure::circle;
   // else this->type = figure::line;
    qDebug() <<"Amount  points"<<arcs.size();
    return arcs;
}


bool Figure::isCircle(const vector_points&points)
{
    double cpRad=0;
    double line1, line2;
    double errore;
    Point center = centerMass(points);
    for (int i=0; i < points.size(); i++)
    {
        cpRad += sqrt(pow((center.first-points[i].first),2) + pow((center.second-points[i].second),2));
    }
    cpRad = cpRad / points.size();

    line1 = sqrt(pow((center.first-points[points.size()-1].first),2) + pow((center.second-points[points.size()-1].second),2));
    line2 = sqrt(pow((center.first-points[points.size()/2].first),2) + pow((center.second-points[points.size()/2].second),2));
    errore = cpRad*0.2;
    if (line1 >= (cpRad-errore) && line1 <= (cpRad+errore)&& line2 >= (cpRad-errore) && line2 <= (cpRad+errore))
    {
        return true;
    }
    else return false;

}


QVector<QPair<int, int>> Figure::recognition(const QVector<QPair<int, int> > &points)
{
    qDebug() << points.size();

    vector_points smooth_figure = smoothing(points);

    //return smooth_figure;

    qDebug() << smooth_figure.size();
    //return smooth_figure;
    if (!isolation(points))
    {
        this->type = figure::line;
        return points;
    }
    vector_points arcs = findArcVector(smooth_figure);


//    QPair<int, int> temp = this->centerMass(smooth_figure);
//    vector_points arcs = findArc(smooth_figure, temp);
//    vector_points arcs_second = findArcSecond(smooth_figure, temp);
//    vector_points arc_final = finalPoints(arcs, arcs_second);
//    qDebug() << arcs << "ONE MORE: " << arcs_second << "FINAL: " << arc_final;
    if (type == figure::circle)
            arcs = getRightCircle(points);
    return arcs;





    qDebug() << "11111111111111111111111111111111111111111111111111";
    QVector<int> indexChangeDirection = this->findChangeDirection(smooth_figure);
    //removeSamePoints(indexChangeDirection, smooth_figure);
    int countChangeDirection = indexChangeDirection.size();
    this->choiceTypeFigure(countChangeDirection, smooth_figure);
    if (this->type == figure::line)
        return points;
    else {
        return this->rightFigure(smooth_figure, indexChangeDirection);
    }


}


vector_points Figure::smoothing(const vector_points &points)
{
    return points;
    vector_points smooth_figure = points;
    if (points.size() == 1 || points.size() == 0)
        return points;
    //сглаживание калмана
    double coef_kalman = 0.15; //15
    int x_smooth_past = coef_kalman * points[0].first + (1 - coef_kalman) ;
    x_smooth_past = points[0].first;
    int y_smooth_past = coef_kalman * points[0].second + (1 - coef_kalman);
    y_smooth_past = points[0].second;
    for (int i = 0; i < points.size()-1; i++)
    {
        QPair<int, int> smoothValue;
        int x_smooth = coef_kalman * points[i+1].first + (1 - coef_kalman) * x_smooth_past;
        int y_smooth = coef_kalman * points[i+1].second + (1-coef_kalman) * y_smooth_past;
        smoothValue.first = x_smooth;
        smoothValue.second = y_smooth;
        x_smooth_past = x_smooth;
        y_smooth_past = y_smooth;
        smooth_figure[i] = smoothValue;
    }
    return smooth_figure;
}


void Figure::stateMachine(int signal)
{

//    //сверхну вниз слева направо
//    if (this->directionBegin.first == 0 && this->directionBegin.second == 2)
//    {
//        ;
//    }
//    //сверху вниз справо налево
//    if (this->directionBegin.first == 0 && this->directionBegin.second == 3)
//    {
//        ;
//    }
//    //снизу вверх слева напрво
//    if (this->directionBegin.first == 1 && this->directionBegin.second == 2)
//    {
//        ;
//    }
//    //снизу вверх справо налево
//    if (this->directionBegin.first == 1 && this->directionBegin.second == 3)
//    {
//        ;
//    }
}

QPair<int, int> Figure::recognitionDirection(const QVector<QPair<int, int> > &points)
{
    int up_down = -1;
    int right_left = -1;
    QPair<int, int> temp1 = points[0];
    QPair<int, int> temp2 = points[1];
    QPair<int, int> directionBegin;
    if (temp1.second > temp2.second)
        up_down = 0;
    else {
        up_down = 1;
    }
    if (temp1.first > temp2.first)
        right_left = 3;
    else {
        right_left = 2;
    }
    directionBegin.first = up_down;
    directionBegin.second = right_left;
    return directionBegin;
}
