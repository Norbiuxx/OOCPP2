#include <iostream>
#include <string>
#include <exception>
#include "Weather.h"
#include "myException.h"
#include <cassert>

using namespace std;
using namespace Forecast;

int main()
{
    try {
        assert(Weather(20, 6, 1, "sunny") == Weather(20, 6, 1, "sunny"));
        assert(Weather(20, 6, 1, "rainy") != Weather(20, 6, 1, "sunny"));
        assert(Weather(21, 2, 0, "sunny") > Weather(20, 6, 1, "cloudy"));
        assert(Weather(20, 4, 1, "sunny") >= Weather(20, 17, 1, "sunny"));
        assert(Weather(5, 20, 0, "snowy") < Weather(12, 11, 0, "stormy"));
        assert(Weather(0, 0, 0, "sleeting") <= Weather(0, 0, 1, "rainy"));

        Weather increment(0, 0, 0, "sleeting");
        assert(++increment > Weather(0, 0, 0, "sleeting"));
        assert(increment++ > Weather(0, 0, 0, "sleeting"));

        Weather decrement(0, 0, 0, "foggy");
        assert(--decrement < Weather(0, 0, 0, "sleeting"));
        assert(decrement-- < Weather(0, 0, 0, "sleeting"));


        cout << "Testing input:\nEnter data for weather in this order: temperature, wind speed, is it going to rain, weather type" << endl;
        Weather test;
        cin >> test;
        cout << "Input successful" << endl;

    }
    catch(myException &error) {
        cerr << error.what() << endl;
    }
    catch(invalid_argument &error) {
        cerr << error.what() << endl;
    }
    catch(exception &error) {
        cerr << error.what() << endl;
    }
    return 0;
}
