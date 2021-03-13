#include "mywidget.h"
#include "math.h"
#include <iostream>

void drawParall(double x, double y, double z, double toX, double toY, double toZ){

//   x = 0.1, y = 0, z = -0.3, toX =-0.1, toY = -2, toZ= -0.5


    glBegin(GL_LINE_LOOP);
        glVertex3d(x, y,z);
        glVertex3d(x, y,toZ);
        glVertex3d(x, toY,toZ);
        glVertex3d(x, toY,z);
   glEnd();
   glBegin(GL_LINE_LOOP);
        glVertex3d(toX , y,z);
        glVertex3d(toX , y,toZ);
        glVertex3d(toX , toY,toZ);
        glVertex3d(toX , toY,z);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3d(x, y,z);
        glVertex3d(toX, y,z);
        glVertex3d(toX, toY,z);
        glVertex3d(x, toY,z);
     glEnd();
     glBegin(GL_LINE_LOOP);
         glVertex3d(x, y,toZ);
         glVertex3d(toX , y,toZ);
         glVertex3d(toX , toY,toZ);
         glVertex3d(x, toY,toZ);
      glEnd();
}

void myWidget::ShowWorld(){

    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
        glVertex3d(-5,0,0);
        glVertex3d(5,0,0);
    glColor3f(0, 1, 0);
        glVertex3d(0,-5,0);
        glVertex3d(0,5,0);
    glColor3f(0, 0, 1);
        glVertex3d(0,0,-5);
        glVertex3d(0,0,5);
    glEnd();


   glRotatef(fig_xAlpha, 1,0,0);
   glRotatef(fig_yAlpha, 0,1,0);
   glRotatef(fig_zAlpha, 0,0,1);




    double slim = 2.0;


    glPointSize(10);
    glColor3f(1, 1, 1);

    double r = 0.5;

//    // kryg dlya vinta
    for (double i = 0.0; i < 2*M_PI; i += M_PI/fineness){
        glBegin(GL_LINE_LOOP);
            glVertex3d(r*cos(i)/slim, r*sin(i)/slim, -0.25);
            glVertex3d(r*cos(i+M_PI/10)/slim, r*sin(i+M_PI/fineness)/slim, -0.25);
            glVertex3d(r*cos(i+M_PI/10)/slim, r*sin(i+M_PI/fineness)/slim, 0.25);
            glVertex3d(r*cos(i)/slim, r*sin(i)/slim, 0.25);
        glEnd();
    }



    // lopasty
    for (int i = 0; i < 7; i++){
        glRotatef(360/7, 0,0,1);
        for (double a = 0.0; a < 2.0; a += 0.1){
            glBegin(GL_LINE_LOOP);
    //            glVertex3d(cos(a/3)-0.5,a,cos(a*0.8+0.0)*0.5-0.3);
    //            glVertex3d(-cos(a/3)+0.5,a,-cos(a*0.8+0.0)*0.5+0.3);
    //            glVertex3d(-cos((a+0.1)/3)+0.5,(a+0.1),-cos((a+0.1)*0.8+0.0)*0.5+0.3);
    //            glVertex3d(cos((a+0.1)/3)-0.5,(a+0.1),cos((a+0.1)*0.8+0.0)*0.5-0.3);
                  glVertex3d((sin(a*0.8+1.3)*0.5-0.3-0.182)/slim,(a+r)/slim,
                             (cos(a*0.8+1.3)*0.5-0.3)/slim);
                  glVertex3d((-sin(a*0.8+1.3)*0.5+0.3+0.182)/slim,(a+r)/slim,
                             (-cos(a*0.8+1.3)*0.5+0.3)/slim);
                  glVertex3d((-sin((a+0.1)*0.8+1.3)*0.5+0.3+0.182)/slim,((a+0.1)+r)/slim,
                             (-cos((a+0.1)*0.8+1.3)*0.5+0.3)/slim);
                  glVertex3d((sin((a+0.1)*0.8+1.3)*0.5-0.3-0.182)/slim,((a+0.1)+r)/slim,
                             (cos((a+0.1)*0.8+1.3)*0.5-0.3)/slim);

            glEnd();
        }
    }


    drawParall(0.1, 0, -0.3, -0.1, -2, -0.5);
    drawParall(0.15, -2, -0.25, -0.15, -4, -0.55);

    drawParall(-2, -4.2, -0.3, 2, -4.5, -0.5);
    drawParall(-0.1, -4.2, -2-0.4, 0.1, -4.5, 2-0.4);



    for (double i = 0.0; i < 2*M_PI; i += M_PI/fineness){
        glBegin(GL_LINE_LOOP);
            glVertex3d(r*cos(i), -4, r*sin(i)-0.4);
            glVertex3d(r*cos(i+M_PI/fineness), -4, r*sin(i+M_PI/fineness)-0.4);
            glVertex3d(r*cos(i+M_PI/fineness), -4.5, r*sin(i+M_PI/fineness)-0.4);
            glVertex3d(r*cos(i), -4.5, r*sin(i)-0.4);
        glEnd();
    }








// paraboloid
    for (double a = 0.4; a > 0.0; a -= 0.1){
        for (double i = 0.0; i < 2*M_PI; i += M_PI/fineness){
            glBegin(GL_LINE_LOOP);
                glVertex3d(a*cos(i)/slim, a*sin(i)/slim, -(-a*a+2)*3+5);
                glVertex3d(a*cos(i+M_PI/fineness)/slim, a*sin(i+M_PI/fineness)/slim, -(-a*a+2)*3+5);
                double nextA =  a + 0.1;
                glVertex3d(nextA*cos(i+M_PI/fineness)/slim , nextA*sin(i+M_PI/fineness)/slim, -(-nextA*nextA+2)*3+5);
                glVertex3d(nextA*cos(i)/slim, nextA*sin(i)/slim, -(-nextA*nextA+2)*3+5);
            glEnd();
        }
    }

}

void myWidget::MoveCamera(){

    glRotatef(-xAlpha, 1,0,0);
    glRotatef(-yAlpha, 0,1,0);
    glRotated(-zAlpha, 0,0,1);
    glTranslatef(cam_x,cam_y,cam_z);


    std::cout << "xAlpha: " << xAlpha << " yAlpha: " << yAlpha << " zAlpha: " << zAlpha << std::endl;
    std::cout << "cam_x: " << cam_x <<" cam_y: " << cam_y <<" cam_z: " << cam_z << std::endl;

}





myWidget::myWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

void myWidget::initializeGL(){
    glFrustum(-1,1, -1,1, 2,50);
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

