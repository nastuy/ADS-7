// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <ctime>
#include "train.h"
double getCurrentTime() {
  return static_cast<double>(std::clock()) / CLOCKS_PER_SEC * 1000;
}
int main() {
  std::srand(std::time(0));
  std::vector<int> train_lengths;
  for (int n = 500; n <= 10000; n += 500) {
    train_lengths.push_back(n);
  }
  std::cout << "Length | All off | Time off | All on |"
    << "Time on | Random | Time random\n";
  for (int n : train_lengths) {
    Train train_off;
    for (int i = 0; i < n; ++i) train_off.addCar(false);
    double start_off = getCurrentTime();
    train_off.getLength();
    double time_off = getCurrentTime() - start_off;
    int count_off = train_off.getOpCount();
    Train train_on;
    for (int i = 0; i < n; ++i) train_on.addCar(true);
    double start_on = getCurrentTime();
    train_on.getLength();
    double time_on = getCurrentTime() - start_on;
    int count_on = train_on.getOpCount();
    Train train_rand;
    for (int i = 0; i < n; ++i) train_rand.addCar(std::rand() % 2);
    double start_rand = getCurrentTime();
    train_rand.getLength();
    double time_rand = getCurrentTime() - start_rand;
    int count_rand = train_rand.getOpCount();
    std::cout << n << "\t" << count_off << "\t" << time_off << " ms\t"
      << count_on << "\t" << time_on << " ms\t"
      << count_rand << "\t" << time_rand << " ms\n";
  }
  return 0;
}
