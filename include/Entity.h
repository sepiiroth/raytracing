#ifndef ENTITY_H
#define ENTITY_H
#include "Matrix.h"
#include "../src/Ray.cpp"
#include "../src/Point.cpp"
#include "../src/Vector.cpp"

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        /*void translate(float x, float y, float z);
        void rotateX(float deg);
        void rotateY(float deg);
        void rotateZ(float deg);
        void scale(float factor);*/

        Point globalToLocal(const Point& p) const;
        Ray globalToLocal(const Ray& r) const;
        Vector globalToLocal(const Vector v) const;

        Point localToGlobal(const Point& p) const;
        Ray localToGlobal(const Ray& r) const;
        Vector localToGlobal(const Vector v) const;

    protected:

    private:
        Matrix trans, transInv;
};

#endif // ENTITY_H
