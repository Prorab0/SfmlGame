#include "Game.h"
#include "Resources.h"
#include "Map.h"
#include "Physics.h"
#include "Player.h"



using namespace std;

Map mapp (16.0f);
Camera camera(320.0f);

const float movementSpeed = 180.0f;
Player player;

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
	Physics::Init();
	
	sf::Image image;
	image.loadFromFile("map.png");
	player.position = mapp.CreateFromImage(image);
	player.Begin();
	

	
}

void Update(float deltaTime)
{
	player.Update(deltaTime);
	camera.position = player.position;
}
//renderuje tekstury na razie block z minecraftu
void Render(Renderer& renderer)
{
	mapp.Draw(renderer);
	player.Draw(renderer);
}

