///week04-3_rotate_translate
#include <GL/glut.h>
float angle=0;///step02-1宣告global 全域變數(不在函式裡頭)angle
void display()
{
    glEnable(GL_DEPTH_TEST);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景,殘影
    glPushMatrix();///備份矩陣
        glTranslatef(0.6,0,0);
        glRotated( angle, 0, 1, 0);///旋轉angle角度
        glColor3f(1,1,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();///step02-1還原矩陣
    glPushMatrix();///step02-1備份矩陣
        glRotated( angle, 0, 1, 0);///旋轉angle角度
        glTranslatef(0.6,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
    angle++;///把角度++
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display);///有空idle時,就重畫畫面
    glutMainLoop();
}
