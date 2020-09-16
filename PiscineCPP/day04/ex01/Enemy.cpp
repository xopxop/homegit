/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:20:56 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:47:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

/* Coplien's form */
Enemy::Enemy(void) { }

Enemy::Enemy(int hp, std::string const & type)
{
	this->_hp = hp;
	this->_type = type;
}

Enemy::Enemy(Enemy const & src)
{
	this->_hp = src.getHP();
	this->_type = src.getType();	
}

Enemy::~Enemy(void) { }

Enemy & Enemy::operator = (Enemy const & rhs)
{
	if (this != &rhs)
	{
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return (*this);
}

/* Accessor */

std::string Enemy::getType(void) const
{
	return (this->_type);
}

int Enemy::getHP(void) const
{
	return (this->_hp);
}

void Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	this->_hp -= damage;
	if (this->_hp <= 0)
		delete this;
}
