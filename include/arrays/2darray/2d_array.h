#ifndef ARRAY_2D_H
#define ARRAY_2D_H

class Array_2d {
private:
    int **array;
    int rows, cols;
    int currentSize;

public:
    Array_2d(int r, int c);
    Array_2d();
    ~Array_2d();

    // member
    void add(int number);
    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;
    int& get(int index);
    void pop();
    void removeAt(int index);
    int& operator[](int index);

    // helper (assignment 1)
    void inputElements();
    void display() const;
    void calculateSum() const;
    void calculateAverage() const;
    void sortArray(bool ascending = true);
    void getMax() const;
    void getMin() const;
};

#endif
