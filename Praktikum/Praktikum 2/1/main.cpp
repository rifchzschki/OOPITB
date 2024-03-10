#include "A.hpp"
#include "B.hpp"

int main() {
    B b;

    // Start editing here :D
    // ...
    // ...
    b.setMe(200);
    b.A::setMe(10);
    
    b.print();
    return 0;
}