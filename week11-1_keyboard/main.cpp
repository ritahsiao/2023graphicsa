///week11-1_keyboard
#include <GL/glut.h>

void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{///���ѷs�Ъ�
    if(key==27) exit(0);///�ǲߨӦ�GLUT�M�ת��d��
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///���ѷs�Ъ�

    glutMainLoop();
}
