#ifndef HRAY_H
#define HRAY_H
#include "HPoint.h"
#include "HVector.h"

class HRay {
    private:
    public:
        HPoint* origin;
        HVector* vec;
        HRay(float ox, float oy, float oz, float ow, float vx, float vy, float vz, float vw);
        HRay(HPoint* p, HVector* v);
};

#endif // HRAY_H
