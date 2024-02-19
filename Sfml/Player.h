#pragma once

#include <SFML/Graphics.hpp>
#include "Renderer.h"

class Player
{
public:
	void Update(float deltaTime);
	void Draw(Renderer& renderer);

	sf::Vector2f position{};
	float angle{};
};

