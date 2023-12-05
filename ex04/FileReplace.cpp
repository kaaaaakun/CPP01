/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:34:10 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/05 20:33:31 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"

void FileReplace::performReplacement() {
    std::string content = readFileContent();

    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.replace(pos, s1.length(), s2);
        pos += s2.length();
    }

    writeFileContent(content);
}

std::string FileReplace::readFileContent() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}

void FileReplace::writeFileContent(const std::string& content) {
    std::ofstream file(filename + ".replace");
    if (!file.is_open()) {
        std::cerr << "Error: Unable to create/overwrite file: " << filename + ".replace" << std::endl;
        exit(EXIT_FAILURE);
    }

    file << content;
    file.close();

    std::cout << "Replacement successful. Result saved to " << filename + ".replace" << std::endl;
}

void	FileReplace::openFile() {
    std::ifstream ifs(filename);
    if (ifs.fail()) {
        std::cerr << "Failed to open file." << std::endl;
		exit(1);
    }
}

void	FileReplace::setArgs(char *argv_1, char *argv_2, char *argv_3) {
    filename = argv_1;
    s1 = argv_2;
    s2 = argv_3;
}
