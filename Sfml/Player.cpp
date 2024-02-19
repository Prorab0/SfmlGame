#include "Player.h"
#include "Renderer.h"
#include "Resources.h"

const float movementSpeed = 180.0f;

void Player::Begin()
{

}

void Player::Update(float deltaTime)
{
	/*float move = movementSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		position.x += movementSpeed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		position.x -= movementSpeed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		position.y -= movementSpeed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		position.y += movementSpeed * deltaTime;
		*/
}

void Player::Draw(Renderer& renderer)
{
	renderer.Draw(Resources::textures["player.png"], position,
		sf::Vector2f(16.0f, 32.0f));
}
