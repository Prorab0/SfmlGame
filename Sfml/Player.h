#pragma once

#include <SFML/Graphics.hpp>
#include <Box2d/Box2d.h>
#include "Renderer.h"


class Player
{
public:
	void Begin();
	void Update(float deltaTime);
	void Draw(Renderer& renderer);

	sf::Vector2f position{};
	float angle{};
private:
	b2Body* body;
};

