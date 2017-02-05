#include "base.h"
#include "a.h"

DerivedA::DerivedA() {
  std::cout << "A::DerivedA constructor\n";
}

Base* DerivedA::Create() {
  return new DerivedA();
}
