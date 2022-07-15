#ifndef POINT_H
#define POINT_H

class Point {
    private:
        float m_x, m_y, m_z;
    public:
        Point();
        Point(float x, float y, float z);
        float getX() const;
        float getY() const;
        float getZ() const;
        void setX(float x);
        void setY(float y);
        void setZ(float y);
        Point operator+(const Point &p);
        Point &operator+=(const Point &p);
        Point operator-(const Point &p);
        Point &operator-=(const Point &p);
        Point operator*(float value);
        Point &operator*=(float value);
        Point operator/(float value);
        Point &operator/=(float value);
        Point &operator=(const Point &p);
        float &operator[](int value);
        Point operator-();
        float dot(const Point &p);
        void display();
};

#endif // POINT_H
