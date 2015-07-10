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
    m_socket.bind(26000);
    m_socket.setBlocking(false);
}

void PacketHandler::sendConnectionRequest() {
    
    sf::Packet packet;
    sf::Int8 opcode = 1;
    packet << opcode;
    m_socket.send(packet, m_serverAddress, 26000);
}

void PacketHandler::sendMove(sf::Int32 x, sf::Int32 y) {
    sf::Packet packet;
    sf::Int8 opcode = 2;
    
    packet << opcode << m_clientID << x << y;
    m_socket.send(packet, m_serverAddress, 26000);
}

void PacketHandler::run() {
    while(true) {
    receivePacket();
    }
}

void PacketHandler::receivePacket() {
    sf::Packet packet;
    sf::Int8 opcode;
    sf::IpAddress senderAddress;
    double x;
    double y;
    unsigned short senderPort;
    
    m_socket.receive(packet, senderAddress, senderPort);
    packet >> opcode;
    
    if (opcode == 1) {
        sf::Int8 clientID;
        packet >> clientID;
        m_clientID = clientID;
    } else {
        while (packet >> x) {
            packet >> y;
            sf::RectangleShape shape(sf::Vector2f(100, 200));
            shape.setPosition(x, y);
            shape.setFillColor(sf::Color(100, 250, 50));
            m_shapes.push(shape);
        }
    }
    packet.clear();
}

std::queue<sf::RectangleShape>& PacketHandler::getShapes() {
    return m_shapes;
}

