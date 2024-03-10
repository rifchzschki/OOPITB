#include <iostream>

using namespace std;

class A{
    public:
        virtual void f(){
            cout << "ini dari A" <<endl;
        }
        void a(){
            cout << "Halo dari A" <<endl;

        }
};

class B: public A {
    public:
        void f(int A){
            cout << "ini dari B" << A <<endl;
        }
        // void f(){
        //     cout << "ini dari B" <<endl;
        // }
        virtual void ayam(){
            cout << "ini dari ayam B" <<endl;
        }
};

class C: public virtual B{
    public:
        void f(){
            cout << "ini dari C" <<endl;
        }
        void ayam(){
            cout << "ini dari ayam C" <<endl;
        }
};

class D: virtual public B{
        void f(){
            cout << "ini dari D" <<endl;
        }
        // void ayam(){
        //     cout << "ini dari ayam D" <<endl;
        // }

};

class C1: public virtual C{
        void f(){
            cout << "ini dari C1" <<endl;
        }

};

// class E: public C1, public D{

// };

// #define mmin(a,b) ((a) < (b) ? (a) : (b))

// T2 myFunc (T2 a, T2 b) {return a+b ;} /* error: T1 bukan bagian dari
// signature */



int main(){
    // E e;
    // A& b = e;
    // b.f();
    // b.a();
    // cout <<myFunc <int, float> (1.02,2);
    // if(myFunc <int, float> (1.02,2)==3.02){
    // }
    ExampleClass<int> intObject(5);
    intObject.printValue();

    ExampleClass<double> doubleObject(3.14);
    doubleObject.printValue();
}
// struct A {
// virtual void f();
// };
// struct VB1: virtual A {
// void f(); // overrides A::f
// };
// struct VB2: virtual A {
// void f(); // overrides A::f
// };
// struct Error: VB1, VB2 {
// // Error A::f has two final overriders in Error
// };
// struct Okay: VB1, VB2 {
// void f(); // OK: this is the final overrider for A::f
// };
// struct VB1a: virtual A {}; // does not declare an overrider
// struct Da: VB1a, VB2 {
// // in Da, the final overrider of A::f is VB2::f
// };


// struct B {
// virtual void f();
// };
// struct D: B {
// void f(int); // D::f hides B::f (wrong parameter list)
// };
// struct D2: D {
// void f(); // D2::f overrides B::f (doesn't matter that it's not visible)
// };
// int main() {
// B b; B& b_as_b = b;
// D d; B& d_as_b = d; D& d_as_d = d;
// D2 d2; B& d2_as_b = d2; D& d2_as_d = d2;
// b_as_b.f(); // calls B::f()
// d_as_b.f(); // calls B::f()
// d2_as_b.f(); // calls D2::f()
// d_as_d.f(); // Error: lookup in D finds only f(int)
// d2_as_d.f(); // Error: lookup in D finds only f(int)
// }
