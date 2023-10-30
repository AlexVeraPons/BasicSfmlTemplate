#include "sceneHandler.hpp"

SceneHandler::SceneHandler() { } // Basic constructor

SceneHandler::~SceneHandler() { } // Basic destructor

void SceneHandler::render(sf::RenderWindow& window) const {
	if (this->scenesStack.size() != 0) {
		this->scenesStack.top()->render(window);
	}
}

void SceneHandler::update() {
	if (this->scenesStack.size() != 0) {
		this->scenesStack.top()->update();
	}
}

void SceneHandler::handleEvent(const sf::Event& evenet, sf::RenderWindow& window)
{
	if (this->scenesStack.size() != 0) {
		this->scenesStack.top()->handleEvent(evenet, window);
	}
}

void SceneHandler::onDisable()
{
	if (this->scenesStack.size() != 0) {
		this->scenesStack.top()->onDisable();
	}
}

void SceneHandler::addScene(Scene& scene) {
	this->scenes.emplace(scene.getIdentifier(), &scene);
	if (this->scenes.size() == 1) {
		this->stackScene(scene.getIdentifier());
	}
}

void SceneHandler::stackScene(std::string sceneName) {
	onDisable();
	this->scenesStack.push(scenes[sceneName]);
	scenesStack.top()->start();
}

void SceneHandler::popScene(void) {
	this->scenesStack.pop();
}

