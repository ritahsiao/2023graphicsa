///week11-2_keyboard_wav_PlaySound
#include <windows.h>
#include <GL/glut.h>

void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{///���ѷs�Ъ�    ������,���ε�����|,�n�p�ߦ]��\\�N��1�Ӥϱ׽u
    if(key=='1') PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\do.wav",NULL,SND_ASYNC);
    if(key=='2') PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\re.wav",NULL,SND_ASYNC);
    if(key=='3') PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\mi.wav",NULL,SND_ASYNC);
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
