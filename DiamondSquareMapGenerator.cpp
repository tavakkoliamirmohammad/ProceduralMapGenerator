#include <cstdlib>
#include <ctime>
#include "GL/glut.h"
#include "DiamondSquareMapGenerator.h"
#include "iostream"

using namespace std;

DiamondSquareMapGenerator::DiamondSquareMapGenerator(double **array, int s) {
    map = array;
    size = s;
    range = 8;
}

double **DiamondSquareMapGenerator::process() {
    _on_start();

    //Processing...
    for (int sideLength = size - 1; sideLength >= 2; sideLength /= 2, range /= 2) {
        int halfSide = sideLength / 2;

        squareStep(sideLength, halfSide);
        diamondStep(sideLength, halfSide);
    }

    return map;
}

void DiamondSquareMapGenerator::diamondStep(int sideLength, int halfSide) {
    for (int x = 0; x < size - 1; x += halfSide) {
        for (int y = (x + halfSide) % sideLength; y < size - 1; y += sideLength) {
            double avg = map[(x - halfSide + size - 1) % (size - 1)][y] +
                         map[(x + halfSide) % (size - 1)][y] +
                         map[x][(y + halfSide) % (size - 1)] +
                         map[x][(y - halfSide + size - 1) % (size - 1)];
            avg /= 4.0 + dRand(-range, range);
            map[x][y] = avg;

            if (x == 0) map[size - 1][y] = avg;
            if (y == 0) map[x][size - 1] = avg;
        }
    }
}

void DiamondSquareMapGenerator::squareStep(int sideLength, int halfSide) {
    for (int x = 0; x < size - 1; x += sideLength) {
        for (int y = 0; y < size - 1; y += sideLength) {
            double avg =
                    map[x][y] + map[x + sideLength][y] + map[x][y + sideLength] + map[x + sideLength][y + sideLength];
            avg /= 4.0;
            map[x + halfSide][y + halfSide] = avg + dRand(-range, range);
        }
    }
}

void DiamondSquareMapGenerator::_on_start() {
    // Defining the corners values :
    map[0][0] = map[0][size - 1] = map[size - 1][0] = map[size - 1][size - 1] = 100;
    // Initializing srand for random values :
    srand(time(nullptr));
}


double DiamondSquareMapGenerator::dRand(double dMin, double dMax) {
    double d = (double) rand() / RAND_MAX;
    return dMin + d * (dMax - dMin);
}

void DiamondSquareMapGenerator::renderMap() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    double maxNumber = -1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            maxNumber = max(maxNumber, map[i][j]);
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            glPushMatrix();
            glTranslatef(j / float(size), i / float(size), 0);
            glBegin(GL_POLYGON);

            float color = abs(map[i][j] / 255.0);
            glColor3f(color, color, color);
            glVertex3f(0, 0, 0);
            glVertex3f(1.0 / size, 0, 0);
            glVertex3f(1.0 / size, 1.0 / size, 0);
            glVertex3f(0, 1.0 / size, 0);
            glEnd();
            glPopMatrix();
        }
        cout << endl;
    }

}
