#include <iostream>
#include "base.h"
#include "registration_list.h"

int main(int argc, char *argv[]) {
  if (argc >= 1) {
    for (int i = 1; i < argc; ++i) {
      Base* tmp = Base::Create(argv[i]);
      if (tmp == nullptr)
        std::cout << argv[i] << ":nullptr" << std::endl;
      else
        delete tmp;
    }
  } 
  // delete Base::Create("A");
  // delete Base::Create("Bee");
  // delete Base::Create("sea");
  // delete Base::Create("DEE");
  return 0;
}
