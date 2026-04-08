#ifndef SORTING_HPP
#define SORTING_HPP


#include "city.hpp"

using std::vector;

template<typename T, typename Comparator>
class Sorting
{
    public:

        Sorting() = default; // Constructor
        ~Sorting() = default; // Destructor
      //Not needed kept for good practice: Sorting(const Sorting& other); // Copy Constructor
      //Not needed kept for good practice: Sorting& operator=(const Sorting& other); // Copy Assingment
      //Not needed kept for good practice: Sorting(Sorting&& other) noexcept; // Move Constructor
      //Not needed kept for good practice: Sorting& operator=(Sorting&& other) noexcept; //Move Assingment


    //members 
    void insertionSort(vector<T>& data, Comparator comp);
    void mergeSort(vector<T>& data, Comparator comp);

};

template<typename T, typename Comparator>
void Sorting<T, Comparator>::insertionSort(vector<T>&data, Comparator comp)
{
    int j;
    T key;

    for(int i = 1; i < data.size(); i++)
    {
        key = data[i];
        j = i - 1;

      while(j >= 0 && comp(key, data[j]))
        {
          data[j + 1] = data[j];
          j--;
        }
      
        data[j + 1] = key;
    }
}

template<typename T, typename Comparator>
void Sorting<T, Comparator>::mergeSort(vector<T>&data, Comparator comp)
{

    if(data.size() <= 1)
    {
      return;
    }

    int mid = data.size() / 2;
    vector<T> left;
    vector<T> right;
    
    for (int i = 0; i < mid; i++)
      {
        left.push_back(data[i]);
      }
    
    for (int i = mid; i < data.size(); i++)
      {
        right.push_back(data[i]);
      }

      mergeSort(left, comp);
      mergeSort(right, comp);

      size_t i = 0, j = 0, k = 0;

      while (i < left.size() && j < right.size())
      {
        
        if (comp(left[i], right[j]))
        {
          data[k++] = left[i++];
        }
        else
        {
          data[k++] = right[j++];
        }
      }

      while(i < left.size())
      {
        data[k++] = left[i++];
      }

      while(j < right.size())
      {
        data[k++] = right[j++];   
      }
}


#endif