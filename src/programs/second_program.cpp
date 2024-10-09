#include "../../include/arrays/2darray/2d_array.h"
#include <iostream>

class secondProgram {
private:
  int choice;
  int element;

public:
  secondProgram() {

    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    Array_2d myArray(rows, cols);
    std::cout<<"\n_________________\n";

    while (true) {
      std::cout << "\nMenu:\n";
      std::cout << "1. Add element\n";
      std::cout << "2. Calculate sum\n";
      std::cout << "3. Calculate average\n";
      std::cout << "4. Sort in ascending order\n";
      std::cout << "5. Sort in descending order\n";
      std::cout << "6. Get maximum value\n";
      std::cout << "7. Get minimum value\n";
      std::cout << "8. Display elements\n";
      std::cout << "9. Exit\n";
      std::cout << "Choose an option: ";

      std::cin >> choice;

      switch (choice) {
      case 1:
        std::cout << "Enter element to add: ";
        std::cin >> element;
        myArray.add(element);
        break;
      case 2:
        myArray.calculateSum();
        break;
      case 3:
        myArray.calculateAverage();
        break;
      case 4:
        myArray.sortArray(true);
        std::cout << "Array sorted in ascending order.\n";
        break;
      case 5:
        myArray.sortArray(false);
        std::cout << "Array sorted in descending order.\n";
        break;
      case 6:
        try {
          myArray.getMax();
        } catch (const std::exception &e) {
          std::cerr << e.what() << "\n";
        }
        break;
      case 7:
        try {
          myArray.getMin();
        } catch (const std::exception &e) {
          std::cerr << e.what() << "\n";
        }
        break;
      case 8:
        std::cout << "Array elements: ";
        myArray.display();
        std::cout << "\n";
        break;
      case 9:
        std::cout << "Exiting...\n";
        break;
        exit(0);
      default:
        std::cout << "Invalid option. Please try again.\n";
      }
    }
  }
};