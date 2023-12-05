/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:30:01 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/04 18:54:15 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <functional>

#define MAX_LEVEL 4
#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n"
#define INFO_MSG "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n"
#define WARNING_MSG "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n"
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now.\n"

class Harl {
private:
    void debugPrint();
    void infoPrint();
    void warningPrint();
    void errorPrint();

    typedef void (Harl::*MemFuncPtr)();
    MemFuncPtr foo[MAX_LEVEL];

public:
    Harl();
    void complain(const std::string level);

};

#endif
