/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:35:23 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/05 17:38:21 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class FileReplace {
public:
    std::ifstream ifs;
    void performReplacement();

private:
    std::string filename;
    std::string s1;
    std::string s2;

    void    openFile(std::string filename);
    std::string readFileContent();
    void writeFileContent(const std::string& content);
};


