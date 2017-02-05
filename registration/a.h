#ifndef A_H_
#define A_H_

#include <string>
#include "base.h"

class DerivedA : public Base {
 public:
  DerivedA(const std::string params);
  static Base* Create(const std::string params);
};

#endif // A_H_
