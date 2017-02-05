#ifndef BASE_H_
#define BASE_H_

#include <map>
#include <string>
#include <functional>

class Base {
 public:
  // rename
  using creator = std::function<Base*(const std::string)>;
  using creators = std::map<std::string, creator>;

  virtual ~Base() {}

  static Base* Create(const std::string& id, const std::string params) {
    auto iter = GetCreators().find(id);
    if (iter == GetCreators().end())
       return nullptr;
    return iter->second(params);
  }

 private:
  template<class T>
  struct Register {
    static bool AddCreator(const std::string& id) {
      auto iter = GetCreators().find(id);
      if (iter != GetCreators().end()) {
          // replace an existed creator, output warning information
      }
      GetCreators()[id] = T::Create;
      return true;
    }

    // flag for registeration;
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
#define REGISTER_TYPE(T, STR) \
    template<> bool \
    Base::Register<T>::IsRegistered_ = \
    Base::Register<T>::AddCreator(STR)

#endif // BASE_H_ 
