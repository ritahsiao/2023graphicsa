///week06-1_TRT_robot2
///�ƻs�W�gweek05-2_TRT_robot�K�W
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidSphere(0.02,30,30);///�����ߪ���y
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glTranslatef(0.46,0.05,0);///(1)����઺����,�񤤤�
        glutSolidTeapot(0.3);
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
