#include "StarterProject_FixtureTests.hpp"

namespace Tests::UnitTest
{

TEST_F(StarterProject_FixtureTests, PrivateComplexCalculation1)
{
    // ARRANGE

    // ACT
    calculation.CalculateViaPrivateMethod(xx, yy, zz);
    double result = calculation.GetCalculationResult();

    // ASSERT
    double expected = xx - yy * zz;
    EXPECT_DOUBLE_EQ(expected, result) << "Failed: CalculateViaPrivateMethod(xx, yy, zz)";
}

TEST_F(StarterProject_FixtureTests, PrivateComplexCalculation2)
{
    // ARRANGE
    xx += 4;
    yy *= 5.5f;
    zz /= 3.3;

    // ACT
    calculation.CalculateViaPrivateMethod(xx, yy, zz);
    double result = calculation.GetCalculationResult();

    // ASSERT
    double expected = xx - yy * zz;
    EXPECT_DOUBLE_EQ(expected, result) << "Failed: CalculateViaPrivateMethod(xx, yy, zz)";
}

} // ~namespace Tests::UnitTest
