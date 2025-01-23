#include <iostream>
#include "hello.h"
#include "goodbye.h"

#include "config.hpp"

int main() {
    std::cout << "Project name: " << project_name << " version: " << project_version << std::endl;
    hello();
    goodbye(); // test here
    return 0;
}