#pragma once

#include "Renderer.h"
#include "Camera.h"


extern Camera camera;

void Begin(const sf::Window& window);
void Update(float deltaTime);
void Render(Renderer& renderer);