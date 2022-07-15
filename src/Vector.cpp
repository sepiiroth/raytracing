#include "vector.h"
#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

Vector::Vector() {}

Vector::Vector(float x, float y, float z) {
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
}

Vector::Vector(const Vector &vec) {
    this->m_x = vec.getX();
    this->m_y = vec.getY();
    this->m_z = vec.getZ();
}

float Vector::getX() const {
    return this->m_x;
};
float Vector::getY() const {
    return this->m_y;
};
float Vector::getZ() const {
    return this->m_z;
};

Vector Vector::operator+(const Vector &vec) {
    return Vector(this->m_x + vec.getX(), this->m_y + vec.getY(), this->m_z + vec.getZ());
}

Vector &Vector::operator+=(const Vector &vec) {
    this->m_x += vec.getX();
    this->m_y += vec.getY();
    this->m_z += vec.getZ();
    return *this;
}

Vector Vector::operator-(const Vector &vec) {
    return Vector(this->m_x - vec.getX(), this->m_y - vec.getY(), this->m_z - vec.getZ());
}

Vector &Vector::operator-=(const Vector &vec) {
    this->m_x -= vec.getX();
    this->m_y -= vec.getY();
    this->m_z -= vec.getZ();
    return *this;
}

Vector Vector ::operator*(float v) {
    return Vector(this->m_x * v,this->m_y * v,this->m_z * v);
}

Vector &Vector::operator*=(float v) {
    this->m_x *= v;
    this->m_y *= v;
    this->m_z *= v;
    return *this;
}

Vector Vector ::operator/(float v) {
    assert(v!=0);
    return Vector(this->m_x / v, this->m_y/v, this->m_z/v);
}

Vector &Vector ::operator/=(float v) {
    assert(v!=0);
    this->m_x /= v;
    this->m_y /= v;
    this->m_z /= v;
    return *this;
}

Vector &Vector::operator=(const Vector &vec) {
    this->m_x = vec.getX();
    this->m_y = vec.getY();
    this->m_z = vec.getZ();
    return *this;
}

float Vector::dot(const Vector &vec) {
    return this->m_x * vec.getX() + vec.getY() * this->m_y + vec.getZ() * this->m_z;
}

float Vector::norm()
{
    return sqrt(square());
}

float Vector::square() {
    return this->m_x * this->m_x + this->m_y * this->m_y + this->m_z * this->m_z;
}

Vector Vector::normalized() {
    assert(norm()!=0);
    *this/=norm();
    return *this;
}

void Vector::display() {
    cout<<this->m_x<<" "<<this->m_y<<" "<<this->m_z<<endl;
}
