#ifndef HPOINT_H
#define HPOINT_H


class HPoint {
    private:
        float m_x, m_y, m_z, m_w;
    public:
        HPoint();
        HPoint(float x, float y, float z, float w);
        float getX() const;
        float getY() const;
        float getZ() const;
        float getW() const;
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void setW(float w);
        HPoint operator+(const HPoint &p);
        HPoint &operator+=(const HPoint &p);
        HPoint operator-(const HPoint &p);
        HPoint &operator-=(const HPoint &p);
        HPoint operator*(float value);
        HPoint &operator*=(float value);
        HPoint operator/(float value);
        HPoint &operator/=(float value);
        HPoint &operator=(const HPoint &p);
        float &operator[](int value);
        HPoint operator-();
        float dot(const HPoint &p);
        void display();
};

#endif // HPOINT_H
