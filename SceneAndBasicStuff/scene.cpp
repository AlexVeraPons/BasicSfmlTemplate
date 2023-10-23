#include "scene.hpp"
#include "gameObject.hpp"

Scene::Scene(std::string identifier) : identifier(identifier) { }

Scene::~Scene() { }

void Scene::addGameObject(GameObject& object) {
    this->listOfGameObjects.push_back(&object);
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
    if(this->listOfGameObjects.size() == 0) return;

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
