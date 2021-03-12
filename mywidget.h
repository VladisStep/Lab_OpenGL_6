#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QOpenGLWidget>

class myWidget : public QOpenGLWidget
{
    Q_OBJECT



public:
    float xAlpha = 0.0;
    float yAlpha = 0.0;
    float zAlpha = -8.0;

    float cam_x = 0.0;
    float cam_y = 0.0;
    float cam_z = -8.0;


     myWidget(QWidget *parent = nullptr);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void MoveCamera();
    void Turn();
};

#endif // MYWIDGET_H
