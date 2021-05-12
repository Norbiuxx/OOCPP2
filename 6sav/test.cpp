#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Weather.h"
#include "myException.h"

using namespace Forecast;

TEST_CASE("Random")
{
    Weather testt(10, 1, 0, "sunny");
    CHECK(testt.getAirTemperature() == 10);
}
