#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QKeyEvent>
#include <QDebug>
#include <QPainter>
using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyVideoCapture;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
    MyVideoCapture *mOpenCV_videoCapture;
    void paintEvent(QPaintEvent *event);
    QPixmap video_pixmap;
};
#endif // MAINWINDOW_H
