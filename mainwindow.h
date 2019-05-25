#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    PaintScene *scene;
    void resizeEvent(QResizeEvent * event);
private slots:
    void pressMouseSlot(QVector<QPair<int, int>>&);
    void releaseMouseSlot(QVector<QPair<int, int>>&);
    void slotTimer();
};

#endif // MAINWINDOW_H
