#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include "figure.h"
#include <paintscene.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintFigure(const QVector<QPair<int, int>>&);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Figure *fig;

    PaintScene *scene;
    void resizeEvent(QResizeEvent * event);
private slots:
    void pressMouseSlot(QVector<QPair<int, int>>&);
    void releaseMouseSlot(const QVector<QPair<int, int>>&);
    void slotTimer();
};

#endif // MAINWINDOW_H
