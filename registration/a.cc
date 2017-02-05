#include <iostream>
#include <string>
#include "base.h"
#include "a.h"

DerivedA::DerivedA(const std::string params) {
  std::cout << "DerivedA constructor " + params + "\n";
}

Base* DerivedA::Create(const std::string params) {
  return new DerivedA(params);
}
