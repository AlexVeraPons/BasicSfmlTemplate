#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class AssetManager
{
private:
	static AssetManager* _instance;

	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;
	std::string _scoreFilePath;

	AssetManager() {}
public:
	~AssetManager();

	static AssetManager* getInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new AssetManager();
		}
		return _instance;
	}

	void loadTexture(std::string identifier, std::string filePath);
	void loadFont(std::string identifier, std::string filePath);
	void loadScoreFile(std::string filePath);

	const sf::Texture& getTexture(std::string identifier);
	const sf::Font& getFont(std::string identifier);
	const std::string getScoreFilePath();
};

