/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 09:04:37 by dthan             #+#    #+#             */
/*   Updated: 2020/09/04 10:51:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
# include <SFML/Graphics.hpp>
# include <cmath>

class Player {
	private:
		const float _START_SPEED = 200;
		const float _START_HEALTH = 100;
		//Where is the player
		sf::Vector2f _m_Position;
		//Of course we will need a sprite
		sf::Sprite _m_Sprite;
		//And a texture
		//!!Watch this space!!
		sf::Texture _m_Texture;
		//What is the screen resolution
		sf::Vector2f _m_Resolution;
		//What size of the current arena
		sf::IntRect _m_Arena;
		//How big is each tile of arena
		int _m_TileSize;
		//Which direction is the player currently moving in
		bool _m_UpPressed;
		bool _m_DownPressed;
		bool _m_LeftPressed;
		bool _m_RightPressed;
		//How much health has the player got?
		int _m_Health;
		//What is the maximum health the player can have?
		int _m_MaxHealth;
		//When was the player last hit
		sf::Time _m_LastHit;
		//Speed in pixels per second
		float _m_Speed;

	public:
		Player();
		void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);
		//Call this at the end of every game
		void resetPlayerStats(void);
		//Handle the player getting hit by a zombie
		bool hit(sf::Time timeHit);
		//How long ago was the player last hit
		sf::Time getLastHitTime(void);
		//Where is the player
		sf::FloatRect getPosition(void);
		//Where is the center of the player
		sf::Vector2f getCenter(void);
		//Which angle is the player facing
		float getRotation(void);
		//Send a copy of the sprite to main
		sf::Sprite getSprite(void);
		//The next four functions move the player
		void moveLeft(void);
		void moveRight(void);
		void moveUp(void);
		void moveDown(void);
		//Stop the player moving in a specific direction
		void stopLeft(void);
		void stopRight(void);
		void stopUp(void);
		void stopDown(void);
		//We will call this function once every frame
		void update(float elapsedTime, sf::Vector2i mousePosition);
		//Give the player speed boost
		void upgradeSpeed(void);
		//Give the player some health
		void upgradeHealth(void);
		//Increase the maximum amount of health the player can have
		void increaseHealthLevel(int amount);
		//How much health has the player currently got?
		int getHealth(void);
};

#endif
