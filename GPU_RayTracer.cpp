// GPU_RayTracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// OMP for performance tests
#pragma omp
#include <omp.h>
#define PERF 0

// Regular include files
#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include "vector.h"
#include "ray.h"
#include "sphere.h"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

#ifndef SIZEX
#define SIZEX 600
#endif

#ifndef SIZEY
#define SIZEY 300
#endif

unsigned char *pixels, *pptr;

void display(void)
{
    glDrawPixels(SIZEX, SIZEY, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    // Setup glut args
    glutInit(&argc, argv);
    glutInitWindowSize(SIZEX, SIZEY);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("glDrawPixels example");
    glutDisplayFunc(display);
    
    // Pixels to be drawn to opengl display window
    pixels = (unsigned char*)malloc(SIZEX * SIZEY * 3);
    pptr = pixels;

    // Raytracer window
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    // Define spheres to be drawn
    Sphere *spheres = new Sphere[1];
    spheres[0].setP(0, 0, -1);
    spheres[0].setRadius(.5);
    spheres[0].setColor(1, 0, 0);

    // OpenMP performance vars
    double startTime, endTime;
    int numloops = 1;
    if (PERF) { 
        startTime = omp_get_wtime();
        numloops = 100;
    } 

    for (int k = 0; k < numloops; k++) {
        // Reset pointer to pixel array (only useful if we're doing performance evaluations)
        pptr = pixels;

//      for (j = SIZEY - 1; j >= 0; j--) {    
        for (int j = 0; j < SIZEY; j++) {               // OpenGL flips the Y direction. So need to do it this way for OpenGL display.
            for (int i = 0; i < SIZEX; i++) {
                float u = float(i) / float(SIZEX);
                float v = float(j) / float(SIZEY);

                ray r(origin, lower_left_corner + u * horizontal + v * vertical);

                vec3 col = color(r, spheres);
                int ir = int(255.99 * col[0]);
                int ig = int(255.99 * col[1]);
                int ib = int(255.99 * col[2]);

                *pptr++ = ir;    /* red */
                *pptr++ = ig;    /* green */
                *pptr++ = ib;    /* blue */
            }
        }
    }
    if (PERF) {
        endTime = omp_get_wtime();
//        cout << "Performance: " << (double)numloops / (endTime - startTime) / 1000000.;
        cout << "Performance: " << (endTime - startTime);
    }


    // Display final results
    glutMainLoop(); 
    return 0;
}

//int main(int argc, char** argv)
//{
//    ofstream imgFile;
//    imgFile.open("test.ppm");
//
//    vec3 lower_left_corner(-2.0, -1.0, -1.0);
//    vec3 horizontal(4.0, 0.0, 0.0);
//    vec3 vertical(0.0, 2.0, 0.0);
//    vec3 origin(0.0, 0.0, 0.0);
//
//    imgFile << "P3\n" << SIZEX << " " << SIZEY << "\n255\n";
//    for (int j = SIZEY - 1; j >= 0; j--) {
//        for (int i = 0; i < SIZEX; i++) {
//                
//            float u = float(i) / float(SIZEX);
//            float v = float(j) / float(SIZEY);
//
//            ray r(origin, lower_left_corner + u * horizontal + v * vertical);
//
//            vec3 col = color(r);
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