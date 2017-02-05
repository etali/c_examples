#include <iostream>
#include <string>
#include "base.h" 
#include "b.h"

DerivedB::DerivedB(const std::string params) {
  std::cout << "DerivedB constructor " + params + "\n";
}

Base* DerivedB::Create(const std::string params) {
  return new DerivedB(params);
}
