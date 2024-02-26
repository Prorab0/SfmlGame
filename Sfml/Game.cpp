#include "Game.h"
#include "Resources.h"
#include "Map.h"




using namespace std;

Map mapp (16.0f);
Camera camera(320.0f);


void Begin(const sf::Window& window)
{
	//przeszkuje wszystkie pliki z tego folderu /resources/textures/ Jak wsadzisz do innego folderu to masz wpierdol
	for (auto& file : filesystem::directory_iterator("./resources/textures/"))
	{
		if(file.is_regular_file() && file.path().extension() == ".png" ||
			file.path().extension() == ".jpg")
		{
			if (!Resources::textures[file.path().filename().string()].loadFromFile(
				file.path().string())) 
			{
				cout << "kurwa";
			}
			
		}
	}
	sf::Image image;
	image.loadFromFile("map.png");
	mapp.CreateFromImage(image);

}

void Update(float deltaTime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		camera.position.x += movementSpeed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		camera.position.x -= movementSpeed * deltaTime;
}
//renderuje tekstury na razie block z minecraftu
void Render(Renderer& renderer)
{
	mapp.Draw(renderer);
}

