///week05-1_TRT_robot 使用week05-1的程式
///畫出大的身體、手臂
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景

    glColor3f(0,1,0);///綠色的身體
    glPushMatrix();
        glutSolidCube(0.5);

        glPushMatrix();
            glTranslatef(0.25,0.25,0);///(3)把整個東西掛在右上角
            glRotated(angle,0,0,1);///(2)轉動
            glTranslatef(0.25,0.25,0);///(1)把旋轉中心放到中心
            ///glTranslatef(0.5,0.5,0);///step03-3先註解掉
            glColor3f(1,0,0);///紅色的手臂
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++;///角度++
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
