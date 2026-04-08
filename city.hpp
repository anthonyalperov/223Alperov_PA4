#ifndef CITY_HPP
#define CITY_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>


using std::string;
using std::vector;

class City
{
    private:

    string city; //Name
    string country; //Name
    long population; //Count
    double latitude; //Coords

    //helper functions if needed below:
    void parseLine(const string& line);

    public:

    City(); // Constructor
    ~City() = default; // Destructor
    City(const City& other); // Copy Constructor
    City& operator=(const City& other); // Copy Assingment
    City(City&& other) noexcept; // Move Constructor
    City& operator=(City&& other) noexcept; //Move Assingment


    //getters
    string getCity() const;
    string getCountry() const;
    long getPopulation() const;
    double getLatitude() const;

    //setters
    void setCity(const string& newCity);
    void setCountry(const string& newCountry);
    void setPopulation(long newPopulation);
    void setLatitude(double newLatitude);


    //members
    void readWorldCities(vector<City>& data);
    void loadParseLine(const string& line); // Needed for helper


};


#endif