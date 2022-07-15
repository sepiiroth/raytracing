#ifndef ENTITY_H
#define ENTITY_H
#include "Matrix.h"

class Entity {
    private:
        Matrix trans;
        Matrix transInv;
    public:
        void translate(float x, float y, float z);
        void rotateX(float deg);
        void rotateY(float deg);
        void rotateZ(float deg);
        void scale(float factor);
    private:
};

#endif // ENTITY_H
