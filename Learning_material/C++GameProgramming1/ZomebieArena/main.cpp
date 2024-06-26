/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 07:54:50 by dthan             #+#    #+#             */
/*   Updated: 2020/09/04 13:38:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include "player.hpp"

int main() {
	// The game will always be in one of four states
	enum class State {
		PAUSED, LEVELING_UP, GAME_OVER, PLAYING
	};

	//Start with the GAME_OVER state
	State state = State::GAME_OVER;

	//Get the screen resolution and create an SFML windo
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Zombie Arena", sf::Style::Fullscreen);

	//Create a an SFML view for the main action
	sf::View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	//Here is our clock for timing everything
	sf::Clock clock;
	
	//How long has the PLAYING state been active
	sf::Time gameTimeTotal;
	
	//Where is the mouse in relation to world coordinates
	sf::Vector2f mouseWorldPosition;
	//Where is the mouse in relation to screen coordinates
	sf::Vector2i mouseScreenPosition;

	//Create an instance of the Player class

	Player player;

	//The boundaries of the arena
	sf::IntRect arena;

	//The main loop
	while (window.isOpen()) {
		/*
		******************
		Handle Input
		******************
		*/

		//Handle events
		sf::Event event;
		state = State::PLAYING;
		// while (window.pollEvent(event)) {
		// 	if (event.type == sf::Event::KeyPressed) {
		// 		// Pause a game while playing
		// 		if (event.key.code == sf::Keyboard::Return && state == State::PLAYING) {
		// 			state = State::PAUSED;
		// 		}
		// 		//Restart while pause
		// 		else if (event.key.code == sf::Keyboard::Return && state == State::PAUSED) {
		// 			state = State::PLAYING;
		// 			// Reset the clock so there isnt a frame jump
		// 			clock.restart();
		// 		} // Start a new game while in GAME_OVER state
		// 		else if (event.key.code == sf::Keyboard::Return && state == State::GAME_OVER) {
		// 			state = State::LEVELING_UP;
		// 		}

		// 		if (state == State::PLAYING) { }
		// 	}
		// } //End event polling

		// Handle the player quitting
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		//Handle controls while playing
		if (state == State::PLAYING) {
			//Handle the pressing and releasing of the WASD keys
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				player.moveUp();
			} else {
				player.stopUp();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				player.moveDown();
			} else {
				player.stopDown();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				player.moveLeft();
			} else {
				player.stopLeft();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				player.moveRight();
			} else {
				player.stopRight();
			}
		} // Ends WASD while playing

		if (state == State::LEVELING_UP) {
			//Handle the player levelling up
			if (event.key.code == sf::Keyboard::Num1) {
				state = State::PLAYING;
			}

			if (event.key.code == sf::Keyboard::Num2) {
				state = State::PLAYING;
			}

			if (event.key.code == sf::Keyboard::Num3) {
				state = State::PLAYING;
			}

			if (event.key.code == sf::Keyboard::Num4) {
				state = State::PLAYING;
			}

			if (event.key.code == sf::Keyboard::Num5) {
				state = State::PLAYING;
			}

			if (event.key.code == sf::Keyboard::Num6) {
				state = State::PLAYING;
			}

			if (state == State::PLAYING) {
				//Prepare the level
				//We will modify the next two lines later
				arena.width = 500;
				arena.height = 500;
				arena.left = 0;
				arena.top = 0;

				// We will modify this line of code later
				int tileSize = 50;

				//Spawn the player in the middle of the arena
				player.spawn(arena, resolution, tileSize);

				//Reset the clock so there isnt a frame jump
				clock.restart();
			}
		} // End leveling up

		/*
		*******************
		UPDATE THE FRAME
		*******************
		*/
		if (state == State::PLAYING) {
			//Update the delta time
			sf::Time dt = clock.restart();
			//Update the total game time
			gameTimeTotal += dt;
			//Make a decimal fraction of 1 from the delta time
			float dtAsSeconds = dt.asSeconds();

			//Where is the mouse pointer
			mouseScreenPosition = sf::Mouse::getPosition();

			//Convert mouse position to world coordinates of the mainView
			mouseWorldPosition = window.mapPixelToCoords(sf::Mouse::getPosition(), mainView);

			//Update the player
			player.update(dtAsSeconds, sf::Mouse::getPosition());

			//Make a note of the players new position
			sf::Vector2f playerPosition(player.getCenter());

			//Make the view center around the player
			mainView.setCenter(player.getCenter());
		} //End updating the scene

		/*
		************************
		Draw the scene
		************************
		*/

		if (state == State::PLAYING) {
			window.clear();

			//set the mainView to be displayed in the window
			//and draw everything related to it
			window.setView(mainView);

			//Draw the player
			window.draw(player.getSprite());
		}

		if (state == State::LEVELING_UP) {

		}

		if (state == State::PAUSED) {

		}

		if (state == State::GAME_OVER) {
			
		}

		window.display();

	} //End game loop
	return 0;
}
