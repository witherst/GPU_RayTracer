// GPU_RayTracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "vector.h"

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

int main()
{
    ofstream imgFile;
    imgFile.open("test.ppm");

    imgFile << "P3\n" << SIZEX << " " << SIZEY << "\n255\n";
    for (int j = SIZEY - 1; j >= 0; j--) {
        for (int i = 0; i < SIZEX; i++) {
            vec3 col(float(i) / float(SIZEX), float(j) / float(SIZEY), 0.2);

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            imgFile << ir << " " << ig << " " << ib << "\n";
        }
    }
}
