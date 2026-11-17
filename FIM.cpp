#include "FIM.hpp"
#include <iostream>
#include <filesystem>
#include <fcntl.h>
#include <unistd.h>
#include <openssl/evp.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

//sha256sum File-Integrity-Monitor/main.cpp

namespace fs = std::filesystem;

std::string scan_directory(const std::string &dir_path){
	if (!fs::exists(dir_path) || !fs::is_directory(dir_path)){
		std::cerr << "INVALID DIRECTORY" << dir_path << std::endl;
		return;
	}

	for (const auto &entry : fs::recursive_directory_iterator(dir_path, fs::directory_options::skip_permission_denied)){
		if (entry.is_regular_file()){
			std::string filepath = entry.path().string();
			return filepath;
		}
	}
	return EMPTY_DIR_ERROR;
}

std::string read_file(const std::string &filepath){
	char buffer[BUFFER_MAX];
	
	int fd = open(filepath.c_str(), O_RDONLY);

	if (fd < 0){
		perror(FILE_OPEN_ERROR);
		return FILE_OPEN_ERROR;
	}

	std::string content;
	ssize_t bytes_read;

	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0){
		content.append(buffer, bytes_read);
	}

	close(fd);
	return content;
}

std::string calculate_sha256(const std::string &file_data){
	EVP_MD_CTX* ctx = EVP_MD_CTX_new(); //Allocate memory
	EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr); //Initialize the sha256 algorithm

	EVP_DigestUpdate(ctx, file_data.data(), file_data.size()); //Process the data

	unsigned char hash[EVP_MAX_MD_SIZE];
	unsigned int hash_len = 0;
	EVP_DigestFinal_ex(ctx, hash, &hash_len); //Extract the result to hash

	EVP_MD_CTX_free(ctx); //Free the memory

	//Convert the 32 bytes to a 64 Hexadecimal character String
	std::stringstream ss;
	for (unsigned i = 0; i < hash_len; i++){
		//convert to hexa -> 1 byte = 2 (hexa)digits ->  fill the extra digit with 0 if necessary
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	}
	return ss.str();
}