#include "../../include/arrays/2darray/2d_array.h"
#include <iostream>

class secondProgram {
private:
  int choice;
  int element;
  int index;

public:
  secondProgram() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    Array_2d myArray(rows, cols);
    std::cout << "\n_________________\n";

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
      std::cout << "9. Get size\n";
      std::cout << "10. Get capacity\n";
      std::cout << "11. Check if array is empty\n";
      std::cout << "12. Get element at index\n";
      std::cout << "13. Remove last element\n";
      std::cout << "14. Remove element at index\n";
      std::cout << "16. Exit\n";
      std::cout << "Choose an option: ";

      std::cin >> choice;

      switch (choice) {
      case 1:
        std::cout << "Enter element to add: ";
        std::cin >> element;
        try {
          myArray.add(element);
        } catch (const std::exception &e) {
          std::cerr << e.what() << "\n";
        }
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
        std::cout << "Array elements: \n";
        myArray.display();
        std::cout << "\n";
        break;
      case 9:
        std::cout << "Size of array: " << myArray.getSize() << "\n";
        break;
      case 10:
        std::cout << "Capacity of array: " << myArray.getCapacity() << "\n";
        break;
      case 11:
        std::cout << (myArray.isEmpty() ? "Array is empty\n"
                                        : "Array is not empty\n");
        break;
      case 12:
        std::cout << "Enter index: ";
        std::cin >> index;
        try {
          std::cout << "Element at index " << index << ": "
                    << myArray.get(index) << "\n";
        } catch (const std::exception &e) {
          std::cerr << e.what() << "\n";
        }
        break;
      case 13:
        try {
          myArray.pop();
          std::cout << "Last element removed.\n";
        } catch (const std::exception &e) {
          std::cerr << e.what() << "\n";
        }
        break;
      case 14:
        std::cout << "Enter index to remove element: ";
        std::cin >> index;
        try {
          myArray.removeAt(index);
          std::cout << "Element at index " << index << " removed.\n";
        } catch (const std::exception &e) {
          std::cerr << e.what() << "\n";
        }
        break;
      case 16:
        std::cout << "Exiting...\n";
        exit(0);
      default:
        std::cout << "Invalid option. Please try again.\n";
      }
    }
  }
};
