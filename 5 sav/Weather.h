#ifndef WEATHER_H
#define WEATHER_H
#include <string.h>

class Weather
{
    private:
        class Inner;
        Inner *ptr;

    public:
        Weather(int airTemp, unsigned int windSpeed, bool isRaining, std::string weatherType);
        Weather(Weather &copyObj);
        Weather();
        virtual ~Weather();
        void initialize(int airTemp, unsigned int windSpeed, bool isRaining, std::string weatherType);
        void check(std::string file, int line) const;

        //setters
        void setAirTemperature(int n);
        void setWindSpeed(unsigned int n);
        void setGoingToRain(bool n);
        void setWeatherType(std::string n);

        //getters
        int getAirTemperature() const;
        unsigned int getWindSpeed() const;
        bool getGoingToRain() const;
        std::string getWeatherType() const;

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

        friend std::ostream& operator<<(std::ostream& output, Weather& weather);
        friend std::istream& operator>>(std::istream& input, Weather& weather);

        std::string toString();

        friend class Inner;
};

#endif // WEATHER_H
