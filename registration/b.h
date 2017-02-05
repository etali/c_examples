#ifndef B_H_
#define B_H_

#include <string>
#include "base.h"

class DerivedB : public Base {
 public:
  DerivedB(const std::string params);
  static Base* Create(const std::string params);
};


#endif // B_H_
