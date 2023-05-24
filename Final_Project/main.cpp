///要用keyboard mouse來控制茶壺,可存檔,可自己動
///int angle[20];angle[0] angle[1]...用它們來旋轉
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head =NULL;///week13 step02-1
GLMmodel * body =NULL;
GLMmodel * uparmR =NULL;
GLMmodel * lowarmR =NULL;
int show[4]={1,1,1,1};///week14_step03-1
int ID=3;///0:頭 1:身體 2:上手臂 3:下手臂///week14_step03-1
FILE * fout = NULL;///一開始,檔案沒有開 NULL
FILE * fin = NULL;///要讀檔用的指標,一開始也是NULL
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
    ///if(key=='0') show[0] = !show[0];///!是將1變0,0變1
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}///將原本的keyboard函式先註解掉

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
            ///glmUnitize(body);///這之後還會更改
        }
        if(ID==0) glColor3f(1,0,0);///選定的,紅色
        else glColor3f(1,1,1);///沒選定,白色
        if(show[0]) glmDraw(head,GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);///選定的,紅色
        else glColor3f(1,1,1);///沒選定,白色
        if(show[1]) glmDraw(body,GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(-1.426666, +0.320000, 0);///week14_step03-1
            glRotatef(angle[2], 0, 0, 1);///week15_step03_1改用陣列
            ///glTranslatef(teapotX, teapotY, 0);///week14_step03-1
            glTranslatef(1.426666, -0.320000, 0);///week14_step03-1

            if(ID==2) glColor3f(1,0,0);///選定的,紅色
            else glColor3f(1,1,1);///沒選定,白色
            if(show[2]) glmDraw(uparmR,GLM_MATERIAL);
            glPushMatrix();
                glTranslatef(-1.939999, +0.186667, 0);///week14_step03-1
                glRotatef(angle[3], 0, 0, 1);///week15_step03_1改用陣列
                //glTranslatef(teapotX, teapotY, 0);///week14_step03-1
                glTranslatef(1.939999, -0.186667, 0);///week14_step03-1

            if(ID==3) glColor3f(1,0,0);///選定的,紅色
            else glColor3f(1,1,1);///沒選定,白色
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
        ///if(fout==NULL) fout=fopen("file4.txt","w");///沒開檔就開檔
        ///fprintf(fout,"%f %f\n",teapotX, teapotY);///要再存座標
    }
    display();
}
//void keyboard(unsigned char key, int x, int y)
//{
//    if(fin==NULL)///如果檔案還沒fopen(),就開它
//    {
//        fclose(fout);///要關掉前面mouse開的fout指標
//        fin = fopen("file4.txt","r");///沒開檔就開檔
//    }
//    fscanf(fin, "%f %f",&teapotX, &teapotY);///讀檔
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
    glutKeyboardFunc(keyboard);///keyboard要開檔,讀檔

    glutMainLoop();
}
