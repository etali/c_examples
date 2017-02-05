#ifndef REGISTRATION_LIST_H_
#define REGISTRATION_LIST_H_

#include "base.h"

#include "a.h"
REGISTER_TYPE(DerivedA, "A");
#include "b.h"
REGISTER_TYPE(DerivedB, "B");
#include "c.h"
REGISTER_TYPE(DerivedC, "C");
#include "d.h"
REGISTER_TYPE_BOOL(DerivedD, "D", false);

#endif // REGISTRATION_LIST_H_
