#include "Entity.h"
#include<math.h>

void Entity::translate(float x, float y, float z){
		Matrix m;
		m(0, 3) = x;
		m(1 ,3) = y;
		m(2, 3) = z;
		this->trans = m*this->trans;
		this->transInv = this->trans.inverse();
}

void Entity::rotateX(float deg){
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


void Entity::scale(float f) {
    Matrix m;
	m(0, 0) = f;
	m(1 ,1) = f;
	m(2, 2) = f;
	this->trans = m*this->trans;
	this->transInv = this->trans.inverse();
}

