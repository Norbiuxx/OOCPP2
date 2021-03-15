#include <iostream>
#include "Weather.h"
#include <sstream>
#include <vector>

#define DEFAULT_TEMP 0
#define DEFAULT_SPEED 0
#define DEFAULT_TYPE "No info"
#define DEFAULT_RAINING false

using namespace std;

int Weather::ID = 0;

Weather::Weather()
{
    setAirTemperature(DEFAULT_TEMP);
    setWindSpeed(DEFAULT_SPEED);
    setGoingToRain(DEFAULT_RAINING);
    setWeatherType(DEFAULT_TYPE);
    currentID = ++ID;
}

Weather::Weather(int airTemp, unsigned int windSpeed, bool isRaining, string weatherType)
{
    setAirTemperature(airTemp);
    setWindSpeed(windSpeed);
    setGoingToRain(isRaining);
    setWeatherType(weatherType);
    currentID = ++ID;
}

void Weather::setAirTemperature(int n) {
    if(isTemperatureCorrect(n))
        airTemperature = n;
    else
        throw invalid_argument("Wrong temperature number! We don't live in a volcano/antarctica");
}
void Weather::setWindSpeed(unsigned int n) {
    if(isWindSpeedCorrect(n))
        windSpeed = n;
    else
        throw invalid_argument("Wrong wind speed number!");
}
void Weather::setGoingToRain(bool n) {
    goingToRain = n;
}
void Weather::setWeatherType(string n) {
    if(isTypeCorrect(n))
        weatherType = n;
    else
        throw invalid_argument("Wrong weather type!");
}
//getters
int Weather::getAirTemperature() {
    return airTemperature;
}
unsigned int Weather::getWindSpeed() {
    return windSpeed;
}
bool Weather::getGoingToRain() {
    return goingToRain;
}
string Weather::getWeatherType() {
    return weatherType;
}

bool Weather::operator==(const Weather &n) const {
    return (weatherType == n.weatherType && airTemperature == n.airTemperature && windSpeed == n.windSpeed);
}
bool Weather::operator!=(const Weather &n) const {
    return !(*this == n);
}
bool Weather::operator>(const Weather &n) const {
    return (weatherType == n.weatherType && airTemperature > n.airTemperature); //it makes more sense to compare by temperature not wind speed or both
}
bool Weather::operator<(const Weather &n) const {
    return (n > *this); // a < b, b > a
}
bool Weather::operator>=(const Weather &n) const {
    return !(n > *this);
}
bool Weather::operator<=(const Weather &n) const {
    return !(n < *this);
}
Weather &Weather::operator++() {
    ++this->airTemperature;
    return *this;
}
Weather Weather::operator++(int) {
    Weather temp = *this;
    airTemperature++;
    return temp;
}
Weather &Weather::operator--() {
    --this->airTemperature;
    return *this;
}
Weather Weather::operator--(int) {
    Weather temp = *this;
    airTemperature--;
    return temp;
}

ostream &operator<<(ostream &output, Weather &weather) {
    output << weather.toString();
    return output;
}
istream &operator>>(istream &input, Weather &weather) {
    Weather temp;
    input >> temp.airTemperature >> temp.windSpeed >> temp.goingToRain >> temp.weatherType;
    if(input.fail()) {
        throw "error";
    }
    else {
        weather.setAirTemperature(temp.airTemperature);
        weather.setWindSpeed(temp.windSpeed);
        weather.setGoingToRain(temp.goingToRain);
        weather.setWeatherType(temp.weatherType);
    }
    return input;
}


bool Weather::isTemperatureCorrect(int airTemperature) {
    if(airTemperature > 100 || airTemperature < -100)
        return false;
    else
        return true;
}
bool Weather::isWindSpeedCorrect(unsigned int windSpeed) {
    if(windSpeed > 103 || windSpeed < 0)
        return false;
    else
        return true;
}
bool Weather::isTypeCorrect(string weatherType) {
    vector<string> types = {"No info", "sunny", "cloudy", "rainy", "snowy", "stormy", "windy", "foggy", "icy", "hailing", "sleeting"};
    bool correct = false;
    int length = types.size();
    for(int i = 0; i < length; i++) {
        if(weatherType == types[i]) {
            correct = true;
            break;
        }
    }
    return correct;
}

string Weather::toString() {
    stringstream b;
    b << "ID is: "<< currentID << " Now it's " << weatherType << ". Wind speed is: " << windSpeed << "m/s, and air temperature is: " << airTemperature << " celcius. ";
    if(goingToRain)
        b << "It is going to rain soon" << endl;
    else
        b << "It is not going to rain soon" << endl;
    return b.str();
}
Weather::~Weather()
{
    //dtor
}
