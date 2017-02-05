#include <iostream>
#include <string>
#include "base.h"
#include "c.h"

DerivedC::DerivedC(const std::string params) {
  std::cout << "DerivedC constructor " + params + "\n";
}

Base* DerivedC::Create(const std::string params) {
  return new DerivedC(params);
}
