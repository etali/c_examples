#ifndef BASE_H_
#define BASE_H_

#include <map>
#include <string>
#include <functional>

class Base {
 public:
  // rename
  using creator = std::function<Base*(void)>;
  using creators = std::map<std::string, creator>;

  virtual ~Base() {}

  static Base* Create(const std::string& id) {
    auto iter = GetCreators().find(id);
    if (iter == GetCreators().end())
       return nullptr;
    return iter->second();
  }

 private:
  template<class T>
  struct Register {
    static creator AddCreator(const std::string& id) {
      auto iter = GetCreators().find(id);
      if (iter != GetCreators().end()) {
          // replace an existed creator, output warning information
      }
      return GetCreators()[id] = T::Create;
    }
    static creator s_creator;
  };

  static creators& GetCreators() {
    static creators s_creators;
    return s_creators;
  }
};

// Here template<> is necessary for specializations
#define REGISTER_TYPE(T, STR) \
    template<> std::function<Base*(void)> \
    Base::Register<T>::s_creator = \
    Base::Register<T>::AddCreator(STR)

#endif // BASE_H_ 
