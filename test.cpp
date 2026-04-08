#include "sorting.hpp"
#include "city.hpp"
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

using std::vector;
using std::string;

int main()
{
    int count = 0;

    vector<int> testInts1 = {5, 3, 1, 4, 2};
    Sorting<int, std::less<int>> intSorter1;
    intSorter1.insertionSort(testInts1, std::less<int>());

    assert(testInts1[0] == 1);
    assert(testInts1[1] == 2);
    assert(testInts1[2] == 3);
    assert(testInts1[3] == 4);
    assert(testInts1[4] == 5);
    count++;

    vector<int> testsInts2 = {5, 1};
    Sorting<int, std::less<int>> sorter2;
    sorter2.mergeSort(testsInts2, std::less<int>());

    assert(testsInts2.size() == 2);
    assert(testsInts2[0] == 1);
    assert(testsInts2[1] == 5);
    count++;

    vector<string> testStrings = {"delta", "alpha", "charlie", "bravo"};
    Sorting<string, std::less<string>> stringSorter;
    stringSorter.mergeSort(testStrings, std::less<string>());

    assert(testStrings[0] == "alpha");
    assert(testStrings[1] == "bravo");
    assert(testStrings[2] == "charlie");
    assert(testStrings[3] == "delta");
    count++;

    vector<int> emptyVec;
    Sorting<int, std::less<int>> emptySorter;
    emptySorter.mergeSort(emptyVec, std::less<int>());

    assert(emptyVec.size() == 0);
    count++;

    vector<int> singleVec = {42};
    Sorting<int, std::less<int>> singleSorter;
    singleSorter.insertionSort(singleVec, std::less<int>());

    assert(singleVec.size() == 1);
    assert(singleVec[0] == 42);
    count++;

    vector<int> sortedVec = {1, 2, 3, 4, 5};
    Sorting<int, std::less<int>> sortedSorter;
    sortedSorter.mergeSort(sortedVec, std::less<int>());

    assert(sortedVec[0] == 1);
    assert(sortedVec[4] == 5);
    count++;

    vector<int> reverseVec = {5, 4, 3, 2, 1};
    Sorting<int, std::less<int>> reverseSorter;
    reverseSorter.insertionSort(reverseVec, std::less<int>());

    assert(reverseVec[0] == 1);
    assert(reverseVec[1] == 2);
    assert(reverseVec[2] == 3);
    assert(reverseVec[3] == 4);
    assert(reverseVec[4] == 5);
    count++;

    City c1;
    c1.setCity("Tokyo");
    c1.setCountry("Japan");
    c1.setPopulation(37732000);
    c1.setLatitude(35.6897);

    City c2;
    c2.setCity("Delhi");
    c2.setCountry("India");
    c2.setPopulation(32226000);
    c2.setLatitude(28.6600);

    City c3;
    c3.setCity("Cairo");
    c3.setCountry("Egypt");
    c3.setPopulation(21750020);
    c3.setLatitude(30.0444);

    vector<City> cityVec1 = {c1, c2, c3};

    std::function<bool(const City&, const City&)> compCity =
    [](const City& a, const City& b)
    {
    return a.getCity() < b.getCity();
    };

    Sorting<City, std::function<bool(const City&, const City&)>> citySorter1;
    citySorter1.mergeSort(cityVec1, compCity);

    assert(cityVec1[0].getCity() == "Cairo");
    assert(cityVec1[1].getCity() == "Delhi");
    assert(cityVec1[2].getCity() == "Tokyo");
    count++;

    vector<City> cityVec2 = {c1, c2, c3};

    std::function<bool(const City&, const City&)> compCountry =
    [](const City& a, const City& b)
    {
    return a.getCountry() < b.getCountry();
    };

    Sorting<City, std::function<bool(const City&, const City&)>> citySorter2;
    citySorter2.insertionSort(cityVec2, compCountry);

    assert(cityVec2[0].getCountry() == "Egypt");
    assert(cityVec2[1].getCountry() == "India");
    assert(cityVec2[2].getCountry() == "Japan");
    count++;

    vector<City> cityVec3 = {c3, c2, c1};

    std::function<bool(const City&, const City&)> compPopulation =
    [](const City& a, const City& b)
    {
    return a.getPopulation() > b.getPopulation();
    };

    Sorting<City, std::function<bool(const City&, const City&)>> citySorter3;
    citySorter3.mergeSort(cityVec3, compPopulation);

    assert(cityVec3[0].getCity() == "Tokyo");
    assert(cityVec3[1].getCity() == "Delhi");
    assert(cityVec3[2].getCity() == "Cairo");
    count++;

    vector<City> cityVec4 = {c2, c3, c1};

    std::function<bool(const City&, const City&)> compLatitude =
    [](const City& a, const City& b)
    {
    return a.getLatitude() > b.getLatitude();
    };

    Sorting<City, std::function<bool(const City&, const City&)>> citySorter4;
    citySorter4.insertionSort(cityVec4, compLatitude);

    assert(cityVec4[0].getCity() == "Tokyo");
    assert(cityVec4[1].getCity() == "Cairo");
    assert(cityVec4[2].getCity() == "Delhi");
    count++;

    if (count == 11)
    {
    std::cout << "All sorting tests passed successfully!" << std::endl;
    }
    else
    {
    std::cout << "Some tests have failed, check accordingly." << std::endl;
    }

    return 0;
}