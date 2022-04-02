#include <iostream>
#include "C:\SRC\vcpkg\packages\freeglut_x64-windows\include\GL\glut.h"

int main(int argc, char** argv)
{
    void RenderSceneCB();
    void glutInit(int* argcp, char** argv);

    glutInit(&argc, argv);

    glutCreateWindow("Tutorial 01");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1024, 768);
    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();

    return 0;
}

void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}