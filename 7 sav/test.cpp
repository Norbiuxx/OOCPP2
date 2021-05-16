#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>

#include "Weather.h"
#include "myException.h"

using namespace std;
using namespace Forecast;

TEST_CASE("#AUTO_ID")
{
    Weather testID1(0, 0, 0, "No info");
    Weather testID2(0, 0, 0, "No info");
    Weather testID3(0, 0, 0, "No info");
    Weather testID4(0, 0, 0, "No info");

    CHECK(testID1.getID() == 1);
    CHECK(testID2.getID() == 2);
    CHECK(testID3.getID() == 3);
    CHECK(testID4.getID() == 4);
}

TEST_CASE("#SET")
{
    //constructor sets values
    Weather testSet(10, 5, 0, "sunny");

    CHECK(testSet.getAirTemperature() == 10);
    CHECK(testSet.getWindSpeed() == 5);
    CHECK(testSet.getGoingToRain() == false);
    CHECK(testSet.getWeatherType() == "sunny");
}

TEST_CASE("#CMP")
{
    Weather testCmp1(10, 5, 0, "sunny");
    Weather testCmp2(23, 3, 0, "sunny");
    Weather testCmp3(-2, 13, 1, "cloudy");
    Weather testCmp4(6, 15, 1, "sleeting");
    Weather testCmp5(9, 8, 1, "stormy");
    Weather testCmp6(10, 5, 0, "sunny");

    CHECK(testCmp1 == testCmp6);
    CHECK(testCmp2 > testCmp4);
    CHECK(testCmp1 >= testCmp6);
    CHECK(testCmp3 < testCmp5);
    CHECK(testCmp1 <= testCmp6);
    CHECK(testCmp3 != testCmp5);
}

TEST_CASE("#STREAM")
{
    Weather testStream1;
    Weather testStream2(10, 3, 1, "rainy");

    std::stringstream b;
    b << testStream2;
    b >> testStream1;

    CHECK(testStream1 == testStream2);
}

TEST_CASE("#PRE_POST")
{
    Weather testPreInc(3, 0, 0, "snowy");
    Weather testPreInc1(3, 0, 0, "snowy");

    Weather testPostInc(3, 0, 0, "snowy");
    Weather testPostInc1(3, 0, 0, "snowy");

    Weather testPreDec(3, 0, 0, "snowy");
    Weather testPreDec1(3, 0, 0, "snowy");

    Weather testPostDec(3, 0, 0, "snowy");
    Weather testPostDec1(3, 0, 0, "snowy");

    ++testPreInc1;
    CHECK(testPreInc1 > testPreInc);

    testPostInc1++;
    CHECK(testPostInc1 > testPostInc);

    --testPreDec1;
    CHECK(testPreDec > testPreDec1);

    --testPostDec1;
    CHECK(testPostDec > testPostDec1);
}

TEST_CASE("#THROW")
{
    Weather testThrow(20, 2, 1, "sunny");

    //forcing an exception
    CHECK_THROWS(testThrow.setAirTemperature(500));
    CHECK_THROWS(testThrow.setWindSpeed(200));
    CHECK_THROWS(testThrow.setWeatherType("test"));

    //check if values remained the same after the exception
    CHECK(testThrow.getAirTemperature() == 20);
    CHECK(testThrow.getWindSpeed() == 2);
    CHECK(testThrow.getWeatherType() == "sunny");
}

TEST_CASE("#COPY")
{
    Weather testCopy1(-3, 7, 0, "snowy");
    Weather testCopy2(testCopy1);

    CHECK(testCopy1 == testCopy2);
    testCopy2.setAirTemperature(0);
    CHECK(testCopy1 != testCopy2);
}

TEST_CASE("#LEAK")
{
    CHECK(Weather::getInstances() == 0);
    {
        Weather testLeak(0, 0, 0, "sunny");
        Weather testLeak1(0, 0, 0, "rainy");
        CHECK(Weather::getInstances() == 2);
    }
}

TEST_CASE("#CHECK_CONDITIONS")
{
    Weather checkCond1(17, 2, 0, "sunny");
    CHECK(checkCond1.checkConditions(checkCond1) == false);

    Weather checkCond2(3, 26, 0, "stormy");
    CHECK(checkCond2.checkConditions(checkCond2) == true);
}
