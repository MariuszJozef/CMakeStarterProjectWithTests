#include "StarterProject_FixtureTests.hpp"

namespace Tests::UnitTest
{

TEST_F(StarterProject_FixtureTests, PrivateComplexCalculation1)
{
    // ARRANGE

    // ACT
    calculation.CalculateViaPrivateMethod(x, y, z);
    double result = calculation.GetCalculationResult();

    // ASSERT
    double expected = x - y * z;
    EXPECT_DOUBLE_EQ(expected, result) << "Failed: CalculateViaPrivateMethod(x, y, z)";
}

TEST_F(StarterProject_FixtureTests, PrivateComplexCalculation2)
{
    // ARRANGE
    x += 4;
    y *= 5.5f;
    z /= 3.3;

    // ACT
    calculation.CalculateViaPrivateMethod(x, y, z);
    double result = calculation.GetCalculationResult();

    // ASSERT
    double expected = x - y * z;
    EXPECT_DOUBLE_EQ(expected, result) << "Failed: CalculateViaPrivateMethod(x, y, z)";
}

} // ~namespace Tests::UnitTest
