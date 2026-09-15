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

// Q6.
struct Matrix4x4 
{
    float m[4][4];

    Matrix4x4();

    static Matrix4x4 Identity();

    Matrix4x4 Transpose() const;
};

// Q9. Q10. 
// SHape Structures
struct AABB
{
    Vector3 min; // Bottom left
    Vector3 max; // Top right 
};

struct Circle
{
    Vector3 center;
    float radius;
};

// Collision detection functions

// point vs shape
bool PointInAABB(const Vector3& point, const AABB& box);
bool PointInCircle(const Vector3& point, const Circle& circle);

// shape vs shape
bool IntersectAABB(const AABB& a, const AABB& b);
bool IntersectCircle(const Circle& a, const Circle& b);
bool IntersectCircleAABB(const Circle& circle, const AABB& box);