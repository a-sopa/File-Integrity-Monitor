#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstdlib>
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
	
	std::unordered_set<std::string> flagged_files; //Files that have been compromised

	while(1){
		system("clear");
		fim_title();

		bool compromised = false;
		for (int i = 0; i < num_files; i++){
			std::optional<std::string> content = read_file(fileList[i]);

			if (!content) continue;

			hash = calculate_sha256(*content);
			if (baseline.count(fileList[i]) && baseline[fileList[i]] != hash){
				alert(fileList[i]); //Alert the user
				compromised = true;
				flagged_files.insert(fileList[i]); //Add the file to the attention list
			}
			else if (std::find(flagged_files.begin(), flagged_files.end(), fileList[i]) != flagged_files.end()){
				attention(fileList[i]);
			}
		}
		if (!compromised){
			no_alert();
		}
		sleep(2); //Scan in between 2 seconds
	}
	return 0;
}