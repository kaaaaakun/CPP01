/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:46:14 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/05 20:34:12 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"

int main(int argc, char* argv[]) {
    FileReplace fr;
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;    return 1;
    }
    fr.setArgs(argv[1], argv[2], argv[3]);
    fr.openFile();
    fr.fileReplace();
    return 0;
}