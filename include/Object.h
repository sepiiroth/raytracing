#ifndef OBJECT_H
#define OBJECT_H
#include "../src/Entity.cpp"

class Object : public Entity
{
    public:
        Object();
        virtual ~Object();

        Point getTextureCoordinates(const Point& p) const;
        //Material getMaterial(const Point& p) const;
        Ray getNormal(const Point& p, const Point& o) const;
        bool intersect(const Ray& ray, Point& impact) const;

        inline Point globalToLocal(const Point& p) const { return Entity::globalToLocal(p); };
        Ray globalToLocal(const Ray& r) const  { return Entity::globalToLocal(r); };
        Vector globalToLocal(const Vector v) const  { return Entity::globalToLocal(v); };

        Point localToGlobal(const Point& p) const { return Entity::localToGlobal(p); };
        Ray localToGlobal(const Ray& r) const { return Entity::localToGlobal(r); };
        Vector localToGlobal(const Vector v) cons { return Entity::localToGlobal(v); }t;

    protected:

    private:
        Point texcoords;
};

#endif // OBJECT_H
