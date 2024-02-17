#include "Game.h"
#include "Resources.h"



using namespace std;

void Begin(const sf::Window& window)
{
	//przeszkuje wszystkie pliki z tego folderu /resources/textures/
	for (auto& file : filesystem::directory_iterator("C:/Users/PC/source/repos/Sfml/Release/resources/textures/"))
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
}

void Update(float deltaTime)
{

}
//renderuje tekstury na razie block z minecraftu
void Render(Renderer& renderer)
{
	renderer.Draw(Resources::textures["block.png"],
		sf::Vector2f(), sf::Vector2f(4.75f, 4.75f));
}

