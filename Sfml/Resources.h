#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <filesystem>
#include <unordered_map>

class Resources
{
public:
	static std::unordered_map<std::string , sf::Texture> textures;
};

