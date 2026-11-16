#include <iostream>
#include <unistd.h>
#include "FIM.hpp"
#include "auxiliar.hpp"
using namespace std;


int main(){
	while(1){
		alert("teste.txt");
		sleep(2); //Scan in between 2 seconds
	}
	return 0;
}