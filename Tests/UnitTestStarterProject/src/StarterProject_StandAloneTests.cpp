#include <gtest/gtest.h>
#include "StarterProject.hpp"

namespace Tests::UnitTest
{

TEST(StarterProject_StandAloneTests, PreserveBool)
{
    // ARRANGE
    bool arg1 {true};
    bool arg2 {false};

    // ACT
    bool result1 = Code::StarterProject::PreserveBoolean(arg1);
    bool result2 = Code::StarterProject::PreserveBoolean(arg2);

    // ASSERT
    EXPECT_TRUE(result1) << "Failed: PreserveBoolean(arg1)";
    EXPECT_FALSE(result2) << "Failed: PreserveBoolean(arg2)";
    // ASSERT_FALSE(result1) << "Failed: PreserveBoolean(arg1)";
    // EXPECT_FALSE(result1) << "Failed: PreserveBoolean(arg1)";
}

TEST(StarterProject_StandAloneTests, NegateBool)
{
    // ARRANGE
    bool arg1 {false};
    bool arg2 {true};

    // ACT
    bool result1 = Code::StarterProject::NegateBoolean(arg1);
    bool result2 = Code::StarterProject::NegateBoolean(arg2);

    // ASSERT
    EXPECT_TRUE(result1) << "Failed: NegateBoolean(arg1)";
    EXPECT_FALSE(result2) << "Failed: NegateBoolean(arg2)";
}

TEST(StarterProject_StandAloneTests, EuclideanDistance1)
{
    // ARRANGE
    Code::StarterProject::Point3D point1 {1.0f, 2.0f, 3.0f};
    Code::StarterProject::Point3D point2 {-1.0f, -2.0f, 7.0f};

    // ACT
    float result = Code::StarterProject::EuclideanDistanceBetweenTwoPoints(point1, point2);

    // ASSERT
    float expected = 6.0f;
    EXPECT_FLOAT_EQ(expected, result) << "Failed: EuclideanDistanceBetweenTwoPoints(point1, point2)";
}

TEST(StarterProject_StandAloneTests, EuclideanDistance2)
{
    // ARRANGE
    Code::StarterProject::Point3D point1 {0.0f, 0.0f, 0.0f};
    Code::StarterProject::Point3D point2 {2.0f, 4.0f, 4.0f};

    // ACT
    float result = Code::StarterProject::EuclideanDistanceBetweenTwoPoints(point1, point2);

    // ASSERT
    float expected = 6.0f;
    EXPECT_FLOAT_EQ(expected, result) << "Failed: EuclideanDistanceBetweenTwoPoints(point1, point2)";
}

TEST(StarterProject_StandAloneTests, PrivateComplexCalculation)
{
    // ARRANGE
    Code::StarterProject::Calculation calculation;
    int x {123};
    float y {4.56f};
    double z {78.9};

    // ACT
    calculation.CalculateViaPrivateMethod(x, y, z);
    double result = calculation.GetCalculationResult();

    // ASSERT
    double expected = x - y * z;
    EXPECT_DOUBLE_EQ(expected, result) << "Failed: CalculateViaPrivateMethod(x, y, z)";
}

} // ~namespace Tests::UnitTest
