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

// Q6. Matrix4x4 Implementation
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

Matrix4x4 Matrix4x4::Transpose() const
{
    Matrix4x4 result;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            // Swap rows and columns
            result.m[i][j] = m[j][i];
        }
    }

    return result;
}


// Q10. Q11. Collision Detection Implementation
bool PointInAABB(const Vector3& point, const AABB& box)
{
    // Check if point is between min and max on both X and Y axes
    return (point.x >= box.min.x && point.x <= box.max.x &&
        point.y >= box.min.y && point.y <= box.max.y);
}

bool PointInCircle(const Vector3& point, const Circle& circle)
{
    Vector3 distanceVec = point - circle.center;

    float distanceSquared = distanceVec.Dot(distanceVec);
    float radiusSquared = circle.radius * circle.radius;

    return distanceSquared <= radiusSquared;
}

bool IntersectAABB(const AABB& a, const AABB& b)
{
    // If the boxes are NOT overlapping on the X axis, or NOT overlapping on the Y axis, 
    // they don't intersect.
    // reverse this logic to return true if they DO intersect
    return (a.min.x <= b.max.x && a.max.x >= b.min.x &&
        a.min.y <= b.max.y && a.max.y >= b.min.y);
}

bool IntersectCircle(const Circle& a, const Circle& b)
{
    Vector3 distanceVec = a.center - b.center;
    float distanceSquared = distanceVec.Dot(distanceVec);

    float radiusSum = a.radius + b.radius;
    float radiusSumSquared = radiusSum * radiusSum;

    return distanceSquared <= radiusSumSquared;
}

bool IntersectCircleAABB(const Circle& circle, const AABB& box)
{
    // Find the closest point on the AABB perimeter to the circle's center
    Vector3 closestPoint = circle.center;

    // Clamp X
    if (closestPoint.x < box.min.x)
    {
        closestPoint.x = box.min.x;
    }
    else if (closestPoint.x > box.max.x)
    {
        closestPoint.x = box.max.x;
    }

    // Clamp Y
    if (closestPoint.y < box.min.y)
    {
        closestPoint.y = box.min.y;
    }
    else if (closestPoint.y > box.max.y)
    {
        closestPoint.y = box.max.y;
    }

    // Check if distance from closest point to circle center is less than radius
    Vector3 distanceVec = circle.center - closestPoint;
    float distanceSquared = distanceVec.Dot(distanceVec);

    return distanceSquared <= (circle.radius * circle.radius);
}