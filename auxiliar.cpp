#include <iostream>
#include "auxiliar.hpp"
using namespace std;

void alert(std::string filename){
    std::cout << ALERT_TEXT << "Modified File: " << filename << '\n';
}

void no_alert(){
    std::cout << OK_TEXT << '\n';
}

void attention(std::string filename){
    std::cout << ATTENTION_TEXT << filename << '\n';
}
