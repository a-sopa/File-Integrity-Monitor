#include <iostream>
#include <unistd.h>
#include "FIM.hpp"
#include "auxiliar.hpp"
using namespace std;


int main(){
	std::string content, hash, filename;
	std::string abs_path = DIRECTORY_TO_READ;

	while(1){
		content = read_file("config.txt");
		hash = calculate_sha256(content);
		std::cout << hash << endl;
		sleep(2); //Scan in between 2 seconds
	}
	return 0;
}