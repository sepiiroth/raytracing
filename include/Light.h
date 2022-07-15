#ifndef LIGHT_H
#define LIGHT_H
#include "Entity.h"
#include "Point.h"
#include "Vector.h"
#include "Ray.h"

class Light: public Entity {
    private:

    public:
        Ray getRayToLight(const Point& p)const;
        Ray getRayFromLight(const Point& p)const;
        Vector getVectorToLight(const Point& p)const;
        Vector getVectorFromLight(const Point& p)const;
};

#endif
