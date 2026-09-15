#pragma once

// Part 1:
struct Vector3 
{
    float x, y, z;

    // Constructors
    Vector3();
    Vector3(float x, float y, float z);

    // Operators
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(float scalar) const;
    Vector3 operator/(float scalar) const;

    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(const Vector3& v);
    Vector3& operator*=(float scalar);
    Vector3& operator/=(float scalar);

    bool operator==(const Vector3& v) const;

    // Math Functions
    float Dot(const Vector3& v) const;
    Vector3 Cross(const Vector3& v) const;
    float Magnitude() const;
    void Normalize();
};

struct Matrix4x4 
{
    float m[4][4];

    Matrix4x4();
    static Matrix4x4 Identity();
};