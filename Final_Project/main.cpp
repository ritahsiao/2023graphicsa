///�n��keyboard mouse�ӱ������,�i�s��,�i�ۤv��
///int angle[20];angle[0] angle[1]...�Υ��̨ӱ���
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head =NULL;///week13 step02-1
GLMmodel * body =NULL;
GLMmodel * uparmR =NULL;
GLMmodel * lowarmR =NULL;
int show[4]={1,1,1,1};///week14_step03-1
int ID=3;///0:�Y 1:���� 2:�W���u 3:�U���u///week14_step03-1
FILE * fout = NULL;///�@�}�l,�ɮרS���} NULL
FILE * fin = NULL;///�nŪ�ɥΪ�����,�@�}�l�]�ONULL
float teapotX=0,teapotY=0;
///float angle=0, angle2=0, angle3=0;
float angle[20]={};///week15_step03_1
void keyboard(unsigned char key,int x ,int y)
{
    if(key=='0') ID = 0;///week14_step02-2
    if(key=='1') ID = 1;///week14_step02-2
    if(key=='2') ID = 2;///week14_step02-2
    if(key=='3') ID = 3;///week14_step02-2
    if(key=='s')
    {
        if (fout==NULL) fout=fopen("motion.txt","w");
        for(int i=0;i<20;i++)///week15_step03_2
        {
            fprintf(fout,"%.2f ",angle[i]);///week15_step03_2
        }
        fprintf(fout,"\n");
    }
    else if(key=='r')
    {
        if (fin==NULL) fin=fopen("motion.txt","r");
        for(int i=0;i<20;i++)///week15_step03_2
        {
            fscanf(fin,"%f",&angle[i]);///week15_step03_2
        }
        glutPostRedisplay();
    }
    ///if(key=='0') show[0] = !show[0];///!�O�N1��0,0��1
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}///�N�쥻��keyboard�禡�����ѱ�

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2, 0.2, 0.2);
        if(body==NULL)
        {
            head=glmReadOBJ("model/head.obj");
            body=glmReadOBJ("model/body.obj");
            uparmR=glmReadOBJ("model/uparmR.obj");
            lowarmR=glmReadOBJ("model/lowarmR.obj");
            ///glmUnitize(body);///�o�����ٷ|���
        }
        if(ID==0) glColor3f(1,0,0);///��w��,����
        else glColor3f(1,1,1);///�S��w,�զ�
        if(show[0]) glmDraw(head,GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);///��w��,����
        else glColor3f(1,1,1);///�S��w,�զ�
        if(show[1]) glmDraw(body,GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(-1.426666, +0.320000, 0);///week14_step03-1
            glRotatef(angle[2], 0, 0, 1);///week15_step03_1��ΰ}�C
            ///glTranslatef(teapotX, teapotY, 0);///week14_step03-1
            glTranslatef(1.426666, -0.320000, 0);///week14_step03-1

            if(ID==2) glColor3f(1,0,0);///��w��,����
            else glColor3f(1,1,1);///�S��w,�զ�
            if(show[2]) glmDraw(uparmR,GLM_MATERIAL);
            glPushMatrix();
                glTranslatef(-1.939999, +0.186667, 0);///week14_step03-1
                glRotatef(angle[3], 0, 0, 1);///week15_step03_1��ΰ}�C
                //glTranslatef(teapotX, teapotY, 0);///week14_step03-1
                glTranslatef(1.939999, -0.186667, 0);///week14_step03-1

            if(ID==3) glColor3f(1,0,0);///��w��,����
            else glColor3f(1,1,1);///�S��w,�զ�
            if(show[3]) glmDraw(lowarmR,GLM_MATERIAL);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glColor3f(0,1,0);///week14_step03-1
    glutSolidTeapot(0.02);///week14_step03-1
    glutSwapBuffers();
}
int oldX=0, oldY=0;
void motion(int x, int y)
{
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    angle[ID]+=(x-oldX);///week15_step03_1
    ///angle= x;
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n",teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN)
    {
        oldX = x;///teapotX = (x-150)/150.0;
        oldY = y;///teapotY = (150-y)/150.0;
        ///angle = x;///week15_step03_1
        ///if(fout==NULL) fout=fopen("file4.txt","w");///�S�}�ɴN�}��
        ///fprintf(fout,"%f %f\n",teapotX, teapotY);///�n�A�s�y��
    }
    display();
}
//void keyboard(unsigned char key, int x, int y)
//{
//    if(fin==NULL)///�p�G�ɮ��٨Sfopen(),�N�}��
//    {
//        fclose(fout);///�n�����e��mouse�}��fout����
//        fin = fopen("file4.txt","r");///�S�}�ɴN�}��
//    }
//    fscanf(fin, "%f %f",&teapotX, &teapotY);///Ū��
//    display();
//}
 int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);///keyboard�n�}��,Ū��

    glutMainLoop();
}
