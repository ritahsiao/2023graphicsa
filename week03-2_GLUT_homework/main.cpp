#include <GL/glut.h>
#include <stdio.h>
void display()
{
    ///glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景,殘影
    ///glPushMatrix();///備份的矩陣
        ///glTranslated( X, Y, 0);
        ///glutSolidTeapot( 0.3 );
    glBegin(GL_POLYGON);
        glVertex2f(-0.208, 0.148);
        glVertex2f(-0.244, 0.092);
        glVertex2f(-0.272, 0.012);
        glVertex2f(-0.304, -0.116);
        glVertex2f(-0.228, -0.220);
        glVertex2f(-0.100, -0.232);
        glVertex2f(0.048, -0.232);
        glVertex2f(0.196, -0.228);
        glVertex2f(0.268, -0.168);
        glVertex2f(0.296, -0.088);
        glVertex2f(0.280, 0.016);
        glVertex2f(0.244, 0.072);
        glVertex2f(0.176, 0.152);
        glVertex2f(0.052, 0.164);
        glVertex2f(-0.112, 0.152);
     glEnd();

     glBegin(GL_POLYGON);
        glVertex2f(-0.204, 0.152);
        glVertex2f(-0.212, 0.196);
        glVertex2f(-0.228, 0.248);
        glVertex2f(-0.236, 0.340);
        glVertex2f(-0.224, 0.416);
        glVertex2f(-0.168, 0.428);
        glVertex2f(-0.140, 0.376);
        glVertex2f(-0.140, 0.300);
        glVertex2f(-0.132, 0.232);
        glVertex2f(-0.132, 0.184);
        glVertex2f(-0.124, 0.160);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.084, 0.164);
        glVertex2f(0.084, 0.216);
        glVertex2f(0.076, 0.260);
        glVertex2f(0.076, 0.332);
        glVertex2f(0.084, 0.404);
        glVertex2f(0.104, 0.428);
        glVertex2f(0.140, 0.432);
        glVertex2f(0.176, 0.424);
        glVertex2f(0.180, 0.368);
        glVertex2f(0.184, 0.304);
        glVertex2f(0.188, 0.244);
        glVertex2f(0.176, 0.208);
        glVertex2f(0.160, 0.164);
        glVertex2f(0.160, 0.160);
    glEnd();

    ///glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{///請mouse函式幫忙
    float X= (x-250)/250.0;
    float Y= -(y-250)/250.0;///口訣減一半,除一半,y負號
    if(state==GLUT_DOWN){
        printf("    glVertex2f(%.3f, %.3f);\n",X,Y);
    }
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///請mouse函式幫忙

    glutMainLoop();
}
