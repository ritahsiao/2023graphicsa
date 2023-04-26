///week11-1_keyboard
#include <GL/glut.h>

void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{///今天新教的
    if(key==27) exit(0);///學習來自GLUT專案的範例
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///今天新教的

    glutMainLoop();
}
