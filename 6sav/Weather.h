#ifndef WEATHER_H
#define WEATHER_H
#include <string>

using std::string;

namespace Forecast
{

    //! Class that contains information about weather
    class Weather
    {
        private:
            //! Inner class that contains main weather's variables
            class Inner;
            Inner *ptr;

        public:
            //! Basic constructor to create an object with all it's properties
            Weather(int airTemp, unsigned int windSpeed, bool isRaining, std::string weatherType);
            //! Deep copy constructor
            Weather(Weather &copyObj);
            //! Empty constructor for lazy initialization
            Weather();
            virtual ~Weather();
            //! Initializes an object by assigning all values to it
            void initialize(int airTemp, unsigned int windSpeed, bool isRaining, std::string weatherType);
            //! Checks if the pointer to Inner class exists, if not, it throws a custom exception
            void check(std::string file, int line) const;

            //setters
            //! Sets air temperature for weather the object
            void setAirTemperature(int n);
            //! Sets wind speed for weather the object
            void setWindSpeed(unsigned int n);
            //! Sets a boolean whether its going to rain for the weather object
            void setGoingToRain(bool n);
            //! Sets weather type for weather the object
            void setWeatherType(std::string n);

            //getters
            int getAirTemperature() const;
            unsigned int getWindSpeed() const;
            bool getGoingToRain() const;
            std::string getWeatherType() const;

            //! Compares two weather objects by all variables
            bool operator==(const Weather &n) const;
            //! Compares two weather objects by all variables
            bool operator!=(const Weather &n) const;
            //! Compares whether the first object's air temperature is higher than the second object's
            bool operator>(const Weather &n) const;
            //! Compares whether the first object's air temperature is higher than the second object's
            bool operator<(const Weather &n) const;
            //! Compares whether the first object's air temperature is more or equal than the second object's
            bool operator>=(const Weather &n) const;
            //! Compares whether the first object's air temperature is less or equal than the second object's
            bool operator<=(const Weather &n) const;
            //! Pre increment operation used to increase air temperature by one
            Weather &operator++();
            //! Post increment operation used to increase air temperature by one
            Weather operator++(int);
            //! Pre decrement operation used to decrease air temperature by one
            Weather &operator--();
            //! Post decrement operation used to decrease air temperature by one
            Weather operator--(int);

            //! Outputs the object referring to the toString() method
            friend std::ostream& operator<<(std::ostream& output, Weather& weather);
            //! Used to read input from a user in format: air temperature, wind speed, going to rain, weather type
            friend std::istream& operator>>(std::istream& input, Weather& weather);

            //! Outputs the object in string format
            std::string toString();

            friend class Inner;
    };
}
#endif // WEATHER_H
