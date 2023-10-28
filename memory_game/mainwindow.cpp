#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPoint>
#include <QEvent>
#include <QPushButton>
#include <QLabel>
#include <QImage>
#include <QMouseEvent>
#include <QtMath>
#include <QRect>
#include <QTimer>
#include <QtGlobal>
#include <QVector>
#include <QTime>
#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    restart = new QPushButton ("Restart",this);
    restart->setGeometry(340,730,200,50);
    connect(restart, &QPushButton::clicked, this, &MainWindow::handelRestart);


    titel = new QLabel("Find the matching pairs!",this);
    titel->setGeometry(40,-20,200,100);

    pics=new picturePos[picsAmount];

    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimerTimeout(){
    if(pics[prevIndex].ownPic==pics[index].ownPic){
        pics[index].backgruond=donePic;
        pics[prevIndex].backgruond=donePic;
        firstClick=true;
    }else{
        pics[prevIndex].backgruond=tempBackground;
        pics[index].backgruond=tempBackground;
        pics[prevIndex].clicked=false;
        pics[index].clicked=false;
        firstClick=true;
    }
    update();
}

void MainWindow::randomPathIndex() {
        QRandomGenerator generator(QTime::currentTime().msec());

        QVector<int> numbers;
        for (int i = 0; i < picsAmount; ++i) {
            numbers.append(i);
        }

        for (int i = 0; i < picsAmount; ++i) {
            int randomIndex = generator.bounded(numbers.size());
            indexes.append(numbers[randomIndex]);
            numbers.removeAt(randomIndex);
        }

}

void MainWindow::randomInitilize(){
    randomPathIndex();
    for(int i=0; i<picsAmount; i++){
        pics[i].ownPic = paths[indexes[i]];
    }
}

void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    for(int i=0; i<qSqrt(picsAmount); i++){
        for(int j=0; j<qSqrt(picsAmount); j++){
            pics[i+j+i*3].x=i*130+40;
            pics[i+j+i*3].y=j*170+60;
        }
    }
    for(int i =0; i<picsAmount; i++){
        QImage mainBackground(pics[i].backgruond);
        QRect rectangle(pics[i].x,pics[i].y,pics[i].width,pics[i].height);
        painter.drawImage(rectangle,mainBackground);
    }
    randomInitilize();
}

void MainWindow::mousePressEvent(QMouseEvent *eventPress)
{
    QPoint pos = eventPress->pos();
    for(int i=0;i<picsAmount;i++){
        if(pos.x()>=pics[i].x && pos.x()<=pics[i].x+pics[i].width && pos.y()>=pics[i].y && pos.y()<=pics[i].y+pics[i].height && !pics[i].clicked){
            pics[i].backgruond = pics[i].ownPic;
            pics[i].clicked=true;

            if(firstClick){
                prevIndex=i;
                firstClick=false;
                continue;
            }

            index=i;
            timer->start(600);
        }
    }
    update();
}

void MainWindow::handelRestart(){
    for(int i=0; i<picsAmount; i++){
        pics[i].backgruond = tempBackground;
        pics[i].clicked = false;
    }
    indexes.clear();
    randomInitilize();
    update();
}
