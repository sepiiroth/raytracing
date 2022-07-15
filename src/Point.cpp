#include "Point.h"
#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

Point::Point() {}

Point::Point(float x, float y, float z) {
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
}

float Point::getX() const {
    return this->m_x;
}

float Point::getY() const {
    return this->m_y;
}
float Point::getZ() const {
    return this->m_z;
}

void Point::setX(float x) {
    this->m_x = x;
}

void Point::setY(float y) {
    this->m_y = y;
}

void Point::setZ(float z) {
    this->m_z = z;
}

Point Point::operator+(const Point &p) {
    return Point(this->m_x + p.getX(), this->m_y + p.getY(), this->m_z + p.getZ());
}

Point &Point::operator+=(const Point &p) {
    this->m_x += p.getX();
    this->m_y += p.getY();
    this->m_z += p.getZ();
    return *this;
}

Point Point::operator-(const Point &p) {
    return Point(this->m_x - p.getX(), this->m_y - p.getY(), this->m_z - p.getZ());
}

Point &Point::operator-=(const Point &p) {
    this->m_x -= p.getX();
    this->m_y -= p.getY();
    this->m_z -= p.getZ();
    return *this;
}

Point Point ::operator*(float v) {
    return Point(this->m_x * v,this->m_y * v,this->m_z * v);
}

Point &Point::operator*=(float v) {
    this->m_x *= v;
    this->m_y *= v;
    this->m_z *= v;
    return *this;
}

Point Point ::operator/(float v) {
    assert(v!=0);
    return Point(this->m_x / v, this->m_y/v, this->m_z/v);
}

Point &Point ::operator/=(float v) {
    assert(v!=0);
    this->m_x /= v;
    this->m_y /= v;
    this->m_z /= v;
    return *this;
}

Point &Point::operator=(const Point &p) {
    this->m_x = p.getX();
    this->m_y = p.getY();
    this->m_z = p.getZ();
    return *this;
}

void Point::display() {
    cout<<this->m_x<<" "<<this->m_y<<" "<<this->m_z<<endl;
}

