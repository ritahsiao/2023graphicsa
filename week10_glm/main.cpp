 #include <GL/glut.h>
 #include "glm.h"///下載source有glm.h放在week10_glm目錄內
 ///glm.c改名為cpp檔放回week10_glm目錄裡
 GLMmodel * pmodel = NULL;///有一個模型的指標 原先是空的
 void  display()
 {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL)
    {
        pmodel = glmReadOBJ("al.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90);
    }
    glmDraw(pmodel,GLM_MATERIAL);
    ///glutSolidTeapot( 0.3 );
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow("week10");

        glutDisplayFunc(display);
        glutMainLoop();
    }
