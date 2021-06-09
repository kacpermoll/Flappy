#pragma once

#include<map>
#include <SFML/Graphics.hpp>

namespace ChroMoZub
{
	class AssetManager
	{
	public:
		AssetManager(){}
		~AssetManager(){}

		//�adowanie tekstur
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		//�adowanie font�w
		void LoadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);

	private:
		//zmienne w postaci kontenera "std::map"
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	};
}