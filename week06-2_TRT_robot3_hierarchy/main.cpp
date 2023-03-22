///week06-2_TRT_robot3
///改自week06-1
///很多不同的連結狀況,而且手臂會帶手肘轉動
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidSphere(0.02,30,30);///正中心的圓球

    glutSolidTeapot(0.3);///step02-1身體

    glPushMatrix();///右手臂
        glTranslatef(0.49,0.13,0);///step02-2新的
        glRotatef(angle,0,0,1);///(2)就可以轉動
        glTranslatef(0.46,-0.05,0);///(1)把旋轉的中心,放中心
        glutSolidTeapot(0.3);

        glPushMatrix();///右手肘
            glTranslatef(0.49,0.13,0);///step02-2新的
            glRotatef(angle,0,0,1);///(2)就可以轉動
            glTranslatef(0.46,-0.05,0);///(1)把旋轉的中心,放中心
            glutSolidTeapot(0.3);
        glPopMatrix();
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
