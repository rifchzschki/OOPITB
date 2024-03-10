#ifndef EXAMPLECLASS_HPP
#define EXAMPLECLASS_HPP

template<class T>
class ExampleClass {
public:
    ExampleClass(T val);
    void printValue();
private:
    T value;
};

// #include "ExampleClass.cpp"  // Include the implementation file at the end of the header

#endif