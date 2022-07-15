#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

class Vector {
    private:
        float m_x, m_y, m_z;
    public:
        Vector();
        Vector(float x, float y, float z = 0);
        Vector(const Vector &vec);
        float GetX() const;
        float GetY() const;
        float GetZ() const;
        Vector operator+(const Vector &vec);
        Vector &operator+=(const Vector &vec);
        Vector operator-(const Vector &vec);
        Vector &operator-=(const Vector &vec);
        Vector operator*(float value);
        Vector &operator*=(float value);
        Vector operator/(float value);
        Vector &operator/=(float value);
        Vector &operator=(const Vector &vec);
        float dot(const Vector &vec);
        float norm();
        float square();
        Vector normalized();
        void display();
};

#endif
