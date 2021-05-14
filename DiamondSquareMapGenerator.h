#ifndef MAP_GENERATION_DIAMONDSQUAREMAPGENERATOR_H
#define MAP_GENERATION_DIAMONDSQUAREMAPGENERATOR_H

class DiamondSquareMapGenerator {
public:
    DiamondSquareMapGenerator(double **array, int s);

    double **process();

    void diamondStep(int, int);

    void squareStep(int, int);

    double dRand(double dMin, double dMax);

private:
    double **map;
    int size;

    int range;

};

#endif //MAP_GENERATION_DIAMONDSQUAREMAPGENERATOR_H
