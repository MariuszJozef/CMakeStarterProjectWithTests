#pragma once

namespace Code::StarterProject
{

bool PreserveBoolean(bool trueOrFalse);
bool NegateBoolean(bool trueOrFalse);

struct Point3D
{
    float x {0.0f};
    float y {0.0f};
    float z {0.0f};
};

float EuclideanDistanceBetweenTwoPoints(const Point3D& point1, const Point3D& point2);

class Calculation final
{
public:
    void CalculateViaPrivateMethod(int x, float y, double z);
    double GetCalculationResult() const { return calculationResult; }

protected:
    void ProtectedMethodCallPrivate(int x, float y, double z);

private:
    void PrivateMethodComplexCalculation(int x, float y, double z);

private:
    double calculationResult {0.0};
};
    
} // ~namespace Code::StarterProject
