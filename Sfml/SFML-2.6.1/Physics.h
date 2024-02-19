#pragma once

#include <Box2D/Box2D.h>
class Physics
{
public:
	static void Init();
	static void Update(float deltaTime);

private:
	static b2World world;
};

