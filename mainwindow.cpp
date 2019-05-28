#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new PaintScene();
    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    connect(scene, SIGNAL(pressMouseSignal(QVector<QPair<int, int>>&)), this, SLOT(pressMouseSlot(QVector<QPair<int, int>>&)));
    connect(scene, SIGNAL(releaseMouseSignal(const QVector<QPair<int, int>>&)), this, SLOT(releaseMouseSlot(const QVector<QPair<int, int>>&)));
    timer->start(100);
    fig = new Figure();
}

void MainWindow::paintFigure(const QVector<QPair<int, int> > &points)
{
    scene->clear();
    scene->paintFigure(points);
}

void MainWindow::pressMouseSlot(QVector<QPair<int, int>>& points)
{
    scene->clear();
    points.clear();
    fig = new Figure();
}

void MainWindow::releaseMouseSlot(const QVector<QPair<int, int>>& points)
{
    qDebug() << points;
    QVector<QPair<int, int>> newFig = fig->recognition(points);
    figure type = fig->getTypeFigure();

    QFont font("Times", 14, QFont::Bold);
    ui->isFigure->setFont(font);
    if (type == figure::line)
    {
        ui->isFigure->setText("Линия");
        return;
    }
    else if (type == figure::circle)
        ui->isFigure->setText("Круг");
    else if (type == figure::triangle)
        ui->isFigure->setText("Треугольник");
    else if (type == figure::rectangle)
        ui->isFigure->setText("Прямоугольник");
    scene->paintCircle(newFig);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}
