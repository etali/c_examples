#ifndef A_H_
#define A_H_

#include <iostream>
#include "base.h"

class DerivedA : public Base {
 public:
  DerivedA();
  static Base* Create();
};

#endif // A_H_
