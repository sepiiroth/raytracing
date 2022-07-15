#include "Camera.h"

Ray Camera::getRay(float x, float y)const {
    return Ray(0, 0, this->focal, x, y, 0);
}
