#include <iostream>
#include <string>
#include <exception>
#include "Weather.h"

using namespace std;

int main()
{
    try {
        Weather weather1(27, 4, false, "sunny");
        Weather weather2(28, 3, true, "sunny");
        Weather weather3;

        weather1++;
        cout << "Temperature of weather1 after incrementing is: " << weather1.getAirTemperature() << endl;

        try {
            cin >> weather3;
            cout << weather3;
        }
        catch(exception &l) {
            cerr << l.what() << endl;
        }

    }
    catch(invalid_argument &error) {
        cerr << error.what() << endl;
    }
    return 0;
}
