#include "StarterProject_ParametrisedFixtureTests.hpp"

namespace Tests::UnitTest
{

TEST_P(StarterProject_ParametrisedFixtureTests, PrivateComplexCalculation)
{
    // ARRANGE
    const ParametersCalculation& parameters = GetParam();

    // ACT
    calculation.CalculateViaPrivateMethod(parameters.x, parameters.y, parameters.z);
    double result = calculation.GetCalculationResult();

    // ASSERT
    EXPECT_EQ(parameters.expected, result) << "Failed: CalculateViaPrivateMethod(x, y, z)";
}

#ifdef _WIN32
    INSTANTIATE_TEST_CASE_P(
        Batch1, 
        StarterProject_ParametrisedFixtureTests,
        ::testing::ValuesIn(parametersCalculationBatch1)
    );
#else
    INSTANTIATE_TEST_SUITE_P(
        Batch1, 
        StarterProject_ParametrisedFixtureTests,
        ::testing::ValuesIn(parametersCalculationBatch1)
    );
#endif

} // ~namespace Tests::UnitTest
