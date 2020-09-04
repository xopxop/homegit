/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 09:21:04 by dthan             #+#    #+#             */
/*   Updated: 2020/09/04 10:51:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.hpp"

Player::Player() {
	this->_m_Speed = this->_START_SPEED;
	this->_m_Health = this->_START_HEALTH;
	this->_m_MaxHealth = this->_START_HEALTH;

	//Associate a texture with the sprite
	this->_m_Texture.loadFromFile("graphics/player.png");
	this->_m_Sprite.setTexture(this->_m_Texture);

	//Set the origin of the sprite to the center,
	//for smooth rotation
	this->_m_Sprite.setOrigin(25, 25);
}

void Player::spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize) {
	//Place the player in the middle of the arena
	this->_m_Position.x = arena.width / 2;
	this->_m_Position.y = arena.height / 2;

	//Copy the details of the arena to the player's m_Arena
	this->_m_Arena.left = arena.left;
	this->_m_Arena.width = arena.width;
	this->_m_Arena.top = arena.top;
	this->_m_Arena.height = arena.height;

	//Remember how big the tiles are in this arena
	this->_m_TileSize = tileSize;

	//Store the resolution for the fure use
	this->_m_Resolution.x = resolution.x;
	this->_m_Resolution.y = resolution.y;
}

void Player::resetPlayerStats(void) {
	this->_m_Speed = this->_START_SPEED;
	this->_m_Health = this->_START_HEALTH;
	this->_m_MaxHealth = this->_START_HEALTH;
}

sf::Time Player::getLastHitTime(void) {
	return this->_m_LastHit;
}

bool Player::hit(sf::Time timeHit) {
	if (timeHit.asMilliseconds() - this->_m_LastHit.asMilliseconds() > 200) {
		this->_m_LastHit = timeHit;
		this->_m_Health -= 10;
		return true;
	} else {
		return false;
	}
}

sf::FloatRect Player::getPosition(void) {
	return this->_m_Sprite.getGlobalBounds();
}

sf::Vector2f Player::getCenter(void) {
	return this->_m_Position;
}

float Player::getRotation(void) {
	return this->_m_Sprite.getRotation();
}

sf::Sprite Player::getSprite(void) {
	return this->_m_Sprite;
}

int Player::getHealth(void) {
	return this->_m_Health;
}

void Player::moveLeft(void) {
	this->_m_LeftPressed = true;
}

void Player::moveRight(void) {
	this->_m_RightPressed = true;
}

void Player::moveUp(void) {
	this->_m_UpPressed = true;
}

void Player::moveDown(void) {
	this->_m_DownPressed = true;
}

void Player::stopLeft(void) {
	this->_m_LeftPressed = false;
}

void Player::stopRight(void) {
	this->_m_RightPressed = false;
}

void Player::stopUp(void) {
	this->_m_UpPressed = false;
}

void Player::stopDown(void) {
	this->_m_DownPressed = false;
}

void Player::update(float elapsedTime, sf::Vector2i mousePosition) {
	if(this->_m_UpPressed) {
		this->_m_Position.y -= this->_m_Speed * elapsedTime;
	}
	if (this->_m_DownPressed) {
		this->_m_Position.y += this->_m_Speed * elapsedTime;
	}
	if (this->_m_RightPressed) {
		this->_m_Position.x += this->_m_Speed * elapsedTime;
	}
	if (this->_m_LeftPressed) {
		this->_m_Position.x -= this->_m_Speed * elapsedTime;
	}

	this->_m_Sprite.setPosition(this->_m_Position);

	//Keep the player in the arena
	if (this->_m_Position.x > this->_m_Arena.width - this->_m_TileSize) {
		this->_m_Position.x = this->_m_Arena.width - this->_m_TileSize;
	}
	if (this->_m_Position.x < this->_m_Arena.left + this->_m_TileSize) {
		this->_m_Position.x = this->_m_Arena.left + this->_m_TileSize;
	}
	if (this->_m_Position.y > this->_m_Arena.height - this->_m_TileSize) {
		this->_m_Position.y = this->_m_Arena.height - this->_m_TileSize;
	}
	if (this->_m_Position.y < this->_m_Arena.top + this->_m_TileSize) {
		this->_m_Position.y = this->_m_Arena.top + this->_m_TileSize;
	}

	//Calculate the angle the player is facing
	float angle = (atan2(mousePosition.y - this->_m_Resolution.y / 2,
		mousePosition.x - this->_m_Resolution.x / 2) * 180) / 3.14;
	
	this->_m_Sprite.setRotation(angle);
}

void Player::upgradeSpeed(void) {
	//20% speed upgrade
	this->_m_Speed += (this->_START_SPEED * .2);
}

void Player::upgradeHealth(void) {
	this->_m_MaxHealth += (this->_START_HEALTH * .2);
}

void Player::increaseHealthLevel(int amount) {
	this->_m_Health += amount;

	//But not beyond the maximum
	if (this->_m_Health > this->_m_MaxHealth) {
		this->_m_Health = this->_m_MaxHealth;
	}
}
