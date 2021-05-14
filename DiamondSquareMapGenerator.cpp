#include <cstdlib>
#include "DiamondSquareMapGenerator.h"

using namespace std;

DiamondSquareMapGenerator::DiamondSquareMapGenerator(double **array, int s) {
    map = array;
    size = s;
    range = 8;
}

double **DiamondSquareMapGenerator::process() {
    map[0][0] = map[0][size - 1] = map[size - 1][0] = map[size - 1][size - 1] = 100;

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



double DiamondSquareMapGenerator::dRand(double dMin, double dMax) {
    double d = (double) rand() / RAND_MAX;
    return dMin + d * (dMax - dMin);
}