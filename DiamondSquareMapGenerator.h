#ifndef MAP_GENERATION_DIAMONDSQUAREMAPGENERATOR_H
#define MAP_GENERATION_DIAMONDSQUAREMAPGENERATOR_H

class DiamondSquareMapGenerator {
public:
    DiamondSquareMapGenerator(double **array, int s);

    double **process();

    void _on_start();

    void diamondStep(int, int);

    void squareStep(int, int);

    double dRand(double dMin, double dMax);

    void renderMap();

private:
    double random_range;
    double min_val;
    double max_val;

    double **map;
    int size;

    int range;

};

#endif //MAP_GENERATION_DIAMONDSQUAREMAPGENERATOR_H
