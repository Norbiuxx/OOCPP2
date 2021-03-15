#ifndef WEATHER_H
#define WEATHER_H
#include <string.h>

using namespace std;

class Weather
{
    public:
        Weather(int airTemp, unsigned int windSpeed, bool isRaining, string weatherType);
        Weather();
        virtual ~Weather();

        //setters
        void setAirTemperature(int n);
        void setWindSpeed(unsigned int n);
        void setGoingToRain(bool n);
        void setWeatherType(string n);

        //getters
        int getAirTemperature();
        unsigned int getWindSpeed();
        bool getGoingToRain();
        string getWeatherType();

        bool operator==(const Weather &n) const;
        bool operator!=(const Weather &n) const;
        bool operator>(const Weather &n) const;
        bool operator<(const Weather &n) const;
        bool operator>=(const Weather &n) const;
        bool operator<=(const Weather &n) const;
        Weather &operator++();
        Weather operator++(int);
        Weather &operator--();
        Weather operator--(int);

        friend ostream& operator<<(ostream& output, Weather& weather);
        friend istream& operator>>(istream& input, Weather& weather);

        bool isTemperatureCorrect(int airTemperature);
        bool isWindSpeedCorrect(unsigned int windSpeed);
        bool isTypeCorrect(string weatherType);
        string toString();

    protected:

    private:
        int airTemperature;
        unsigned int windSpeed;
        bool goingToRain;
        string weatherType;
        static int ID;
        unsigned int currentID;
};

#endif // WEATHER_H
