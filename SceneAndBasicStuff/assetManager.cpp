#include "assetManager.hpp"
#include <iostream>

AssetManager* AssetManager::_instance = nullptr;

AssetManager::~AssetManager() { }

void AssetManager::loadTexture(std::string identifier, std::string filePath)
{
	sf::Texture texture;
	texture.loadFromFile(filePath);
	this->_textures.emplace(identifier, texture);
}

void AssetManager::loadFont(std::string identifier, std::string filePath)
{
	sf::Font font;
	font.loadFromFile(filePath);
	this->_fonts.emplace(identifier, font);
}

void AssetManager::loadScoreFile(std::string filePath)
{
	this->_scoreFilePath = filePath;
}

const sf::Texture& AssetManager::getTexture(std::string identifier)
{
	return this->_textures[identifier];
}

const sf::Font&  AssetManager::getFont(std::string identifier)
{
	return this->_fonts[identifier];
}

const std::string AssetManager::getScoreFilePath()
{
	return _scoreFilePath;
}

