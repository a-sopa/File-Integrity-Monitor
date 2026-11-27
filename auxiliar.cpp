#include <iostream>
#include "FIM.hpp"
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

void fim_title(){
    std::cout << "=== File Integrity Monitor (" << DIRECTORY_TO_READ << ") ===\n\n";
}
