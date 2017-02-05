#ifndef C_H_
#define C_H_

#include "base.h"

class DerivedC : public Base {
 public:
  DerivedC();
  static Base* Create();
};

#endif // C_H_
