#include "game.h"
#include "world.h"
#include <iostream>
#include "utils.h"
using std::getline;
using std::endl;
using std::cout;
using std::cin;
Game::Game(Life** life, int numLife) {
	m_steps = 0;
	m_automate = false;
	m_world = new World();

	if (life != nullptr) {
		for (int i = 0; i < numLife; i++) {
			if (life[i] != nullptr) {
				bool success = m_world->initLife(life[i]);
				if (!success) {
					cout << "Failed to add life to the world" << endl;
				}
			}
		}
	}
}
Game::~Game() {
	delete m_world;
}

void Game::game_loop() {
	while (true) {
		m_world->print();

		if (!m_automate) {
			cout << "command (<space> to step, <a> to automate, <q> to quit): ";

			string action;
			getline(cin, action);

			switch (action[0])
			{
			default:
				cout << '\a' << std::endl;  // beep
				continue;
			case 'q':
				std::cout << "Quitting Game." << std::endl;
				return;
			case 's':

				continue;
			case ' ':

				break;
			case 'a':
				m_automate = true;
				break;
			}
		}
		else {
			if (m_steps >= MAX_STEPS) {
				std::cout << "Reached max steps, quitting." << std::endl;
				return;
			}
			delay(300);
		}
		m_steps++;

		m_world->updateWorld();
	}
}