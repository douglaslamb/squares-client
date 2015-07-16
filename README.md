# squares-client

This is the client for Squares. Squares is a small project I did to learn local multiplayer networking. It enables up to twelve people to connect to a server and move green squares around using the arrow keys. It is written in C++ and makes heavy use of SFML. It is intended to help others who are getting into multiplayer networking and SFML.

## Warning

Squares is very rough. The program can only be exited by force quitting.

## Install

Install SFML. Build the project in XCode.

## Use

Start squares-server. On another machine start squares-client, making sure to put the ip address or hostname of squares-server in the main function of squares-client. The client will connect automatically. Sometimes the client will fail to connect. In that case force-quit the client and retry.

Directional arrows control movement of square. Squares are not visible unless moving. I think updates from the server back-up on the clients, because clients will sometimes appear to be processing updates from the server long after the player stops pressing a key.
