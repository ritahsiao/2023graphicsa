///week04-3_rotate_translate
#include <GL/glut.h>
float angle=0;///step02-1�ŧiglobal �����ܼ�(���b�禡���Y)angle
void display()
{
    glEnable(GL_DEPTH_TEST);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��,�ݼv
    glPushMatrix();///�ƥ��x�}
        glTranslatef(0.6,0,0);
        glRotated( angle, 0, 1, 0);///����angle����
        glColor3f(1,1,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();///step02-1�٭�x�}
    glPushMatrix();///step02-1�ƥ��x�}
        glRotated( angle, 0, 1, 0);///����angle����
        glTranslatef(0.6,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
    angle++;///�⨤��++
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display);///����idle��,�N���e�e��
    glutMainLoop();
}
