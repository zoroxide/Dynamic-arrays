#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>

class Array {
private:
    int* arr;       
    int capacity;   
    int size;       

    void resize(int newCapacity);

public:
    Array(int initialCapacity = 4);

    Array(std::initializer_list<int> initList);

    ~Array();

    int getSize() const;

    int getCapacity() const;

    bool isEmpty() const;

    void add(int element);

    int& get(int index);

    void remove();

    void removeAt(int index);

    void display() {}

    int& operator[](int index);

    // assignment 1
    int calculateSum() const;
    double calculateAverage() const;
    void sortAscending();
    void sortDescending();
    int getMaxValue() const;
    int getMinValue() const;
};

#endif
