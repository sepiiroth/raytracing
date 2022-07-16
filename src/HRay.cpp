#include "HRay.h"
#include<iostream>
#include<math.h>

HRay::HRay(float ox, float oy, float oz, float ow, float vx, float vy, float vz, float vw) {
    this->origin = new HPoint(ox, oy, oz, ow);
    this->vec = new HVector(vx, vy, vz, vw);
}

HRay::HRay(HPoint* p, HVector* v) {
    this->origin = p;
    this->vec = v;
}
