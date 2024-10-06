#ifndef ARRAY_2D_H
#define ARRAY_2D_H

class Array_2d {
private:
  int **array;
  int rows, cols;

public:
  Array_2d(int r, int c);
  Array_2d();
  ~Array_2d();

  void inputElements();
  void display() const;
  void calculateSum() const;
  void calculateAverage() const;
  void sortArray(bool ascending = true);
  void getMax() const;
  void getMin() const;
};

#endif
