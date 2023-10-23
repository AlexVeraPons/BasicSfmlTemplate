#pragma once

#include <map>
#include <stack>
#include "scene.hpp"

class SceneHandler {
private:
    std::map<std::string, Scene*> scenes;
    std::stack<Scene*> scenesStack;
public:
    SceneHandler();
    ~SceneHandler();
public:
    void render(sf::RenderWindow& window) const; // const because it doesn't change the object
    void update();
    void handleEvent(const sf::Event& evenet, sf::RenderWindow& window);

    void addScene(Scene& scene);
    void stackScene(std::string sceneName); // Stack is to add an element to the top of the stack
    void popScene(); // Pop is to remove the top element of the stack
};
