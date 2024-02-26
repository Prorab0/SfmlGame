#include "Player.h"
#include "Physics.h"
#include "Renderer.h"
#include "Resources.h"

#include <Box2d/Box2d.h>






constexpr float M_PI = 22.0f / 7.0f;

const float movementSpeed = 180.0f;

void Player::Begin()
{
	b2BodyDef bodyDef{};
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(position.x, position.y);
	body = Physics::world.CreateBody(&bodyDef);
	b2PolygonShape shape{};
	shape.SetAsBox(0.5f, 1.0f);
	b2FixtureDef fixtureDef{};
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
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
	position = sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
	angle = body->GetAngle() * (180.0f / M_PI);
}

void Player::Draw(Renderer& renderer)
{
	renderer.Draw(Resources::textures["player.png"], position,
		sf::Vector2f(16.0f, 32.0f), angle);
}
