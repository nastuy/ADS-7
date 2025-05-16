// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "train.h"
int main() {
  std::srand(std::time(0));
  std::vector<int> train_lengths;
  for (int n = 100; n <= 1500; n += 100) {
    train_lengths.push_back(n);
  }
  std::cout << "Train length | All off | All on | Random\n";
  for (int n : train_lengths) {
    Train train_off;
    for (int i = 0; i < n; ++i) train_off.addCar(false);
    int ops_off = train_off.getLength();
    int count_off = train_off.getOpCount();
    Train train_on;
    for (int i = 0; i < n; ++i) train_on.addCar(true);
    int ops_on = train_on.getLength();
    int count_on = train_on.getOpCount();
    Train train_rand;
    for (int i = 0; i < n; ++i) train_rand.addCar(std::rand() % 2);
    int ops_rand = train_rand.getLength();
    int count_rand = train_rand.getOpCount();
    std::cout << n << "\t\t" << count_off << "\t\t" << count_on << "\t\t" << count_rand << "\n";
  }
  return 0;
}
