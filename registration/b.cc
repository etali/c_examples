#include <iostream>
#include "base.h" 
#include "b.h"

DerivedB::DerivedB() {
  std::cout << "B::DerivedB constructor\n";
}

Base* DerivedB::Create() {
  return new DerivedB();
}
