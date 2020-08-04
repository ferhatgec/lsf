/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <cstring>
#include <FileSystemPlusPlus.h>
#include <FegeyaList.hpp>

void HelpFunction() {
	std::cout << "Fegeya List Arguments\nlsf (--a || --all) : List current directory\n" << 
	"lsf  --ia <file> : List all files and folders from current directory with input\n" << 
	"lsf --if <file> : List only file with input\n" <<
	"lsf --id <file> : List only directory with input\n" <<   
	"lsf --f || --file : List current directory without folders.\n" <<
	"lsf --d || --dir : List current directory without files\n" <<
	"lsf --v || --version : Show version.\n";
}

void VersionFunction() {
	std::cout << "Fegeya List - " << FEGEYA_LIST_VERSION << "\n";
}

int main(int argc, char** argv) {
	std::string copy_arg, reg;
	if(argc > 1) {
        	for(int i = 1; i < argc; i++) {
			std::string arg(argv[i]);
			reg = argv[1];
			copy_arg = arg;
		}
	
        } else {
        	fsplusplus::List();
	}
	
	if(reg.substr(0, 2) == "--") {
		if(reg == "--a" || reg ==  "--all") { // List all files and folders from current directory with input
			fsplusplus::List();
		} else if(strstr(reg.c_str(), "--ia")) { 
			fsplusplus::ListPath(true, true, copy_arg);
		} else if(reg == "--f" || reg == "--file") { // List only file from current directory with input.				
			fsplusplus::ListFile();
		} else if(reg == "--d" || reg == "--dir") { // List only directory from current directory with input.				
			fsplusplus::ListDirectory();
		} else if(strstr(reg.c_str(), "--if")) { // List only file with input
			fsplusplus::ListPath(false, true, copy_arg); 
		} else if(strstr(reg.c_str(), "--id")) { // List only directory with input.
			fsplusplus::ListPath(true, false, copy_arg); 
		} else if(reg == "--h" || reg == "--help") {
			HelpFunction();
		} else if(reg == "--v" || reg == "--version") {
			VersionFunction();
		} else {
			HelpFunction();
		}
	}
	return 0;
}
