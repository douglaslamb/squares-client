//
//  Game.cpp
//  SquaresClient
//
//  Created by rocker on 20150709.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "Game.h"

Game::Game(sf::IpAddress serverAddress): m_handler(serverAddress), m_window(sf::VideoMode(800, 800), "Squares") {
    m_window.setFramerateLimit(60);
}

void Game::start() {
    m_handler.sendConnectionRequest();
    m_handler.receivePacket();
    run();
}

void Game::run() {
    while (m_window.isOpen()) {
        // if (clock.getElapsed()
        m_handler.receivePacket();
        handleInput();
        update();
    }
}

void Game::update() {
    m_window.clear();
    // std::queue<sf::RectangleShape>* shapes = m_handler.getShapes();
    while (!m_handler.getShapes().empty()) {
        m_window.draw(m_handler.getShapes().front());
        m_handler.getShapes().pop();
    }
    m_window.display();
}

void Game::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_handler.sendMove(-1, 0);
        std::cout << "left\n";
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_handler.sendMove(1, 0);
        std::cout << "right\n";
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_handler.sendMove(0, -1);
        std::cout << "up\n";
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_handler.sendMove(0, 1);
        std::cout << "down\n";
    }
}
