 ///week14-2_timer_play
#include <GL/glut.h>
float angle=0,oldAngle=0,newAngle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t)
{
    if(t<100) glutTimerFunc(50,timer,t+1);///在100之內 設定
    float alpha =t/100.0;
    angle=newAngle*alpha+(1-alpha)*oldAngle;///alpha介於0.00~1.00之間
    glutPostRedisplay();///重新畫畫面
}
void motion(int x,int y)
{
    angle=x;///即時更新角度
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN) oldAngle=x;///按下去
    if(state==GLUT_UP) newAngle=x;///放開來
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)///按任意建,就會播放動畫
{
    glutTimerFunc(0,timer,0);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);///用keyboard()
    ///glutTimerFunc(2000,timer,0);///設定timer格式

    glutMainLoop();
}
