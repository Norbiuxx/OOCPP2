#include <iostream>
#include "Weather.h"
#include <sstream>
#include <vector>
#include "myException.h"

#define DEFAULT_TEMP 0
#define DEFAULT_SPEED 0
#define DEFAULT_RAINING false
#define DEFAULT_TYPE "No info"

using namespace std;

class Weather::Inner {
        int airTemperature;
        unsigned int windSpeed;
        bool goingToRain;
        string weatherType;
        static int ID;
        unsigned int currentID;

        bool isTemperatureCorrect(int airTemperature);
        bool isWindSpeedCorrect(unsigned int windSpeed);
        bool isTypeCorrect(string weatherType);

        friend class Weather;
};

int Weather::Inner::ID = 0;

Weather::Weather() : ptr(NULL) {}

Weather::Weather(Weather &copyObj) {
    Inner *temp = new Inner;
    temp->airTemperature = copyObj.getAirTemperature();
    temp->goingToRain = copyObj.getGoingToRain();
    temp->weatherType = copyObj.getWeatherType();
    temp->windSpeed = copyObj.getWindSpeed();

    this->ptr = temp;
    this->ptr->currentID = ++this->ptr->ID;
}

Weather::Weather(int airTemp, unsigned int windSpeed, bool isRaining, string weatherType)
{
    ptr = new Weather::Inner();
    initialize(airTemp, windSpeed, isRaining, weatherType);
    this->ptr->currentID = ++this->ptr->ID;
}

void Weather::initialize(int airTemp, unsigned int windSpeed, bool isRaining, string weatherType) {
    setAirTemperature(airTemp);
    setWindSpeed(windSpeed);
    setGoingToRain(isRaining);
    setWeatherType(weatherType);
}

void Weather::check(string file, int line) const {
    if(ptr == NULL) throw myException(file, line);
}

//setters
void Weather::setAirTemperature(int n) {
    if(this->ptr == NULL) {
        ptr = new Inner();
        this->ptr->currentID = ++this->ptr->ID;
    }

    if(this->ptr->isTemperatureCorrect(n))
        this->ptr->airTemperature = n;
    else
        throw invalid_argument("Wrong temperature number!");
}
void Weather::setWindSpeed(unsigned int n) {
    if(this->ptr == NULL) {
        ptr = new Inner();
        this->ptr->currentID = ++this->ptr->ID;
    }

    if(this->ptr->isWindSpeedCorrect(n))
        this->ptr->windSpeed = n;
    else
        throw invalid_argument("Wrong wind speed number!");
}
void Weather::setGoingToRain(bool n) {
    if(this->ptr == NULL) {
        ptr = new Inner();
        this->ptr->currentID = ++this->ptr->ID;
    }
    this->ptr->goingToRain = n;
}
void Weather::setWeatherType(string n) {
    if(this->ptr == NULL) {
        ptr = new Inner();
        this->ptr->currentID = ++this->ptr->ID;
    }

    if(this->ptr->isTypeCorrect(n))
        this->ptr->weatherType = n;
    else
        throw invalid_argument("Wrong weather type!");
}
//getters
int Weather::getAirTemperature() const {
    check(__FILE__, __LINE__);
    return ptr->airTemperature;
}
unsigned int Weather::getWindSpeed() const {
    check(__FILE__, __LINE__);
    return ptr->windSpeed;
}
bool Weather::getGoingToRain() const {
    check(__FILE__, __LINE__);
    return ptr->goingToRain;
}
string Weather::getWeatherType() const {
    check(__FILE__, __LINE__);
    return ptr->weatherType;
}

//checkers
bool Weather::Inner::isTemperatureCorrect(int airTemperature) {
    if(airTemperature > 100 || airTemperature < -100)
        return false;
    else
        return true;
}
bool Weather::Inner::isWindSpeedCorrect(unsigned int windSpeed) {
    if(windSpeed > 103 || windSpeed < 0)
        return false;
    else
        return true;
}
bool Weather::Inner::isTypeCorrect(string weatherType) {
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

bool Weather::operator==(const Weather &n) const{
    check(__FILE__, __LINE__);
    return (this->getWeatherType() == n.getWeatherType() && this->getAirTemperature() == n.getAirTemperature() && this->getGoingToRain() == n.getGoingToRain() && this->getWindSpeed() == n.getWindSpeed());
}
bool Weather::operator!=(const Weather &n) const {
    check(__FILE__, __LINE__);
    return !(*this == n);
}
bool Weather::operator>(const Weather &n) const {
    check(__FILE__, __LINE__);
    return (this->getAirTemperature() > n.getAirTemperature());
}
bool Weather::operator<(const Weather &n) const {
    check(__FILE__, __LINE__);
    return (n > *this);
}
bool Weather::operator>=(const Weather &n) const {
    check(__FILE__, __LINE__);
    return !(n > *this);
}
bool Weather::operator<=(const Weather &n) const {
    check(__FILE__, __LINE__);
    return !(n < *this);
}
Weather &Weather::operator++() {
    check(__FILE__, __LINE__);
    ++ptr->airTemperature;
    return *this;
}
Weather Weather::operator++(int) {
    check(__FILE__, __LINE__);
    Weather temp = *this;
    ++ptr->airTemperature;
    return temp;
}
Weather &Weather::operator--() {
    check(__FILE__, __LINE__);
    --ptr->airTemperature;
    return *this;
}
Weather Weather::operator--(int) {
    check(__FILE__, __LINE__);
    Weather temp = *this;
    --ptr->airTemperature;
    return temp;
}

ostream &operator<<(ostream &output, Weather &weather) {
    output << weather.toString();
    return output;
}
istream &operator>>(istream &input, Weather &weather) {
    int tempAirTemperature;
    unsigned int tempWindSpeed;
    bool tempGoingToRain;
    string tempWeatherType;
    input >> tempAirTemperature >> tempWindSpeed >> tempGoingToRain >> tempWeatherType;
    if(input.fail()) {
        throw "Error while trying to input";
    }
    else {
        weather.initialize(tempAirTemperature, tempWindSpeed, tempGoingToRain, tempWeatherType);
    }
    return input;
}

string Weather::toString() {
    check(__FILE__, __LINE__);
    stringstream b;
    b << "ID is: "<< ptr->currentID << " Now it's " << ptr->weatherType << ". Wind speed is: " << ptr->windSpeed << "m/s, and air temperature is: " << ptr->airTemperature << " celcius. ";
    if(ptr->goingToRain)
        b << "It is going to rain soon" << endl;
    else
        b << "It is not going to rain soon" << endl;
    return b.str();
}
Weather::~Weather()
{
    --ptr->currentID;
    delete ptr;
}
