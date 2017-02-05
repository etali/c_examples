#ifndef D_H_
#define D_H_

#include "base.h"

class DerivedD : public Base {
 public:
  DerivedD();
  static Base* Create();
};

#endif // D_H_
