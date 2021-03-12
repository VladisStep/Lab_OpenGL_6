#include "mywidget.h"
#include "math.h"



void ShowWorld(){

//    float vert[] = {1,1,0, 1,-1,0, -1,-1,0, -1,1,0};

//    glEnableClientState(GL_VERTEX_ARRAY);
//        glVertexPointer(3, GL_FLOAT, 0, &vert);
//        glColor3f(0, 0.5, 0);
//        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//    glDisableClientState(GL_VERTEX_ARRAY);


    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
        glVertex3d(-2,0,0);
        glVertex3d(2,0,0);
    glColor3f(0, 1, 0);
        glVertex3d(0,-2,0);
        glVertex3d(0,2,0);
    glColor3f(0, 0, 1);
        glVertex3d(0,0,-2);
        glVertex3d(0,0,2);
    glEnd();




    double slim = 1.0;


    glPointSize(10);
    glColor3f(1, 1, 1);

    double r = 0.5;

    // kryg dlya vinta
//    for (double i = 0.0; i < 2*M_PI; i += M_PI/20){
//        glBegin(GL_LINE_LOOP);
//            glVertex3d(r*cos(i)/slim, r*sin(i)/slim, -0.25/slim);
//            glVertex3d(r*cos(i+M_PI/10)/slim, r*sin(i+M_PI/10)/slim, -0.25/slim);
//            glVertex3d(r*cos(i+M_PI/10)/slim, r*sin(i+M_PI/10)/slim, 0.25/slim);
//            glVertex3d(r*cos(i)/slim, r*sin(i)/slim, 0.25/slim);
//        glEnd();
//    }



    // lopasty
//    for (int i = 0; i < 7; i++){
//        glRotatef(360/7, 0,0,1);
//        for (double a = 0.0; a < 2.0; a += 0.1){
//            glBegin(GL_LINE_LOOP);
//    //            glVertex3d(cos(a/3)-0.5,a,cos(a*0.8+0.0)*0.5-0.3);
//    //            glVertex3d(-cos(a/3)+0.5,a,-cos(a*0.8+0.0)*0.5+0.3);
//    //            glVertex3d(-cos((a+0.1)/3)+0.5,(a+0.1),-cos((a+0.1)*0.8+0.0)*0.5+0.3);
//    //            glVertex3d(cos((a+0.1)/3)-0.5,(a+0.1),cos((a+0.1)*0.8+0.0)*0.5-0.3);
//                  glVertex3d(0,a+r,cos(a*0.8+1.3)*0.5-0.3);
//                  glVertex3d(0,a+r,-cos(a*0.8+1.3)*0.5+0.3);
//                  glVertex3d(0,(a+0.1)+r,-cos((a+0.1)*0.8+1.3)*0.5+0.3);
//                  glVertex3d(0,(a+0.1)+r,cos((a+0.1)*0.8+1.3)*0.5-0.3);

//            glEnd();
//        }
//    }


// paraboloid
    for (double a = 1.0; a >= 0.0; a -= 0.01){
        for (double i = 0.0; i < 2*M_PI; i += M_PI/20){


            glBegin(GL_LINE_LOOP);


                glVertex3d(a*cos(i)/slim, -a*a+2, a*sin(i)/slim);
                glVertex3d(a*cos(i+M_PI/10)/slim, -a*a+2 , a*sin(i+M_PI/10)/slim);

                double nextA =  a + 0.1;
                glVertex3d(nextA*cos(i+M_PI/10)/slim, -nextA*nextA+2 , nextA*sin(i+M_PI/10)/slim);
                glVertex3d(nextA*cos(i)/slim, -nextA*nextA+2, nextA*sin(i)/slim);


            glEnd();

        }
    }






}

void myWidget::MoveCamera(){
    glRotatef(-xAlpha, 1,0,0);
    glRotatef(-yAlpha, 0,1,0);
    glRotated(-zAlpha, 0,0,1);
    glTranslatef(cam_x,cam_y,cam_z);


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

