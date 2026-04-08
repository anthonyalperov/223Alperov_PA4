#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <iomanip>

#include "timer.hpp"
#include "city.hpp"
#include "sorting.hpp"

using std::cout; 
using std::endl;   

void handleSortCommand(const std::string& algorithmName, const std::string& fieldName, const std::vector<City>& masterData) 
{
    vector<City> data = masterData;

    std::function<bool(const City&, const City&)> comp;

if (fieldName == "population")
{
        comp = [](const City& a, const City& b) 
        {
        return a.getPopulation() > b.getPopulation();
        };
}
else if (fieldName == "city")
    {
        comp = [](const City& a, const City& b)
        {
        return a.getCity() < b.getCity();
        };
    }
else if (fieldName == "country")
{
        comp = [](const City& a, const City& b) 
        {
        return a.getCountry() < b.getCountry();
        };
}
else if (fieldName == "latitude")
{
    comp = [](const City& a, const City& b) 
    {
    return a.getLatitude() > b.getLatitude();
    };
}


Timer timer;
timer.start();

if (algorithmName == "insertionSort")
{
Sorting<City, decltype(comp)> sorter;
sorter.insertionSort(data, comp);
}
else
{
Sorting<City, decltype(comp)> sorter;
sorter.mergeSort(data, comp);
}

timer.stop();



for (int i = 0; i < 10 && i < data.size(); i++)
{
cout << i + 1 << ". "
<< data[i].getCity() << ", "
<< data[i].getCountry() << ", "
<< data[i].getPopulation() << ", "
<< data[i].getLatitude() << endl;
}


cout << "Elapsed time: " << std::fixed << std::setprecision(2) << timer.elapsedMilliseconds() << " ms\n";
}


int main() {
    
    //Testing for Demo
    vector<int> VideoDemo = {5,3,1,4,2};
    Sorting<int, std::less<int>> sorter;

    //Insertion demo
    sorter.insertionSort(VideoDemo, std::less<int>());

    //Merge demo
     sorter.mergeSort(VideoDemo, std::less<int>());

    vector<City> cities;
    City temp;
    temp.readWorldCities(cities);
    std::cout<< "Loaded " << cities.size() << " cities." << std::endl;
    // ---- REPL: Do not modify below this line ----

    std::string line;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) {
            break; // EOF
        }

        // Trim leading whitespace
        size_t start = line.find_first_not_of(" \t");
        if (start == std::string::npos) continue;
        line = line.substr(start);

        if (line == "quit" || line == "exit") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        // Parse command: <algorithm> <field>
        std::istringstream iss(line);
        std::string algorithm, field;
        iss >> algorithm >> field;

        if (algorithm.empty() || field.empty()) {
            std::cout << "Usage: <algorithm> <field>" << std::endl;
            std::cout << "  Algorithms: insertionSort, mergeSort" << std::endl;
            std::cout << "  Fields: population, city, country, latitude"
                      << std::endl;
            std::cout << "  Or type 'quit' to exit." << std::endl;
            continue;
        }

        // Validate algorithm name
        if (algorithm != "insertionSort" && algorithm != "mergeSort") {
            std::cout << "Unknown algorithm: " << algorithm << std::endl;
            std::cout << "Valid algorithms: insertionSort, mergeSort"
                      << std::endl;
            continue;
        }

        // Validate field name
        if (field != "population" && field != "city" &&
            field != "country" && field != "latitude") {
            std::cout << "Unknown field: " << field << std::endl;
            std::cout << "Valid fields: population, city, country, latitude"
                      << std::endl;
            continue;
        }

       handleSortCommand(algorithm, field, cities);

        std::cout << std::endl;
    }

    return 0;
}
