#ifndef B_H_
#define B_H_

#include "base.h"

class DerivedB : public Base {
 public:
  DerivedB();
  static Base* Create();
};


#endif // B_H_
