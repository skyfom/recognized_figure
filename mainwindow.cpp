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
    connect(scene, SIGNAL(releaseMouseSignal(QVector<QPair<int, int>>&)), this, SLOT(releaseMouseSlot(QVector<QPair<int, int>>&)));
    timer->start(100);
}

void MainWindow::pressMouseSlot(QVector<QPair<int, int>>& points)
{
    scene->clear();
    points.clear();
}

void MainWindow::releaseMouseSlot(QVector<QPair<int, int>>& points)
{
    qDebug() << points;
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
