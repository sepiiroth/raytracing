#include "../include/Scene.h"

using namespace std;

Scene::Scene()
{
    this->lights = vector<Light>();
    this->objects = vector<Object*>();
}

Scene::~Scene()
{
    //dtor
}

int Scene::nbLights() const{
    return this->lights.size();
}

const Light* Scene::getLight(int index) const
{
    return &(this->lights[index]);
}

Object* Scene::closer_intersected(const Ray& ray, Point& impact) const
{
    Point impactTemp;

    float minDistance = INT_MAX * 1.0f;
    Object* temp = nullptr;

    for(int i = 0; i < this->objects.size(); i++)
    {
        if(this->objects[i]->intersect(ray, impactTemp))
        {
            float tempDistance = ray.origin->distanceTo(impactTemp);
            if( tempDistance < minDistance)
            {
                minDistance = tempDistance;
                temp = this->objects[i];
            }
        }
    }

    return temp;

}


