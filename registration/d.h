#ifndef D_H_
#define D_H_

#include <string>
#include "base.h"

class DerivedD : public Base {
 public:
  DerivedD(const std::string params);
  static Base* Create(const std::string params);
};

#endif // D_H_
