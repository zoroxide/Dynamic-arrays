#include "2d_array.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

Array_2d::Array_2d(int r, int c) : rows(r), cols(c), currentSize(0) {
    array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols]();
    }
}

Array_2d::Array_2d() : rows(0), cols(0), array(nullptr), currentSize(0) {}

Array_2d::~Array_2d() {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

int Array_2d::getSize() const {
    return currentSize;
}

int Array_2d::getCapacity() const {
    return rows * cols;
}

bool Array_2d::isEmpty() const {
    return currentSize == 0;
}

void Array_2d::add(int element) {
    if (currentSize >= getCapacity()) {
        throw std::out_of_range("Array is full");
    }

    int rowIndex = currentSize / cols;
    int colIndex = currentSize % cols;
    array[rowIndex][colIndex] = element;
    currentSize++;
}

int& Array_2d::get(int index) {
    if (index < 0 || index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }

    int rowIndex = index / cols;
    int colIndex = index % cols;
    return array[rowIndex][colIndex];
}

void Array_2d::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Array is empty");
    }

    currentSize--;
}

void Array_2d::removeAt(int index) {
    if (index < 0 || index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }

    int rowIndex = index / cols;
    int colIndex = index % cols;

    for (int i = index; i < currentSize - 1; ++i) {
        int nextRowIndex = (i + 1) / cols;
        int nextColIndex = (i + 1) % cols;
        array[rowIndex][colIndex] = array[nextRowIndex][nextColIndex];
        rowIndex = nextRowIndex;
        colIndex = nextColIndex;
    }
    currentSize--;
}

int& Array_2d::operator[](int index) {
    return get(index);
}

void Array_2d::inputElements() {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cin >> array[i][j];
    }
  }
}

void Array_2d::display() const {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << std::setw(5) << array[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Array_2d::calculateSum() const {
  int totalSum = 0;

  for (int i = 0; i < rows; ++i) {
    int rowSum = 0;
    for (int j = 0; j < cols; ++j) {
      rowSum += array[i][j];
      totalSum += array[i][j];
    }
    std::cout << "Row " << i + 1 << ": " << rowSum << std::endl;
  }

  for (int j = 0; j < cols; ++j) {
    int colSum = 0;
    for (int i = 0; i < rows; ++i) {
      colSum += array[i][j];
    }
    std::cout << "Column " << j + 1 << ": " << colSum << std::endl;
  }

  std::cout << "Total Sum of all elements: " << totalSum << std::endl;
}

void Array_2d::calculateAverage() const {
  int totalElements = rows * cols;
  int totalSum = 0;

  for (int i = 0; i < rows; ++i) {
    int rowSum = 0;
    for (int j = 0; j < cols; ++j) {
      rowSum += array[i][j];
      totalSum += array[i][j];
    }
    std::cout << "Row " << i + 1 << ": " << static_cast<double>(rowSum) / cols
              << std::endl;
  }

  for (int j = 0; j < cols; ++j) {
    int colSum = 0;
    for (int i = 0; i < rows; ++i) {
      colSum += array[i][j];
    }
    std::cout << "Column " << j + 1 << ": "
              << static_cast<double>(colSum) / rows << std::endl;
  }

  std::cout << "Average of all elements: "
            << static_cast<double>(totalSum) / totalElements << std::endl;
}

void Array_2d::sortArray(bool ascending) {
  int *flatArray = new int[rows * cols];
  int index = 0;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      flatArray[index++] = array[i][j];
    }
  }

  if (ascending) {
    std::sort(flatArray, flatArray + rows * cols);
  } else {
    std::sort(flatArray, flatArray + rows * cols, std::greater<int>());
  }

  index = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      array[i][j] = flatArray[index++];
    }
  }

  delete[] flatArray;
  display();
}

void Array_2d::getMax() const {
  for (int i = 0; i < rows; ++i) {
    int maxRow = array[i][0];
    for (int j = 1; j < cols; ++j) {
      if (array[i][j] > maxRow) {
        maxRow = array[i][j];
      }
    }
    std::cout << "Row " << i + 1 << ": " << maxRow << std::endl;
  }

  for (int j = 0; j < cols; ++j) {
    int maxCol = array[0][j];
    for (int i = 1; i < rows; ++i) {
      if (array[i][j] > maxCol) {
        maxCol = array[i][j];
      }
    }
    std::cout << "Column " << j + 1 << ": " << maxCol << std::endl;
  }

  int maxAll = array[0][0];
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (array[i][j] > maxAll) {
        maxAll = array[i][j];
      }
    }
  }

  std::cout << "Maximum value of all elements: " << maxAll << std::endl;
}

void Array_2d::getMin() const {
  for (int i = 0; i < rows; ++i) {
    int minRow = array[i][0];
    for (int j = 1; j < cols; ++j) {
      if (array[i][j] < minRow) {
        minRow = array[i][j];
      }
    }
    std::cout << "Row " << i + 1 << ": " << minRow << std::endl;
  }

  for (int j = 0; j < cols; ++j) {
    int minCol = array[0][j];
    for (int i = 1; i < rows; ++i) {
      if (array[i][j] < minCol) {
        minCol = array[i][j];
      }
    }
    std::cout << "Column " << j + 1 << ": " << minCol << std::endl;
  }

  int minAll = array[0][0];
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (array[i][j] < minAll) {
        minAll = array[i][j];
      }
    }
  }

  std::cout << "Minimum value of all elements: " << minAll << std::endl;
}