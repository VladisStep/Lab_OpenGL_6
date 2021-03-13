#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QOpenGLWidget>

class myWidget : public QOpenGLWidget
{
    Q_OBJECT



public:
    float xAlpha = 335.0;
    float yAlpha = 33.0;
    float zAlpha = 0.0;

    float cam_x = -4.1;
    float cam_y = -1.7;
    float cam_z = -5.3;

    int fig_xAlpha = 0.0;
    int fig_yAlpha = 0.0;
    int fig_zAlpha = 0.0;

    int fineness = 5; // melkost' razbieniya

    float test = 100;


     myWidget(QWidget *parent = nullptr);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void MoveCamera();
    void Turn();

    void ShowWorld();
};

#endif // MYWIDGET_H
