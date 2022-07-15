#include "vector.h"
#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

Vector::Vector() {
    m_x = 0;
    m_y = 0;
    m_z = 0;
}

Vector::Vector(float x, float y, float z = 0) {
    m_x = x;
    m_y = y;
    m_z = z;
}

Vector::Vector(const Vector &vec) {
    m_x = vec.x;
    m_y = vec.y;
    m_z = vec.z;
}

float Vector::GetX() const {
    return m_x;
};
float Vector::GetY() const {
    return m_y;
};
float Vector::GetZ() const {
    return m_z;
};

Vector Vector::operator+(const Vector &vec) {
    return Vector(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z);
}

Vector &Vector::operator+=(const Vector &vec) {
    m_x += vec.m_x;
    m_y += vec.m_y;
    m_z += vec.m_z;
    return *this;
}

Vector Vector::operator-(const Vector &vec) {
    return Vector(m_x - vec.m_x, m_y - vec.m_y, m_z - vec.m_z);
}

Vector &Vector::operator-=(const Vector &vec) {
    m_x -= vec.m_x;
    m_y -= vec.m_y;
    m_z -= vec.m_z;
    return *this;
}

Vector Vector ::operator*(float v) {
    return Vector(m_x * v,m_y * v,m_z * v);
}

Vector &Vector::operator*=(float v) {
    m_x *= v;
    m_y *= v;
    m_z *= v;
    return *this;
}

Vector Vector ::operator/(float v) {
    assert(v!=0);
    return Vector(m_x / v, m_y/v, m_z/v);
}

Vector &Vector ::operator/=(float v) {
    assert(v!=0);
    m_x /= v;
    m_y /= v;
    m_z /= v;
    return *this;
}

Vector &Vector::operator=(const Vector &vec) {
    m_x = vec.m_x;
    m_y = vec.m_y;
    m_z = vec.m_z;
    return *this;
}

float Vector::dot(const Vector &vec) {
    return m_x * vec.m_x + vec.m_y * m_y + vec.m_z * m_z;
}

float Vector::norm()
{
    return sqrt(square());
}

float Vector::square() {
    return m_x * m_x + m_y * m_y + m_z * m_z;
}

Vector Vector::normalized() {
    assert(norm()!=0);
    *this/=norm();
    return *this;
}

void Vector::display() {
    cout<<m_x<<" "<<m_y<<" "<<m_z<<endl;
}
