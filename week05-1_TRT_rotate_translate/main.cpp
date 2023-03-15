///week05-1_TRT_rotate_translate
///把上週week04-1拿來用
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景

    glColor3f(0,1,0);///綠色的
    glPushMatrix();
        glTranslatef(0.8,0,0);///最後是綠色的移動
        glRotated( angle, 0, 0, 1);///改對z軸轉
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glColor3f(1,0,0);///紅色的
    glPushMatrix();
        glRotated( angle, 0, 0, 1);///改對z軸轉///最後是紅色的轉動
        glTranslatef(0.8,0,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
