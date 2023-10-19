#pragma once
#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include "StarterProject_FixtureTests.hpp"

namespace Tests::UnitTest
{

struct ParametersCalculation
{
    int x;
    float y;
    double z;
    double expected;
};

std::string PrintToString(const ParametersCalculation& parameters)
{
    std::stringstream parametersThatErrored;
    parametersThatErrored << "x: " << parameters.x
        << ", y: " << parameters.y
        << ", z: " << parameters.z
        << ", expected: " << parameters.expected;
    return parametersThatErrored.str();
}

std::vector<ParametersCalculation> parametersCalculationBatch1 {
    {1, 1.1f, 11.111, 1 - 1.1f * 11.111},
    {2, 2.2f, 22.222, 2 - 2.2f * 22.222},
    {3, 3.3f, 33.333, 3 - 3.3f * 33.333}
};

class StarterProject_ParametrisedFixtureTests 
    : public StarterProject_FixtureTests
    , public ::testing::WithParamInterface<ParametersCalculation>
{
protected:
    // static void SetUpTestSuite() {}
    // void SetUp() override {}
    // void TearDown() override {}
    // static void TearDownTestSuite() {}
};

} // ~namespace Tests::UnitTest
