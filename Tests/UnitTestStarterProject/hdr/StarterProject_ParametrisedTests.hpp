#pragma once
#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include "StarterProject.hpp"

namespace Tests::UnitTest
{

struct ParametersPoint3D
{
    Code::StarterProject::Point3D point1;
    Code::StarterProject::Point3D point2;
    float expected;
};

std::string PrintToString(const ParametersPoint3D& parameters)
{
    std::stringstream parametersThatErrored;
    parametersThatErrored << "point1.x: " << parameters.point1.x
        << ", point1.y: " << parameters.point1.y
        << ", point1.z: " << parameters.point1.z
        << ", point2.x: " << parameters.point2.x
        << ", point2.y: " << parameters.point2.y
        << ", point2.z: " << parameters.point2.z
        << ", expected: " << parameters.expected;
    return parametersThatErrored.str();
}

std::vector<ParametersPoint3D> parametersPoint3DBatch1 {
    {
        Code::StarterProject::Point3D {1.0f, 2.0f, 3.0f}, 
        Code::StarterProject::Point3D {-1.0f, -2.0f, 7.0f}, 
        6.0f
    },
    {
        Code::StarterProject::Point3D {0.0f, 0.0f, 0.0f},
        Code::StarterProject::Point3D {2.0f, 4.0f, 4.0f},
        6.0f
    },
    {
        Code::StarterProject::Point3D {1.0f, 4.0f, 6.0f},
        Code::StarterProject::Point3D {3.0f, 8.0f, 10.0f},
        6.0f
    }
};

class StarterProject_ParametrisedTests : public ::testing::TestWithParam<ParametersPoint3D>
{
protected:
    // static void SetUpTestSuite() {}
    // void SetUp() override {}
    // void TearDown() override {}
    // static void TearDownTestSuite() {}
};

struct ParametersCalculation2
{
    int x;
    float y;
    double z;
    double expected;
};

std::string PrintToString(const ParametersCalculation2& parameters)
{
    std::stringstream parametersThatErrored;
    parametersThatErrored << "x: " << parameters.x
        << ", y: " << parameters.y
        << ", z: " << parameters.z
        << ", expected: " << parameters.expected;
    return parametersThatErrored.str();
}

std::vector<ParametersCalculation2> parametersCalculation2Batch1 {
    {1, 1.1f, 11.111, 1 - 1.1f * 11.111},
    {2, 2.2f, 22.222, 2 - 2.2f * 22.222},
    {3, 3.3f, 33.333, 3 - 3.3f * 33.333}
};

class StarterProject_ParametrisedTests2 : public ::testing::TestWithParam<ParametersCalculation2>
{
protected:
    // static void SetUpTestSuite() {}
    // void SetUp() override {}
    // void TearDown() override {}
    // static void TearDownTestSuite() {}
};

} // ~namespace Tests::UnitTest
