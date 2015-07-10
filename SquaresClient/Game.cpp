//
//  Game.cpp
//  SquaresClient
//
//  Created by rocker on 20150709.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "Game.h"

Game::Game(sf::IpAddress serverAddress): m_handler(serverAddress), m_window(sf::VideoMode(800, 800), "Squares") {
}

void Game::start() {
    m_handler.sendConnectionRequest();
    m_handler.run();
    // m_window = sf::RenderWindow(sf::VideoMode(800, 800), "Squares");
    run();
}

void Game::run() {
    while (true) {
        handleInput();
        update();
    }
}

void Game::update() {
    m_window.clear();
    std::queue<sf::RectangleShape> shapes = m_handler.getShapes();
    while (!shapes.empty()) {
        m_window.draw(shapes.front());
        shapes.pop();
    }
    m_window.display();
}

void Game::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_handler.sendMove(-1, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_handler.sendMove(1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_handler.sendMove(0, -1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_handler.sendMove(0, 1);
    }
}
