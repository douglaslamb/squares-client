//
//  PacketHandler.h
//  SquaresClient
//
//  Created by rocker on 20150709.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#ifndef __SquaresClient__PacketHandler__
#define __SquaresClient__PacketHandler__

#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <queue>

class PacketHandler {
    
private:
    sf::IpAddress m_serverAddress;
    sf::UdpSocket m_socket;
    std::queue<sf::RectangleShape> m_shapes;
    sf::Int32 m_clientID;
    
public:
    PacketHandler(sf::IpAddress serverAddress);
    void sendConnectionRequest();
    void sendMove(sf::Int32 x, sf::Int32 y);
    // probably delete run() void run();
    void receivePacket();
    std::queue<sf::RectangleShape>& getShapes();
};


#endif /* defined(__SquaresClient__PacketHandler__) */
