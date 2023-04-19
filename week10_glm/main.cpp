 #include <GL/glut.h>
 #include "glm.h"///�U��source��glm.h��bweek10_glm�ؿ���
 ///glm.c��W��cpp�ɩ�^week10_glm�ؿ���
 GLMmodel * pmodel = NULL;///���@�Ӽҫ������� ����O�Ū�
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
