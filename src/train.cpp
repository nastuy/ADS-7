// Copyright 2021 NNTU-CS
#include <cstdlib>
#include <ctime>
#include "train.h"
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
  if (!first->light) {
    first->light = true;
  }
  int steps = 0;
  Car* current = first;
  while (true) {
    steps = 0;
    do {
      current = current->next;
      steps++;
      countOp++;
    } while (!current->light && current != first);
    current->light = false;
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
