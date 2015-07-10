//
//  Game.h
//  SquaresClient
//
//  Created by rocker on 20150709.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#ifndef __SquaresClient__Game__
#define __SquaresClient__Game__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "PacketHandler.h"

class Game {
    
private:
    sf::RenderWindow m_window;
    PacketHandler m_handler;
    
public:
    
    Game(sf::IpAddress serverAddress);
    void start();
    void run();
    void update();
    void handleInput();
    
};

#endif /* defined(__SquaresClient__Game__) */
