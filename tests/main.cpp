#include<iostream>
#include "gtest/gtest.h"

// was will ich testen?
#include "my_lib.h"
#include "linalg.h"

//------------------------------------------------
// Mock class for void methods
//------------------------------------------------

// class MockTurtle : public Turtle {
//  public:
//   ...
//   MOCK_METHOD(void, PenUp, (), (override));
//   MOCK_METHOD(void, PenDown, (), (override));
//   MOCK_METHOD(void, Forward, (int distance), (override));
//   MOCK_METHOD(void, Turn, (int degrees), (override));
//   MOCK_METHOD(void, GoTo, (int x, int y), (override));
//   MOCK_METHOD(int, GetX, (), (const, override));
//   MOCK_METHOD(int, GetY, (), (const, override));
// };

//------------------------------------------------
// TestSuits: um verschiedene tests zu definieren
// aTestSuite: name testSuite
// MyTest: name aktuellen test
//------------------------------------------------

TEST(aTestSuite, Test_ComputeAverage)
{
    std::int32_t valueA=10, valueB = 20;
    std::int32_t expectedResult = 15;
    //Method call
    std::int32_t result = computer_average(valueA,valueB);
    // check
    ASSERT_EQ(expectedResult, result);
    // ASSERT_NE(expectedResult, 16);
}

TEST(aTestSuiteVector, Test_Vector)
{
    linalg::aliases::float3 expectedResult {1,2,3};
    //Method call
    linalg::aliases::float3 result = print_linalg_vector();
    // check
    for(int i = 0; i < 3 ;++i ){
      ASSERT_EQ(expectedResult[i], result[i]);
    }
}


//------------------------------------------------
// Main
//------------------------------------------------

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



