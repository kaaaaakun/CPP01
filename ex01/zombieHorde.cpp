/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:14:02 by tokazaki          #+#    #+#             */
/*   Updated: 2023/12/09 14:11:30 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *NewZombies;

	try {
		NewZombies = new Zombie[N];
	} catch (std::bad_alloc &ba) {
		std::exit(EXIT_FAILURE);
	}
	for (int i = 0; i < N; i++) {
		NewZombies[i].set_name(name);
	}
	return (NewZombies);
}
