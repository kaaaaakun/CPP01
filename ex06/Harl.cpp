/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:30:13 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/07 14:54:36 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

typedef void (*FuncPtr)();

Harl::Harl() {
    foo[0] = &Harl::debugPrint;
    foo[1] = &Harl::infoPrint;
    foo[2] = &Harl::warningPrint;
    foo[3] = &Harl::errorPrint;
}

void    Harl::complain(const std::string level) {
    std::string levels[MAX_LEVEL] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    size_t i = 0;
    for (; i < MAX_LEVEL ; i++) {
        if (levels[i] == level) {
            break;
        }
    }
    switch (i)
    {
        case DEBUG:
            debugPrint();
        case INFO:
            infoPrint();
        case WARNING:
            warningPrint();
        case ERROR:
            errorPrint();
            break;
        default:
            std::cerr << "Unknown level: " << level << std::endl;
            break;
    }
}

void Harl::debugPrint() {
    std::cout << DEBUG_MSG << std::endl;
}

void Harl::infoPrint() {
    std::cout << INFO_MSG << std::endl;
}

void Harl::warningPrint() {
    std::cout << WARNING_MSG << std::endl;
}

void Harl::errorPrint() {
    std::cout << ERROR_MSG << std::endl;
}
