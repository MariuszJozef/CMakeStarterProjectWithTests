#include <iostream>
#include "StarterProject.hpp"

int main()
{
    Code::StarterProject::PreserveBoolean(true);
    Code::StarterProject::NegateBoolean(true);

    Code::StarterProject::Point3D point1 {0.0f, 0.0f, 0.0f};
    Code::StarterProject::Point3D point2 {2.0f, 4.0f, 4.0f};
    Code::StarterProject::EuclideanDistanceBetweenTwoPoints(point1, point2);

    int x {123};
    float y {4.56f};
    double z {78.9};
    Code::StarterProject::Calculation calculation;
    calculation.CalculateViaPrivateMethod(x, y, z);
    double calculationResult = calculation.GetCalculationResult();

    std::cout << "StarterProjectWithTests: calculationResult = " << calculationResult << "\n";

#ifdef STARTER_PROJECT
    std::cout << "STARTER_PROJECT is ON\n";
#else
    std::cout << "STARTER_PROJECT is OFF\n";
#endif
}
