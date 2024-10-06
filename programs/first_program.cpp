#include "../arrays/1darray/Array.h"
#include <bits/stdc++.h>
#include <cstdlib>

class firstProgram {
public:
  firstProgram() {

    Array arr;
    int choice, element;

    int ops = 10;

    while (true) {
        ops--;
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
        arr.add(element);
        break;
      case 2:
        std::cout << "Sum of elements: " << arr.calculateSum() << "\n";
        break;
      case 3:
        std::cout << "Average of elements: " << arr.calculateAverage() << "\n";
        break;
      case 4:
        arr.sortAscending();
        std::cout << "Array sorted in ascending order.\n";
        break;
      case 5:
        arr.sortDescending();
        std::cout << "Array sorted in descending order.\n";
        break;
      case 6:
        try {
          std::cout << "Maximum value: " << arr.getMaxValue() << "\n";
        } catch (const std::exception &e) {
          std::cerr << e.what() << "\n";
        }
        break;
      case 7:
        try {
          std::cout << "Minimum value: " << arr.getMinValue() << "\n";
        } catch (const std::exception &e) {
          std::cerr << e.what() << "\n";
        }
        break;
      case 8:
        std::cout << "Array elements: ";
        for (int i = 0; i < arr.getSize(); ++i) {
          std::cout << arr[i] << " ";
        }
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