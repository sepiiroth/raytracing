#ifndef HVECTOR_H
#define HVECTOR_H

class HVector {
    private:
        float m_x, m_y, m_z, m_w;
    public:
        HVector();
        HVector(float x, float y, float z, float w = 0);
        HVector(const HVector &vec);
        float getX() const;
        float getY() const;
        float getZ() const;
        float getW() const;
        HVector operator+(const HVector &vec);
        HVector &operator+=(const HVector &vec);
        HVector operator-(const HVector &vec);
        HVector &operator-=(const HVector &vec);
        HVector operator*(float value);
        HVector &operator*=(float value);
        HVector operator/(float value);
        HVector &operator/=(float value);
        HVector &operator=(const HVector &vec);
        float &operator[](int value);
        HVector operator-();
        float dot(const HVector &vec);
        float norm();
        float square();
        HVector normalized();
        void display();
};

#endif
