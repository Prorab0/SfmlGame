
//#include <string> // not used for now
#include <iostream>

#include "Game.h"
#include "Camera.h"
#include "Renderer.h"


// don't forget to include your own header



int main() {

    sf::RenderWindow window(sf::VideoMode(1200, 900), "Platformer");
    sf::Clock deltaClock;
    
    Renderer renderer(window);

    window.setFramerateLimit(60);

    Begin(window);
    while(window.isOpen())
    {
        float deltaTime = deltaClock.restart().asSeconds();

        sf::Event event{};
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.setView(camera.GetView(window.getSize()));
        Update(deltaTime);
        window.clear(sf::Color(20,20,20));
        Render(renderer);
        window.display();

    }

    return 0;
}


