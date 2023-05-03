///要用keyboard mouse來控制茶壺,可存檔,可自己動
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL;///一開始,檔案沒有開 NULL
FILE * fin = NULL;///要讀檔用的指標,一開始也是NULL
float teapotX=0,teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX,teapotY,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN)
    {
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        if(fout==NULL) fout=fopen("file4.txt","w");///沒開檔就開檔
        fprintf(fout,"%f %f\n",teapotX, teapotY);///要再存座標
    }
    display();
}
void keyboard(unsigned char key, int x, int y)
{
    if(fin==NULL)///如果檔案還沒fopen(),就開它
    {
        fclose(fout);///要關掉前面mouse開的fout指標
        fin = fopen("file4.txt","r");///沒開檔就開檔
    }
    fscanf(fin, "%f %f",&teapotX, &teapotY);///讀檔
    display();
}
 int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);///keyboard要開檔,讀檔

    glutMainLoop();
}
