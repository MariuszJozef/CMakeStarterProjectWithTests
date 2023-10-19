#pragma once
#include <gtest/gtest.h>
#include <iostream>
#include "StarterProject.hpp"

namespace Tests::UnitTest
{

class StarterProject_FixtureTests : public ::testing::Test
{
// public:
protected:
    StarterProject_FixtureTests()
    {
        std::cout << "StarterProject_FixtureTests::StarterProject_FixtureTests\n";
    }

    ~StarterProject_FixtureTests()
    {
        std::cout << "StarterProject_FixtureTests::~StarterProject_FixtureTests\n";
    }

protected:
    static void SetUpTestSuite() 
    {
        std::cout << "StarterProject_FixtureTests::SetUpTestSuite\n";
    };

    void SetUp() override
    {
        std::cout << "StarterProject_FixtureTests::SetUp\n";
    };
    
    void TearDown() override
    {
        std::cout << "StarterProject_FixtureTests::TearDown\n";
    };
    
    static void TearDownTestSuite()
    {
        std::cout << "StarterProject_FixtureTests::TearDownTestSuite\n";
    };

// Cannot be private!
protected:
    Code::StarterProject::Calculation calculation;
    int x {123};
    float y {4.56f};
    double z {78.9};
};

} // ~namespace Tests::UnitTest
