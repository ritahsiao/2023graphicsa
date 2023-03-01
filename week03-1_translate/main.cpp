#include <GL/glut.h>
float X=0,Y=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景,殘影
    glPushMatrix();///備份的矩陣
        glTranslated( X, Y, 0);
        glutSolidTeapot( 0.3 );

    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
///#include <stdio.h>
void mouse(int button,int state,int x,int y)
{///請mouse函式幫忙
    X= (x-150)/150.0;///printf("%d %d %d %d\n",button,state,x,y);
    Y= -(y-150)/150.0;///button(左右鍵等),state(按下去是0,1)
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///請mouse函式幫忙

    glutMainLoop();
}
