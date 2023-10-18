#include "scene.hpp"

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

void Scene::update() {
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
