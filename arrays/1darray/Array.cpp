#include "Array.h"
#include <bits/stdc++.h>

Array::Array(int initialCapacity) {
  if (initialCapacity <= 0) {
    throw std::invalid_argument("Capacity must be greater than zero");
  }
  arr = new int[initialCapacity];
  capacity = initialCapacity;
  size = 0;
}

Array::Array(std::initializer_list<int> initList) {
  size = initList.size();
  capacity = size > 0 ? size : 4;
  arr = new int[capacity];

  int i = 0;
  for (int value : initList) {
    arr[i++] = value;
  }
}

Array::~Array() { delete[] arr; }

void Array::resize(int newCapacity) {
  int *newArr = new int[newCapacity];
  for (int i = 0; i < size; i++) {
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
  capacity = newCapacity;
}

int Array::getSize() const { return size; }

int Array::getCapacity() const { return capacity; }

bool Array::isEmpty() const { return size == 0; }

void Array::add(int element) {
  if (size == capacity) {
    resize(2 * capacity);
  }
  arr[size++] = element;
}

int &Array::get(int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }
  return arr[index];
}

void Array::remove() {
  if (size > 0) {
    size--;
  }
}

void Array::removeAt(int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }
  for (int i = index; i < size - 1; i++) {
    arr[i] = arr[i + 1];
  }
  size--;
}

int &Array::operator[](int index) { return get(index); }

int Array::calculateSum() const {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

double Array::calculateAverage() const {
  if (size == 0)
    return 0.0;
  return static_cast<double>(calculateSum()) / size;
}

void Array::sortAscending() { std::sort(arr, arr + size); }

void Array::sortDescending() {
  std::sort(arr, arr + size, std::greater<int>());
}

int Array::getMaxValue() const {
  if (size == 0)
    throw std::runtime_error("Array is empty");
  return *std::max_element(arr, arr + size);
}

int Array::getMinValue() const {
  if (size == 0)
    throw std::runtime_error("Array is empty");
  return *std::min_element(arr, arr + size);
}
