#include <iostream>
#include "ExampleClass.hpp"

template<class T>
ExampleClass<T>::ExampleClass(T val) : value(val) {}

template<class T>
void ExampleClass<T>::printValue() {
    std::cout << "Value: " << value << std::endl;
}