﻿#include <iostream>
#include "C:\SRC\vcpkg\packages\glew_x64-windows\include\GL\glew.h"
#include "C:\SRC\vcpkg\packages\freeglut_x64-windows\include\GL\glut.h"
#include "math_3d.h"

GLuint VBO;

int main(int argc, char** argv)
{
    void RenderSceneCB();
    void glutInit(int* argcp, char** argv);

    glutInit(&argc, argv);

    glutCreateWindow("Tutorial 01");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1024, 768);
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    Vector3f Vertices[3];
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    glutDisplayFunc(RenderSceneCB);
    glutMainLoop();

    return 0;
}

void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_POINTS, 0, 1);
    glDisableVertexAttribArray(0);
    
    glutSwapBuffers();
}