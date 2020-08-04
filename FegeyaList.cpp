/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <cstring>
#include <FileSystemPlusPlus.h>

void HelpFunction() {
	std::cout << "Fegeya List\nlsf (--a || --all) : Lists current directory\n";
}

int main(int argc, char** argv) {
	if(argc > 1) {
        	for(int i = 1; i < argc; i++) {
			std::string arg(argv[i]);
			if(arg.substr(0, 2) == "--") {
				if(arg == "--a" || arg ==  "--all") {
					fsplusplus::List();
				} else if(arg == "--f" || arg == "--file") {
					// List only file.
				} else if(arg == "--h" || arg == "--help") {
					HelpFunction();
				} else {
					HelpFunction();
				}
			} else {
				fsplusplus::List();
			}
		}
        } else {
        	fsplusplus::List();
	}
}
