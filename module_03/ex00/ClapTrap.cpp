/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: digoncal                                     +:+ +:+         +:+     */
/*   <digoncal@student.42porto.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Project:                                          #+#    #+#             */
/*   -> C++ Modules                                   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "Default constructor called\n";
	hitPoints = 10;
	energy = 10;
	atk = 0;
}

ClapTrap::ClapTrap(const ClapTrap &value) {
	std::cout << "Copy constructor called\n";
	*this = value;
}

ClapTrap::ClapTrap(const std::string& name) {
	std::cout << "Copy constructor with params called\n";
	this->name = name;
	hitPoints = 10;
	energy = 10;
	atk = 0;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &value) {
	std::cout << "Copy assignment operator called\n";
	this->name = value.name;
	this->hitPoints = value.hitPoints;
	this->energy = value.energy;
	this->atk = value.atk;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called\n";
}

void	ClapTrap::attack(const std::string& target) {
	if (energy > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << atk << " points of damage!\n";
		energy--;
	}
	else
		std::cout << "ClapTrap " << name << " can't attack\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0)
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";

	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energy > 0)
	{
		std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points\n";
		hitPoints += amount;
		energy--;
	}
}
