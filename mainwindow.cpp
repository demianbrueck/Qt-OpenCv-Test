#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myvideocapture.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mOpenCV_videoCapture = new MyVideoCapture(this);

    connect(mOpenCV_videoCapture, &MyVideoCapture::newPixmapCaptured,this,[&](){
        video_pixmap = mOpenCV_videoCapture->pixmap();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    mOpenCV_videoCapture->terminate();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< "test";
    mOpenCV_videoCapture->start(QThread::HighestPriority);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);

    painter.drawPixmap(50,50,50,50,video_pixmap);
}

