#include <cmath>
#include "StarterProject.hpp"

namespace Code::StarterProject
{

bool PreserveBoolean(bool trueOrFalse)
{
    return trueOrFalse;
}

bool NegateBoolean(bool trueOrFalse)
{
    return !trueOrFalse;
}

float EuclideanDistanceBetweenTwoPoints(const Point3D& point1, const Point3D& point2)
{
    float hypotenuseSquared = std::pow(point1.x - point2.x, 2);
    hypotenuseSquared += std::pow(point1.y - point2.y, 2);
    hypotenuseSquared += std::pow(point1.z - point2.z, 2);

    return std::sqrt(hypotenuseSquared);
}

void Calculation::CalculateViaPrivateMethod(int x, float y, double z)
{
    ProtectedMethodCallPrivate(x, y, z);
}

void Calculation::ProtectedMethodCallPrivate(int x, float y, double z)
{
    PrivateMethodComplexCalculation(x, y, z);
}

void Calculation::PrivateMethodComplexCalculation(int x, float y, double z)
{
    calculationResult = x - y * z;
}

} // ~namespace Code::StarterProject
