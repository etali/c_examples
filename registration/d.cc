#include <iostream>
#include "base.h"
#include "d.h"

DerivedD::DerivedD() {
  std::cout << "D::DerivedD constructor\n";
}

Base* DerivedD::Create() {
  return new DerivedD();
}
