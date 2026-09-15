// GameDevMaths.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "MathEngine.h"

// A quick helper function to make printing vectors easier
void PrintVector(const char* name, const Vector3& v)
{
    std::cout << name << ": (" << v.x << ", " << v.y << ", " << v.z << ")\n";
}

int main()
{
    // Make std::cout print "true/false" instead of "1/0"
    std::cout << std::boolalpha;

    std::cout << "--- TESTING VECTORS ---\n";
    Vector3 v1(1.0f, 0.0f, 0.0f); // Pointing Right
    Vector3 v2(0.0f, 1.0f, 0.0f); // Pointing Up

    Vector3 added = v1 + v2;
    PrintVector("v1 + v2", added);

    float dot = v1.Dot(v2);
    std::cout << "Dot Product (Right vs Up): " << dot << " (Should be 0)\n";

    Vector3 cross = v1.Cross(v2);
    PrintVector("Cross Product", cross);

    Vector3 toNormalize(0.0f, 3.0f, 4.0f);
    std::cout << "Magnitude before: " << toNormalize.Magnitude() << " (Should be 5)\n";
    toNormalize.Normalize();
    PrintVector("Normalized", toNormalize);
    std::cout << "Magnitude after: " << toNormalize.Magnitude() << " (Should be 1)\n\n";


    std::cout << "--- TESTING MATRICES ---\n";
    Matrix4x4 identity = Matrix4x4::Identity();
    std::cout << "Identity [0][0]: " << identity.m[0][0] << " (Should be 1)\n";
    Matrix4x4 transposed = identity.Transpose();
    std::cout << "Transposed Identity [0][0]: " << transposed.m[0][0] << " (Should be 1)\n\n";


    std::cout << "--- TESTING COLLISIONS ---\n";
    // Create a 10x10 box starting at the origin
    AABB box1;
    box1.min = Vector3(0.0f, 0.0f, 0.0f);
    box1.max = Vector3(10.0f, 10.0f, 0.0f);

    // Create a circle with radius 2 at coordinates (5, 5)
    Circle circle1;
    circle1.center = Vector3(5.0f, 5.0f, 0.0f);
    circle1.radius = 2.0f;

    // Test Points
    Vector3 insidePoint(5.0f, 5.0f, 0.0f);
    Vector3 outsidePoint(20.0f, 20.0f, 0.0f);

    std::cout << "Point in AABB (Inside): " << PointInAABB(insidePoint, box1) << "\n";
    std::cout << "Point in AABB (Outside): " << PointInAABB(outsidePoint, box1) << "\n";

    std::cout << "Point in Circle (Inside): " << PointInCircle(insidePoint, circle1) << "\n";
    std::cout << "Point in Circle (Outside): " << PointInCircle(outsidePoint, circle1) << "\n";

    // Test Shape vs Shape
    AABB box2; // Intersects box1
    box2.min = Vector3(8.0f, 8.0f, 0.0f);
    box2.max = Vector3(15.0f, 15.0f, 0.0f);

    Circle circle2; // Does not intersect circle1 (too far away)
    circle2.center = Vector3(15.0f, 15.0f, 0.0f);
    circle2.radius = 2.0f;

    std::cout << "AABB vs AABB (Intersecting): " << IntersectAABB(box1, box2) << "\n";
    std::cout << "Circle vs Circle (Not Intersecting): " << IntersectCircle(circle1, circle2) << "\n";

    // Circle 1 is inside Box 1
    std::cout << "Circle vs AABB (Intersecting): " << IntersectCircleAABB(circle1, box1) << "\n";

    return 0;
}