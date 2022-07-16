#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    private:
        float m_x, m_y, m_z;
    public:
        Vector();
        Vector(float x, float y, float z = 0);
        Vector(const Vector &vec);
        float getX() const;
        float getY() const;
        float getZ() const;
        Vector operator+(const Vector &vec);
        Vector &operator+=(const Vector &vec);
        Vector operator-(const Vector &vec);
        Vector &operator-=(const Vector &vec);
        Vector operator*(float value);
        Vector &operator*=(float value);
        Vector operator/(float value);
        Vector &operator/=(float value);
        Vector &operator=(const Vector &vec);
        float operator[](int value) const;
        float& operator[](int value);
        Vector operator-();
        float dot(const Vector &vec);
        float norm();
        float square();
        Vector normalized();
        void display();
};

#endif
