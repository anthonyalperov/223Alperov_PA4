#include "city.hpp"

using std::move;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::cout;
using std::endl;

//Helper
void City::parseLine(const string& line)
{
    vector<string> fields;
    string current;
    bool inQuotes = false;

    // Parse CSV line while ignoring commas inside quotes
    for (size_t i = 0; i < line.size(); ++i)
        {
        char c = line[i];

        if (c == '"')
        {
            inQuotes = !inQuotes;
        }
        else if (c == ',' && !inQuotes)
        {
            fields.push_back(current);
            current.clear();
        }
        else
        {
            current += c;
        }

        }
    fields.push_back(current);

    // Safety check
    if (fields.size() < 11)
    {
        city = "";
        country = "";
        latitude = 0.0;
        population = 0;
        return;
    }

    city = fields[0];
    country = fields[4];

    string temp = fields[2];
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());

    bool validLat = true;
    for (size_t i = 0; i < temp.size(); ++i)
        {

        char c = temp[i];
        if (!(isdigit(c) || c == '-' || c == '.'))
        {
            validLat = false;
            break;
        }
        }

    if (temp.empty() || !validLat)
    {
        latitude = 0.0;
    }
    else
    {
        latitude = stod(temp);
    }

    temp = fields[9];
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());

    bool validPop = true;
    for (size_t i = 0; i < temp.size(); ++i)
        {
            char c = temp[i];
        if (!isdigit(c))
        {
            validPop = false;
            break;
        }
        }

    if (temp.empty() || !validPop)
    {
        population = 0;
    }
    else
    {
        population = stol(temp);
    }
}


City::City()
{
    city = "";
    country = "";
    population = 0;
    latitude = 0.0;
}

// Unessacary City::~City(){}, already initallized to default

City::City(const City& other)
{
    city = other.city;
    country = other.country;
    population = other.population;
    latitude = other.latitude;
}

City& City::operator=(const City& other)
{
    if (this != &other)
    {
        city = other.city;
        country = other.country;
        population = other.population;
        latitude = other.latitude;
    }
    
    return *this;   
}

City::City(City&& other) noexcept
{
    city = move(other.city);
    country = move(other.country);
    population = other.population;
    latitude = other.latitude;
}

City& City::operator=(City&& other) noexcept
{
    if (this != &other)
    { 
        city = move(other.city);
        country = move(other.country);
        population = other.population;
        latitude = other.latitude;
    }
    return *this;
}


//Getters

string City::getCity() const
{
    return city;
}

string City::getCountry() const
{
    return country;
}

long City::getPopulation() const
{
    return population;
}

double City::getLatitude() const
{
    return latitude;
}


//Setters

void City::setCity(const string& newCity)
{
    city = newCity;
}

void City::setCountry(const string& newCountry)
{
    country = newCountry;
}

void City::setPopulation(long newPopulation)
{
    population = newPopulation;
}

void City::setLatitude(double newLatitude)
{
    latitude = newLatitude;
}


void City::readWorldCities(vector<City>& data)
{
    ifstream infile("worldcities.csv");
    string line;

    if(!infile)
    {
        cout << "Error opening file. . ." << endl;
        return;
    }

    getline(infile, line); //Skip the header line.

    while(getline(infile, line))
    {
        City city;
        city.loadParseLine(line);
        data.push_back(city);
    }

    infile.close();
}


void City::loadParseLine(const string& line)
{
    parseLine(line);
}