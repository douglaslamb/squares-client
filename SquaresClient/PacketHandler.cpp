//
//  PacketHandler.cpp
//  SquaresClient
//
//  Created by rocker on 20150709.
//  Copyright (c) 2015 rocker. All rights reserved.
//

#include "PacketHandler.h"

PacketHandler::PacketHandler(sf::IpAddress serverAddress) {
    m_serverAddress = serverAddress;
    m_socket.bind(25000);
    m_socket.setBlocking(false);
}

void PacketHandler::sendConnectionRequest() {
    
    sf::Packet packet;
    sf::Int32 opcode = 1;
    packet << opcode;
    m_socket.send(packet, m_serverAddress, 26000);
    packet.clear();
    std::cout << "sent connection request\n";
}

void PacketHandler::sendMove(sf::Int32 x, sf::Int32 y) {
    sf::Packet packet;
    sf::Int32 opcode = 2;
    
    packet << opcode << m_clientID << x << y;
    m_socket.send(packet, m_serverAddress, 26000);
    packet.clear();
}

void PacketHandler::receivePacket() {
    sf::Packet packet;
    sf::Int32 opcode;
    sf::IpAddress senderAddress;
    double myX = 23;
    double myY = 7;
    unsigned short senderPort;
    
    if (m_socket.receive(packet, senderAddress, senderPort) != sf::Socket::NotReady) {
        packet >> opcode;
        std::cout << "opcode " << opcode << "\n";
        
        if (opcode == 1) {
            sf::Int32 clientID;
            packet >> clientID;
            m_clientID = clientID;
            std::cout << "client_ID " << m_clientID;
        } else {
            std::cout << "received broadcast\n";
            while (packet >> myX) {
                packet >> myY;
                std::cout << "x " << myX << "\n";
                std::cout << "y " << myY << "\n";
                sf::RectangleShape shape(sf::Vector2f(100, 200));
                
                shape.setPosition(myX, myY);
                shape.setFillColor(sf::Color(100, 250, 50));
                m_shapes.push(shape);
            }
        }
    }
    packet.clear();
}

std::queue<sf::RectangleShape>& PacketHandler::getShapes() {
    return m_shapes;
}

