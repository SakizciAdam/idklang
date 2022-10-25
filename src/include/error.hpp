#include <iostream>

void error(std::string n,std::string error="fatal error"){
    std::cout << "\033[31m" << error << ": " << "\033[0m" << n << std::endl;

    
    exit(1);
}
