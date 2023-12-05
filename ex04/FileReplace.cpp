/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:34:10 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/05 17:38:23 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"

FileReplace::FileReplace(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

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

void	FileReplace::openFile(std::string filename) {
    std::ifstream ifs(filename);

    if (ifs.fail()) {
        std::cerr << "Failed to open file." << std::endl;
		exit -1;
    }
}

