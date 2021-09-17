#include "module1.h"
#include "module2.h"
#include <iostream>
using namespace std;
int main() {

    std::cout << "Hello, World!" << std::endl;
    std::cout << Module1::getMyName() << std::endl;
    std::cout << Module2::getMyName() << std::endl;

    using namespace Module1;
    std::cout << getMyName() << std::endl;
    std::cout << Module2::getMyName() << std::endl;

    using Module2::getMyName;
    std::cout << getMyName() << std::endl;

    return 0;
}
