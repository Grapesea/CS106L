/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <iostream>
#include <stdexcept>
void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  Juice j1;

  Juice j2("lemonade", "cs106", 10, 5);

  Juice j3(j1);
}