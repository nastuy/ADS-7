// Copyright 2021 NNTU-CS
#include "train.h"
#include <cstdlib>
#include <ctime>
Train::Train() : countOp(0), first(nullptr) {
  std::srand(std::time(0));
}
void Train::addCar(bool light) {
  Car* nc = new Car{ light, nullptr, nullptr };
  if (!first) {
    first = nc;
    nc->next = nc;
    nc->prev = nc;
  } else {
    Car* last = first->prev;
    last->next = nc;
    nc->prev = last;
    nc->next = first;
    first->prev = nc;
  }
}
int Train::getLength() {
  if (!first)
    return 0;
  if (first->next == first)
    return 1;
  countOp = 0;
  Car* current = first;
  int randomSteps = std::rand() % 10;
  for (int i = 0; i < randomSteps; i++) {
    current = current->next;
    countOp++;
  }
  current->light = true;
  countOp++;
  Car* startCar = current;
  while (true) {
    int steps = 0;
    do {
      current = current->next;
      steps++;
      countOp++;
    } while (!current->light && current != startCar);
    if (current == startCar && !current->light) {
      return steps;
    }
    current->light = false;
    countOp++;
    for (int i = 0; i < steps; i++) {
      current = current->prev;
      countOp++;
    }
    if (!current->light) {
      return steps;
    }
  }
}
int Train::getOpCount() const {
  return countOp;
}
