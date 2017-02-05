#include <iostream>
#include <string>
#include "base.h"
#include "d.h"

DerivedD::DerivedD(const std::string params) {
  std::cout << "DerivedD constructor " + params + "\n";
}

Base* DerivedD::Create(const std::string params) {
  return new DerivedD(params);
}
