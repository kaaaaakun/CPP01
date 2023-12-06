/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:35:23 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/06 23:44:41 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_REPLACE_HPP
# define FILE_REPLACE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class FileReplace {
 private:
    std::string filename;
    std::string s1;
    std::string s2;

 public:
    void fileReplace();
    void setArgs(char *argv_1, char *argv_2, char *argv_3);
    bool checkArgs(int argc, char* argv[]);
};
#endif
