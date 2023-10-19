#include "StarterProject_ParametrisedTests.hpp"

namespace Tests::UnitTest
{

TEST_P(StarterProject_ParametrisedTests, EuclideanDistance)
{
    // ARRANGE
    const ParametersPoint3D& parameters = GetParam();

    // ACT
    float result = Code::StarterProject::EuclideanDistanceBetweenTwoPoints(parameters.point1, parameters.point2);

    // ASSERT
    EXPECT_EQ(parameters.expected, result) << "Failed: EuclideanDistanceBetweenTwoPoints(point1, point2)";
}

#ifdef _WIN32
    INSTANTIATE_TEST_CASE_P(
        Batch1, 
        StarterProject_ParametrisedTests,
        ::testing::ValuesIn(parametersPoint3DBatch1)
    );
#else
    INSTANTIATE_TEST_SUITE_P(
        Batch1, 
        StarterProject_ParametrisedTests,
        ::testing::ValuesIn(parametersPoint3DBatch1)
    );
#endif

TEST_P(StarterProject_ParametrisedTests2, PrivateComplexCalculation)
{
    // ARRANGE
    Code::StarterProject::Calculation calculation;
    const ParametersCalculation2& parameters = GetParam();

    // ACT
    calculation.CalculateViaPrivateMethod(parameters.x, parameters.y, parameters.z);
    double result = calculation.GetCalculationResult();

    // ASSERT
    EXPECT_EQ(parameters.expected, result) << "Failed: CalculateViaPrivateMethod(x, y, z)";
}

#ifdef _WIN32
    INSTANTIATE_TEST_CASE_P(
        Batch1, 
        StarterProject_ParametrisedTests2,
        ::testing::ValuesIn(parametersCalculation2Batch1)
    );
#else
    INSTANTIATE_TEST_SUITE_P(
        Batch2, 
        StarterProject_ParametrisedTests2,
        ::testing::ValuesIn(parametersCalculation2Batch1)
    );
#endif

} // ~namespace Tests::UnitTest
