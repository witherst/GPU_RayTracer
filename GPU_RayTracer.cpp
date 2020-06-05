// GPU_RayTracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "vector.h"
#include <GL/glut.h>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

#ifndef SIZEX
#define SIZEX 200
#endif

#ifndef SIZEY
#define SIZEY 100
#endif

//int main(int argc, char** argv)
//{
//    ofstream imgFile;
//    imgFile.open("test.ppm");
//
//    imgFile << "P3\n" << SIZEX << " " << SIZEY << "\n255\n";
//    for (int j = SIZEY - 1; j >= 0; j--) {
//        for (int i = 0; i < SIZEX; i++) {
//            vec3 col(float(i) / float(SIZEX), float(j) / float(SIZEY), 0.2);
//
//            int ir = int(255.99 * col[0]);
//            int ig = int(255.99 * col[1]);
//            int ib = int(255.99 * col[2]);
//
//            imgFile << ir << " " << ig << " " << ib << "\n";
//        }
//    }
//
//    return 0;
//
//}

unsigned char* pixels, * pptr;

void display(void)
{
    glDrawPixels(SIZEX, SIZEY, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    int i, j;
    glutInit(&argc, argv);
    glutInitWindowSize(SIZEX, SIZEY);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("glDrawPixels example");

    glutDisplayFunc(display);

    pixels = pptr = (unsigned char*)malloc(SIZEX * SIZEY * 3);
    for (j = SIZEY - 1; j >= 0; j--) {
        for (i = 0; i < SIZEX; i++) {
            vec3 col(float(i) / float(SIZEX), float(j) / float(SIZEY), 0.2);

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            cout << *pptr << " ";

            *pptr++ = ir; // (i ^ j) >> 2;  /* red */
            *pptr++ = ig; // (i ^ j) >> 1;  /* green */
            *pptr++ = ib; // (i ^ j);       /* blue */
        }
    }
    glutMainLoop();
    return 0;
}