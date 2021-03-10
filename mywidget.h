#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QOpenGLWidget>

class myWidget : public QOpenGLWidget
{
    Q_OBJECT



public:
    float xAlpha = 0.0;
    float zAlpha = 0.0;


     myWidget(QWidget *parent = nullptr);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void MoveCamera();
    void Turn();
};

#endif // MYWIDGET_H
