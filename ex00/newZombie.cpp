/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:44:05 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/09 14:09:10 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie *aNewZombie;

	try {
		aNewZombie = new Zombie(name);
	} catch (std::bad_alloc &ba) {
		std::exit(EXIT_FAILURE);
	}
	aNewZombie->announce();
	return aNewZombie;
}