#ifndef C_H_
#define C_H_

#include <string>
#include "base.h"

class DerivedC : public Base {
 public:
  DerivedC(const std::string params);
  static Base* Create(const std::string params);
};

#endif // C_H_
