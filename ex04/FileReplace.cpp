/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:34:10 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/06 23:46:31 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"
#include <string>
#include <iostream>
#include <fstream>

bool FileReplace::checkArgs(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
        return false;
    }
    if (argv[1][0] == '\0' || argv[2][0] == '\0') {
        std::cout << "Error: empty argument" << std::endl;
        return false;
    }
    return true;
}

void FileReplace::setArgs(char *argv_1, char *argv_2, char *argv_3) {
    filename = argv_1;
    s1 = argv_2;
    s2 = argv_3;
}

void FileReplace::fileReplace() {
    std::ifstream ifs(filename);
    std::ofstream ofs(filename + ".replace");
    std::string line;
    std::string::size_type n;

    if (ifs.fail()) {
        std::cerr << "Failed to open file." << std::endl;
        exit(1);
    }
    if (ofs.fail()) {
        std::cerr << "Failed to create/overwrite file: " << filename + ".replace" << std::endl;
        exit(1);
    }
    while (1) {
        std::getline(ifs, line);
        if (ifs.eof()) {
            break;
        }
		while (1) {
			n = line.find(s1);
			if (n == std::string::npos) {
				break;
			}
			ofs << line.substr(0, n) << s2;
			line = line.substr(n + s1.length());
		}
		ofs << line << std::endl;

    }
}
