## Factory registration example

When you need to implement a derived class from class Base,
you only need to register the derived class with REGISTER_TYPE(derived_class, "name")

Then, you can create a the derived class by calling Base::Create("name")

*Reference:* http://stackoverflow.com/questions/6137706/automatic-registration-of-object-creator-function-with-a-macro
