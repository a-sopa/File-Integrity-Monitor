#include <iostream>
#include <unistd.h>
#include <vector>
#include "FIM.hpp"
#include "auxiliar.hpp"

using namespace std;

int main(){
	HashMap baseline = snapshot(DIRECTORY_TO_READ);

	std::string hash;
	
	std::vector<std::string> fileList;
	int num_files = scan_directory(DIRECTORY_TO_READ, fileList);

	if (num_files < 0){
		return 1;
	}
	if (num_files == 0){
		cerr << EMPTY_DIR_ERROR << endl;
	}

	while(1){
		for (int i = 0; i < num_files; i++){
			std::optional<std::string> content = read_file(fileList[i]);
			if (!content) continue;
			hash = calculate_sha256(*content);
			if (baseline.count(fileList[i]) && baseline[fileList[i]] != hash){
				alert(fileList[i]);
			}
		}
	
		sleep(2); //Scan in between 2 seconds
	}
	return 0;
}