#include "../arrays/2darray/2d_array.h"
#include <iostream>

class secondProgram {
public:
  secondProgram() {

    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    Array_2d myArray(rows, cols);
    myArray.inputElements();
    myArray.display();

    myArray.calculateSum();
    myArray.calculateAverage();
    myArray.sortArray(true);
    std::cout << "\n";
    myArray.sortArray(false);
    myArray.getMax();
    myArray.getMin();
  }
};