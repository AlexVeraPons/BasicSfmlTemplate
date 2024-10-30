#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "main.h"
#include "turnBasedGame.hpp"

const int _windowWidth = 1280;
const int _windowHeight = 720;
const sf::Color _backgroundColor = sf::Color(1, 106, 159);
const std::string _latoRegularFontPath = "Assets/Fonts/Lato-Regular.ttf";
const std::string _scoreFilePath = "Savedata/score.cmgt";

void LoadAssets();
void SetupWindow(sf::RenderWindow& window);
void SetupScenes(SceneHandler& handler, sf::Font& font, sf::RenderWindow& window);
void SetupGameScreen(Scene* gameScreen, sf::Font& font, Scene* mainScreen, SceneHandler& handler, sf::RenderWindow& window);
void SetupMainScreen(sf::Font& font, Scene* mainScreen, SceneHandler& hanlder, sf::RenderWindow& window);
void GameLoop(sf::RenderWindow& window, SceneHandler& handler);

int main() {
	sf::RenderWindow window;
	SceneHandler handler;

	LoadAssets();

	sf::Font font = AssetManager::getInstance()->getFont("latoRegular");

	SetupWindow(window);
	SetupScenes(handler, font, window);
	GameLoop(window, handler);

	return 0;
}

void LoadAssets() {
	AssetManager* assetManager = AssetManager::getInstance();
	assetManager->loadFont("latoRegular", _latoRegularFontPath);
	assetManager->loadTexture("skeleton", "Assets/Sprites/skeleton.png");
	assetManager->loadTexture("arena", "Assets/Sprites/arena.png");
	assetManager->loadTexture("home", "Assets/Sprites/home.png");
	assetManager->loadTexture("skull", "Assets/Sprites/skull.png");
	//try yo open the path if not create a file
	std::ifstream file(_scoreFilePath);
	if (!file.is_open())
	{
		file.close();
		std::ofstream offile(_scoreFilePath);
		offile.close();
	}
	assetManager->loadScoreFile(_scoreFilePath);
}

void SetupWindow(sf::RenderWindow& window) {
	window.create(sf::VideoMode(_windowWidth, _windowHeight), "TurnBasedGame", sf::Style::Close);
}

void SetupScenes(SceneHandler& handler, sf::Font& font, sf::RenderWindow& window) {
	Scene* mainScreen = new Scene("mainScreen");
	Scene* gameScreen = new Scene("gameScreen");

	SetupMainScreen(font, mainScreen, handler, window);
	SetupGameScreen(gameScreen, font, mainScreen, handler, window);

	handler.addScene(*mainScreen);
	handler.addScene(*gameScreen);
}

void GameLoop(sf::RenderWindow& window, SceneHandler& handler) {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			handler.handleEvent(event, window);
		}
		window.clear(_backgroundColor);
		handler.update();
		handler.render(window);
		window.display();
	}
	handler.onDisable();
}

void SetupMainScreen(sf::Font& font, Scene* mainScreen, SceneHandler& handler, sf::RenderWindow& window)
{
	auto background = std::make_unique<Image>("background", AssetManager::getInstance()->getTexture("home"));
	background->sprite.setPosition(sf::Vector2f(0, 0));
	background->sprite.setScale(sf::Vector2f((float)window.getSize().x / background->sprite.getTexture()->getSize().x, (float)window.getSize().y / background->sprite.getTexture()->getSize().y));
	background->texture->setSmooth(true);
	mainScreen->addGameObject(std::move(background));


	sf::Vector2f mainScreenButtonsize(200, 100);

	// scoreboard
	auto scoreboard = std::make_unique<Scoreboard>("scoreboard", sf::Vector2f(_windowWidth - _windowWidth / 4, _windowHeight / 5), font);
	mainScreen->addGameObject(std::move(scoreboard));

	// play button
	auto play = std::make_unique<TextHighliteButton>("play", font, "Play", mainScreenButtonsize);
	play->setPosition(sf::Vector2f(100, 200));
	play->setHighliteFillColor(sf::Color::Transparent);
	play->setHighliteTextColor(sf::Color::Cyan);
	play->setTextSize(40);
	play->setOutlineColor(sf::Color::Transparent);
	play->setOnClickAction([&handler]() {
		handler.stackScene("gameScreen");
		});
	mainScreen->addGameObject(std::move(play));

	// erase data button
	auto eraseData = std::make_unique<TextHighliteButton>("eraseData", font, "Erase Data", mainScreenButtonsize);
	eraseData->setPosition(sf::Vector2f(100, 300));
	eraseData->setHighliteFillColor(sf::Color::Transparent);
	eraseData->setHighliteTextColor(sf::Color::Cyan);
	eraseData->setOutlineColor(sf::Color::Transparent);
	eraseData->setTextSize(40);
	eraseData->setOnClickAction([mainScreen]() {
		GameObject* gameObject = mainScreen->getGameObject("scoreboard");
		Scoreboard* scoreboard = dynamic_cast<Scoreboard*>(gameObject);
		if (scoreboard) {
			scoreboard->clearScores();
		}
		});
	mainScreen->addGameObject(std::move(eraseData));

	// quit button
	auto quit = std::make_unique<TextHighliteButton>("quit", font, "Quit", mainScreenButtonsize);
	quit->setPosition(sf::Vector2f(100, 400));
	quit->setHighliteFillColor(sf::Color::Transparent);
	quit->setTextSize(40);
	quit->setHighliteTextColor(sf::Color::Cyan);
	quit->setOutlineColor(sf::Color::Transparent);
	quit->setOnClickAction([&window]() {
		window.close();
		});
	mainScreen->addGameObject(std::move(quit));
}


void SetupGameScreen(Scene* gameScreen, sf::Font& font, Scene* mainScreen, SceneHandler& handler, sf::RenderWindow& window)
{
	auto arena = std::make_unique<Image>("arena", AssetManager::getInstance()->getTexture("arena"));
	arena->texture->setSmooth(true);
	arena->sprite.setScale(sf::Vector2f(((float)window.getSize().y / arena->sprite.getTexture()->getSize().y) / 1.25, ((float)window.getSize().y / arena->sprite.getTexture()->getSize().y) / 1.25));
	arena->sprite.setPosition(sf::Vector2f(window.getSize().x / 2 - arena->sprite.getGlobalBounds().width / 2, window.getSize().y / 2.75 - arena->sprite.getGlobalBounds().height / 2));
	gameScreen->addGameObject(std::move(arena));

	auto quitButton = std::make_unique<TextHighliteButton>("quitButton", font, "Quit", sf::Vector2f(100, 50));
	quitButton->setHighliteFillColor(sf::Color(150, 150, 150));
	quitButton->setHighliteTextColor(sf::Color::Cyan);
	quitButton->setOutlineColor(sf::Color(90, 90, 90));
	quitButton->setPosition(sf::Vector2f(20, 20));
	quitButton->setOnClickAction([&handler]() {
		handler.stackScene("mainScreen");
		});
	gameScreen->addGameObject(std::move(quitButton));

	CharacterData playerData;
	playerData.name = "Player";
	playerData.stats.attack = 7;
	playerData.stats.setHealth(6);
	playerData.stats.maxHealth = 60;
	playerData.stats.speed = 30;

	FightCharacter player(playerData);

	auto fightController = std::make_unique<FightController>("fightController", player);
	gameScreen->addGameObject(std::move(fightController));

	FightController* fightControllerintance = dynamic_cast<FightController*>(gameScreen->getGameObject("fightController"));

	FightCharacter* playerInstance = &fightControllerintance->getPlayer();
	FightCharacter* enemyInstance = &fightControllerintance->getEnemy();

	auto lightAttackButton = std::unique_ptr<ShowMoveResultButton>(new ShowMoveResultButton("lightAttack", font, "Light Attack", sf::Vector2f(_windowWidth / 4, _windowHeight / 4), playerInstance, AttackMove().getCost()));
	lightAttackButton->setHighliteFillColor(sf::Color(100, 100, 100, 100));

	lightAttackButton->setGrowFactor(1);
	lightAttackButton->setOnClickAction([gameScreen]() {
		FightController* fightController = dynamic_cast<FightController*>(gameScreen->getGameObject("fightController"));
		if (fightController) {
			LightAttack* lightAttack = new LightAttack(fightController->getPlayer(), fightController->getEnemy());
			fightController->executeMove(lightAttack);
			delete lightAttack;
		}
		});

	auto healButton = std::unique_ptr<ShowMoveResultButton>(new ShowMoveResultButton("BigHeal", font, "BigHeal", sf::Vector2f(_windowWidth / 4, _windowHeight / 4), playerInstance, BigHeal().getCost()));
	healButton->setHighliteFillColor(sf::Color(100, 100, 100, 100));
	healButton->setGrowFactor(1);
	healButton->setOnClickAction([gameScreen]() {
		FightController* fightController = dynamic_cast<FightController*>(gameScreen->getGameObject("fightController"));
		if (fightController) {
			BigHeal* bigHeal = new BigHeal(fightController->getPlayer());
			fightController->executeMove(bigHeal);
			delete bigHeal;
		}
		});

	auto heavyAttackButton = std::unique_ptr<ShowMoveResultButton>(new ShowMoveResultButton("HeavyAttack", font, "HeavyAttack", sf::Vector2f(_windowWidth / 4, _windowHeight / 4), playerInstance, HeavyAttack().getCost()));
	heavyAttackButton->setHighliteFillColor(sf::Color(100, 100, 100, 100));
	heavyAttackButton->setGrowFactor(1);
	heavyAttackButton->setOnClickAction([gameScreen]() {
		FightController* fightController = dynamic_cast<FightController*>(gameScreen->getGameObject("fightController"));
		if (fightController) {
			HeavyAttack* heavyAttack = new HeavyAttack(fightController->getPlayer(), fightController->getEnemy());
			fightController->executeMove(heavyAttack);
			delete heavyAttack;
		}
		});

	auto lifeStealAttackButton = std::unique_ptr<ShowMoveResultButton>(new ShowMoveResultButton("LifeSteal", font, "LifeSteal", sf::Vector2f(_windowWidth / 4, _windowHeight / 4), playerInstance, HeavyAttack().getCost()));
	lifeStealAttackButton->setHighliteFillColor(sf::Color(100, 100, 100, 100));
	lifeStealAttackButton->setGrowFactor(1);
	lifeStealAttackButton->setOnClickAction([gameScreen]() {
		FightController* fightController = dynamic_cast<FightController*>(gameScreen->getGameObject("fightController"));
		if (fightController) {
			LifeStealMove* lifeStealAttack = new LifeStealMove(fightController->getPlayer(), fightController->getEnemy());
			fightController->executeMove(lifeStealAttack);
			delete lifeStealAttack;
		}
		});

	auto actionSelectorUI = std::unique_ptr<ActionSelectorUI>(new ActionSelectorUI("actionSelectorUI", sf::Vector2f(_windowWidth / 2, _windowHeight - _windowHeight / 4), _windowWidth / 2, _windowHeight / 4, fightControllerintance->getPlayer()));
	actionSelectorUI->addButton(std::move(lightAttackButton));
	actionSelectorUI->addButton(std::move(healButton));
	actionSelectorUI->addButton(std::move(heavyAttackButton));
	actionSelectorUI->addButton(std::move(lifeStealAttackButton));

	gameScreen->addGameObject(std::move(actionSelectorUI));

	auto battleLog = std::unique_ptr<BattleLog>(new BattleLog("battleLog", sf::Vector2f(0, _windowHeight - _windowHeight / 4), _windowWidth / 2, _windowHeight / 4, font));
	fightControllerintance->addObserver(*battleLog);
	playerInstance->Subject<std::string>::addObserver(*battleLog);
	enemyInstance->Subject<std::string>::addObserver(*battleLog);

	gameScreen->addGameObject(std::move(battleLog));

	auto fightUI = std::unique_ptr<FightUI>(new FightUI("fightUI", playerInstance, enemyInstance, sf::Vector2f(_windowWidth, _windowHeight)));
	gameScreen->addGameObject(std::move(fightUI));
}