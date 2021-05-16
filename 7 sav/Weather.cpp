#include <iostream>
#include "Weather.h"
#include <sstream>
#include <vector>
#include "myException.h"

using namespace std;

namespace Forecast {

    class Weather::Inner {
            int airTemperature;
            unsigned int windSpeed;
            bool goingToRain;
            string weatherType;
            static int Instances;
            static int ID;
            unsigned int currentID;

            bool isTemperatureCorrect(int airTemperature);
            bool isWindSpeedCorrect(unsigned int windSpeed);
            bool isTypeCorrect(string weatherType);

            friend class Weather;
            friend std::ostream& operator<<(std::ostream& stream, const Weather& weather);
            friend std::istream& operator>>(std::istream& stream, Weather& weather);

        public:
            ~Inner();

    };

    int Weather::Inner::ID = 0;
    int Weather::Inner::Instances = 0;

    Weather::Inner::~Inner() {
        --Weather::Inner::Instances;
    }

    Weather::Weather() : ptr(NULL) {}

    Weather::Weather(Weather &copyObj) {
        Inner *temp = new Inner;
        temp->airTemperature = copyObj.getAirTemperature();
        temp->goingToRain = copyObj.getGoingToRain();
        temp->weatherType = copyObj.getWeatherType();
        temp->windSpeed = copyObj.getWindSpeed();

        this->ptr = temp;
        this->ptr->currentID = ++this->ptr->ID;
        ++this->ptr->Instances;
    }

    Weather::Weather(int airTemp, unsigned int windSpeed, bool isRaining, string weatherType)
    {
        ptr = new Weather::Inner();
        initialize(airTemp, windSpeed, isRaining, weatherType);
        this->ptr->currentID = ++this->ptr->ID;
        ++this->ptr->Instances;
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

    bool Weather::checkConditions(Weather obj) {
        if(obj.ptr->goingToRain) return true;
        if(obj.ptr->airTemperature > 35 || obj.ptr->airTemperature < -20) return true;
        if(obj.ptr->windSpeed > 20) return true;
        return false;
    }

    //setters
    void Weather::setAirTemperature(int n) {
        if(this->ptr == NULL) {
            ptr = new Inner();
            this->ptr->currentID = ++this->ptr->ID;
            ++this->ptr->Instances;
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
            ++this->ptr->Instances;
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
            ++this->ptr->Instances;
        }
        this->ptr->goingToRain = n;
    }
    void Weather::setWeatherType(string n) {
        if(this->ptr == NULL) {
            ptr = new Inner();
            this->ptr->currentID = ++this->ptr->ID;
            ++this->ptr->Instances;
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
    int Weather::getID() const {
        return ptr->currentID;
    }
    int Weather::getInstances() {
        return Weather::Inner::Instances;
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

    Weather& Weather::operator =(const Weather& weather)
    {
        if(this == &weather)
            return *this;

        Inner *temp = new Inner();

        temp->airTemperature = weather.getAirTemperature();
        temp->goingToRain = weather.getGoingToRain();
        temp->weatherType = weather.getWeatherType();
        temp->windSpeed = weather.getWindSpeed();
        temp->currentID = weather.getID();
        ++temp->Instances;

        delete this->ptr;
        this->ptr = temp;

        return *this;
    }

    ostream &operator<<(ostream &output, Weather &weather) {
        output << weather.toString();
        return output;
    }
    istream &operator>>(istream &input, Weather &weather) {
        Weather temp;
        temp.ptr = new Weather::Inner;
        input >> temp.ptr->airTemperature >> temp.ptr->windSpeed >> temp.ptr->goingToRain >> temp.ptr->weatherType;
        temp.initialize(temp.ptr->airTemperature, temp.ptr->windSpeed, temp.ptr->goingToRain, temp.ptr->weatherType);
        ++temp.ptr->Instances;

        weather = temp;
        return input;
    }

    string Weather::toString() {
        check(__FILE__, __LINE__);
        stringstream b;
        b << ptr->airTemperature << " " << ptr->windSpeed << " " << ptr->goingToRain << " " << ptr->weatherType;
        return b.str();
    }
    Weather::~Weather()
    {
        --ptr->currentID;
        delete ptr;
    }
}
