#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct picturePos{
    int x;
    int y;
    int width=110;
    int height=150;
    QString backgruond = "C:/Users/Sona/Desktop/memory_game/pictures/background";
    QString ownPic;
    bool clicked = false;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    QVector<int> indexes;
    void randomPathIndex();
    void handelRestart();
    void randomInitilize();
    int index;

public slots:
    void onTimerTimeout();

private:
    Ui::MainWindow *ui;
    int picsAmount = 16;
    picturePos* pics;
    int prevIndex=0;
    bool firstClick=true;
    QString donePic = "C:/Users/Sona/Desktop/memory_game/pictures/done";
    QString tempBackground = "C:/Users/Sona/Desktop/memory_game/pictures/background";
    QVector<QString> paths{
        "C:/Users/Sona/Desktop/memory_game/pictures/casillas",
        "C:/Users/Sona/Desktop/memory_game/pictures/david_vila",
        "C:/Users/Sona/Desktop/memory_game/pictures/kroos",
        "C:/Users/Sona/Desktop/memory_game/pictures/messi",
        "C:/Users/Sona/Desktop/memory_game/pictures/neymar",
        "C:/Users/Sona/Desktop/memory_game/pictures/pele",
        "C:/Users/Sona/Desktop/memory_game/pictures/ronaldinio",
        "C:/Users/Sona/Desktop/memory_game/pictures/ronaldo",
        "C:/Users/Sona/Desktop/memory_game/pictures/casillas",
        "C:/Users/Sona/Desktop/memory_game/pictures/david_vila",
        "C:/Users/Sona/Desktop/memory_game/pictures/kroos",
        "C:/Users/Sona/Desktop/memory_game/pictures/messi",
        "C:/Users/Sona/Desktop/memory_game/pictures/neymar",
        "C:/Users/Sona/Desktop/memory_game/pictures/pele",
        "C:/Users/Sona/Desktop/memory_game/pictures/ronaldinio",
        "C:/Users/Sona/Desktop/memory_game/pictures/ronaldo"
        };
    QTimer* timer;
    QPushButton* restart;
    QLabel* titel;
};
#endif // MAINWINDOW_H
