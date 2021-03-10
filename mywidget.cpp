#include "mywidget.h"
#include "math.h"



void ShowWorld(){

//    float vert[] = {1,1,0, 1,-1,0, -1,-1,0, -1,1,0};

//    glEnableClientState(GL_VERTEX_ARRAY);
//        glVertexPointer(3, GL_FLOAT, 0, &vert);
//        glColor3f(0, 0.5, 0);
//        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//    glDisableClientState(GL_VERTEX_ARRAY);


    double slim = 1.0;


    glPointSize(10);
    glColor3f(1, 0, 0);

    for (double i = 0.0; i < 2*M_PI; i += M_PI/10){
        glBegin(GL_LINE_LOOP);
            glVertex3d(cos(i)/slim, sin(i)/slim, 0);
            glVertex3d(cos(i+M_PI/10)/slim, sin(i+M_PI/10)/slim, 0);
            glVertex3d(cos(i+M_PI/10)/slim, sin(i+M_PI/10)/slim, 0.5/slim);
            glVertex3d(cos(i)/slim, sin(i)/slim, 0.5/slim);
        glEnd();
    }

    double x = 0.0;
    double y = 0.0;

//    for (double a = 0.503; a < 1.0; a += 0.01){
//        glBegin(GL_LINE_LOOP);
//            glVertex3d(a,asin(a-1.5)*2.0+3.0,0);
//            glVertex3d(a+0.01,asin(a+0.01-1.5)*2.0+3.0,0);
//            glVertex3d(-a-0.01,-asin(-a-0.01+1.5)*2.0+3.0,0);
//            glVertex3d(-a,-asin(-a+1.5)*2.0+3.0,0);
//        glEnd();
//    }





}

void myWidget::MoveCamera(){
    glRotatef(-xAlpha, 1,0,0);
//    glRotatef(-20, 0,1,0);
    glRotated(-zAlpha, 0,0,1);
    glTranslatef(0,0,-8);


}




myWidget::myWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

void myWidget::initializeGL(){
    glFrustum(-1,1, -1,1, 2,8);
    paintGL();
}
void myWidget::paintGL(){

    glPushMatrix();
        MoveCamera();
        ShowWorld();
    glPopMatrix();
}
void myWidget::resizeGL(int w, int h){
//    glViewport(0,0,w,h);
}

