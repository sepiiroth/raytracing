#include "../include/Entity.h"
#include <math.h>

Entity::Entity()
{
    this->trans = Matrix(4,4);
    this->transInv = Matrix(4,4);
}

Entity::~Entity()
{
    //dtor
}

/*void Entity::translate(float x, float y, float z){
    Matrix m;
    m(0, 3) = x;
    m(1 ,3) = y;
    m(2, 3) = z;
    this->trans = m*this->trans;
    this->transInv = this->trans.inverse();
}

/*void Entity::rotateX(float deg){
    Matrix m;
	m(0, 0) = 1;
	m(1 ,1) = cos(deg);
	m(1, 2) = -sin(deg);
	m(2, 1) = sin(deg);
	m(2, 2) = cos(deg);
	this->trans = m*this->trans;
	this->transInv = this->trans.inverse();
}

void Entity::rotateY(float deg){
	Matrix m;
    m(0, 0) = cos(deg);
	m(0 ,2) = sin(deg);
	m(1, 1) = 1;
	m(2, 0) = -sin(deg);
	m(2, 2) = cos(deg);
	this->trans = m*this->trans;
	this->transInv = this->trans.inverse();
}


void Entity::rotateZ(float deg){
	Matrix m;
    m(0, 0) = cos(deg);
	m(0 ,1) = -sin(deg);
	m(1, 0) = sin(deg);
	m(1, 1) = cos(deg);
	m(2, 2) = 1;
	this->trans = m*this->trans;
	this->transInv = this->trans.inverse();
}

void Entity::scale(float factor){
    Matrix m;
	m(0,0) = factor;
	m(1,1) = factor;
	m(2,2) = factor;
	this->trans = m*this->trans;
	this->transInv = this->trans.inverse();
}*/

Point Entity::globalToLocal(const Point& p) const
{
    HPoint temp(p);
	return trans*temp;
}

Ray Entity::globalToLocal(const Ray& r) const{
    HRay temp(r);
  	return Ray(trans*temp.origin, trans*temp.vector);

}

Vector Entity::globalToLocal(const Vector v) const{
    HVector temp(v);
	return trans*temp;
}

Point Entity::localToGlobal(const Point& p) const{
    HPoint temp(p);
	return transInv*temp;
}

Ray Entity::localToGlobal(const Ray& r) const{
    HRay temp(r);
  	return Ray(transInv*temp.origin, transInv*temp.vector);

}

Vector Entity::localToGlobal(const Vector v) const{
    HVector temp(v);
	return transInv*temp;
}
