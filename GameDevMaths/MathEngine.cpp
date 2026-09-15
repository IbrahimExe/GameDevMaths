#include "MathEngine.h"
#include <cmath> //for std::sqrt


// Vector3 Implementation 
Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
Vector3 Vector3::operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
Vector3 Vector3::operator*(float scalar) const { return Vector3(x * scalar, y * scalar, z * scalar); }
Vector3 Vector3::operator/(float scalar) const { return Vector3(x / scalar, y / scalar, z / scalar); }

Vector3& Vector3::operator+=(const Vector3& v) { x += v.x; y += v.y; z += v.z; return *this; }
Vector3& Vector3::operator-=(const Vector3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
Vector3& Vector3::operator*=(float scalar) { x *= scalar; y *= scalar; z *= scalar; return *this; }
Vector3& Vector3::operator/=(float scalar) { x /= scalar; y /= scalar; z /= scalar; return *this; }

bool Vector3::operator==(const Vector3& v) const 
{
    return x == v.x && y == v.y && z == v.z;
}

float Vector3::Dot(const Vector3& v) const 
{
    return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector3 Vector3::Cross(const Vector3& v) const 
{
    return Vector3
    (
        (y * v.z) - (z * v.y),
        (z * v.x) - (x * v.z),
        (x * v.y) - (y * v.x)
    );
}

float Vector3::Magnitude() const 
{
    return std::sqrt(x * x + y * y + z * z);
}

void Vector3::Normalize() 
{
    float mag = Magnitude();
    if (mag > 0.0001f) 
    {
        x /= mag;
        y /= mag;
        z /= mag;
    }
}

// Matrix4x4 Implementation
Matrix4x4::Matrix4x4() 
{
    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 4; ++j) 
        {
            m[i][j] = 0.0f;
        }
    }
}

Matrix4x4 Matrix4x4::Identity() 
{
    Matrix4x4 mat;
    mat.m[0][0] = 1.0f;
    mat.m[1][1] = 1.0f;
    mat.m[2][2] = 1.0f;
    mat.m[3][3] = 1.0f;
    return mat;
}