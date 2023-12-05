/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:30:13 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/04 17:00:15 by tokazaki         ###   ########.fr       */
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
    for (size_t i = 0; i < MAX_LEVEL ; i++) {
        if (levels[i] == level)
        {
            (this->*foo[i])();
            return ;
        }
    }
    std::cerr << "Unknown level: " << level << std::endl;
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