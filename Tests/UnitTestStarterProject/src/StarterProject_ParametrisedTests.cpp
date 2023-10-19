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

} // ~namespace Tests::UnitTest
