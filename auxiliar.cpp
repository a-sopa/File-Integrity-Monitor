#include <iostream>
#include "auxiliar.hpp"
using namespace std;

void alert(std::string filename){
    std::cout << ALERT_TEXT << "Modified File: " << filename << '\n';
}

