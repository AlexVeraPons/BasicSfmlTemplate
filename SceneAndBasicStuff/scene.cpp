#include "scene.hpp"
#include "gameObject.hpp"

Scene::Scene(std::string const identifier) : identifier(identifier), listOfGameObjects() { }
Scene::~Scene() { }

void Scene::addGameObject(std::unique_ptr<GameObject> object) {
	this->listOfGameObjects.push_back(std::move(object));
}

GameObject* Scene::getGameObject(std::string const identifier) {
	for (std::unique_ptr<GameObject>& gameObject : this->listOfGameObjects) {
		if (gameObject) {  // Check if gameObject is not null
			printf("identifier: %s\n", gameObject->getIdentifier().c_str());
			if (gameObject->getIdentifier() == identifier) {
				return gameObject.get();
			}
		}
		else {
			printf("Null gameObject found in listOfGameObjects\n");
		}
	}
	return nullptr;  // Ensure to return a value in all cases
}

void Scene::start()
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i]->start();
	}
}

void Scene::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i]->handleEvent(event, window);
	}
}

void Scene::update() {
	if (this->listOfGameObjects.size() == 0) return;

	for (auto& gameObject : listOfGameObjects) {
		gameObject->update();
	}
}


void Scene::render(sf::RenderWindow& window) {
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++) {
		this->listOfGameObjects[i]->render(window);
	}
}

std::string Scene::getIdentifier() const {
	return this->identifier;
}

void Scene::onDisable()
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i]->onDisable();
	}
}
