#ifndef RAY_H
#define RAY_H
#include "Point.h"
#include "Vector.h"

class Ray
{
    public:
        Point* origin;
        Vector* vec;
        Ray(float ox, float oy, float oz, float vx, float vy, float vz);
        Ray(Point* p, Vector* v);
    private:
};

#endif
