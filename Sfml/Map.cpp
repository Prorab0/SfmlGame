#include "Map.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Renderer.h"

Map::Map(float cellSize)
	:cellSize(cellSize), grid()
{

}

sf::Vector2f Map::CreateFromImage(const sf::Image& image)
{
	grid.clear();
	grid = std::vector(image.getSize().x, std::vector(image.getSize().y,0));

	sf::Vector2f playerPosition{};

	for(size_t x = 0; x < grid.size(); x++)	
	{
		for (size_t y = 0; y < grid[x].size(); y++)
		{
			sf::Color color = image.getPixel(x, y);
			if (color == sf::Color::Black)
				grid[x][y] = 1;
			else if (color == sf::Color::Red)
				playerPosition = sf::Vector2f(cellSize * x + cellSize / 2.0f,
					cellSize * y + cellSize / 2.0f);
			
		}
	}

	return playerPosition;
}

void Map::CreateCheckerboard(size_t width, size_t height)
{
	grid = std::vector(width, std::vector(height, 0));

	bool last = 0;
	for (auto& column : grid)
	{ 
		for (auto& cell : column)
		{
			last = cell = !last;
			
		}
		if (width % 2 == 0) 
		{
			last = !last;
		}
	}
}



void Map::Draw(Renderer& renderer)
{
	int x = 0;
	for (const auto& column : grid)
	{
		int y = 0;
		for (const auto& cell : column)
		{
			if (cell) 
			{
				renderer.Draw(Resources::textures["block.png"],
					sf::Vector2f(cellSize * x + cellSize / 2.0f,
						cellSize * y + cellSize / 2.0f),
					sf::Vector2f(cellSize, cellSize));
			}
			y++;
		}
		x++;
	}
}
