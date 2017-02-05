#include <iostream>
#include "base.h"
#include "c.h"

DerivedC::DerivedC() {
  std::cout << "C::DerivedC constructor\n";
}

Base* DerivedC::Create() {
  return new DerivedC();
}
