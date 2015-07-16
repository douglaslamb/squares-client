
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // NOTE IMPT! Replace "localhost" with the ip address
    // or host name of the server you are connecting to
    // unless you are running client and server on the same machine.
    sf::IpAddress address = "localhost";
    Game game(address);
    game.start();
    // i'm wrtingi the client so that the server ip can be entered

    return EXIT_SUCCESS;
}
