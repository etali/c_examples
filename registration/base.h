#ifndef BASE_H_
#define BASE_H_

#include <map>
#include <string>
#include <functional>

/*
 * |Example for registering a class|
 * class DerivedClass : public Base {
 *   DerivedClass(const std::string params) {}
 *   Base* Create(const std::string params) { return new DerivedClass(params); }
 * }
 * 
 * register the class
 * REGISTER_TYPE(DerivedClass, "derived class");
 *
 * not register the class
 * REGISTER_TYPE_BOOL(DerivedClass, "derived class", false);
 *
 * check whether the class is registered
 * CHECK_REGISTRATION(DerivedClass);
 */

class Base {
 public:
  // rename
  using creator = std::function<Base*(const std::string)>;
  using creators = std::map<std::string, creator>;

  virtual ~Base() {}

  static Base* Create(const std::string& id,
                      const std::string params) {
    auto iter = GetCreators().find(id);
    if (iter == GetCreators().end())
      return nullptr;
    return iter->second(params);
  }

  template<class T>
  struct Register {
    static bool AddCreator(const std::string& id,
                           const bool is_registered) {
      if (!is_registered) return false;
      auto iter = GetCreators().find(id);
      if (iter != GetCreators().end()) {
          // replace an existed creator, output warning information
      }
      GetCreators()[id] = T::Create;
      return true;
    }
    static bool IsRegistered() { return IsRegistered_; }
   private:
    static bool IsRegistered_;
  };

  static creators& GetCreators() {
    static creators s_creators;
    return s_creators;
  }
};

// Here template<> is necessary for specializations
#define REGISTER_TYPE_BOOL(T, STR, BOOL) \
    template<> bool \
    Base::Register<T>::IsRegistered_ = \
    Base::Register<T>::AddCreator(STR, BOOL)

#define REGISTER_TYPE(T, STR) \
    REGISTER_TYPE_BOOL(T, STR, true)

#define CHECK_REGISTRATION(T) \
    Base::Register<T>::IsRegistered()

#endif // BASE_H_ 
