#include "turnIndicatorUI.hpp"
#include "turnIndicatorEntityUI.hpp"

TurnIndicatorUI::TurnIndicatorUI() : GameObject("TurnIndicatorUI", sf::Vector2f(0, 0))
{
	_rectBackground.setSize(sf::Vector2f(400, 10));
	_rectBackground.setFillColor(sf::Color::Black);
	_rectBackground.setOutlineColor(sf::Color::White);
	_rectBackground.setOutlineThickness(2);
	_rectBackground.setPosition(position);
	_rectBackground.setOutlineColor(sf::Color::Transparent);

	_entity1Indicator = std::make_unique<TurnIndicatorEntityUI>(
		sf::Vector2f(position.x + _rectBackground.getSize().x, position.y + (_rectBackground.getSize().y / 2)),
		sf::Color::Blue,
		this
	);

	_entity2Indicator = std::make_unique<TurnIndicatorEntityUI>(
		sf::Vector2f(position.x, position.y + (_rectBackground.getSize().y / 2)),
		sf::Color::Red,
		this
	);
}

TurnIndicatorUI::TurnIndicatorUI(std::string identifier, sf::Vector2f position, sf::Vector2f size, FightCharacter* fighter1, FightCharacter* fighter2) : GameObject(identifier, position)
{
	_rectBackground.setSize(size);
	_rectBackground.setFillColor(sf::Color::Black);
	_rectBackground.setOutlineColor(sf::Color::White);
	_rectBackground.setOutlineThickness(2);
	_rectBackground.setPosition(position);
	_rectBackground.setOutlineColor(sf::Color::Transparent);

	_entity1Indicator = std::make_unique<TurnIndicatorEntityUI>(
		sf::Vector2f(position.x + _rectBackground.getSize().x, position.y + (_rectBackground.getSize().y / 2)),
		sf::Color::Blue,
		this
	);
	fighter1->addObserverToQueueManager(*_entity1Indicator);

	_entity2Indicator = std::make_unique<TurnIndicatorEntityUI>(
		sf::Vector2f(position.x, position.y + (_rectBackground.getSize().y / 2)),
		sf::Color::Red,
		this
	);
	fighter2->addObserverToQueueManager(*_entity2Indicator);
}

TurnIndicatorUI::~TurnIndicatorUI() { }

sf::Vector2f TurnIndicatorUI::getSize() const
{
	return _rectBackground.getSize();
}

void TurnIndicatorUI::setPosition(sf::Vector2f position)
{
	_rectBackground.setPosition(position);
	_entity1Indicator->setPosition(sf::Vector2f(position.x + _rectBackground.getSize().x, position.y + (_rectBackground.getSize().y / 2)));
	_entity2Indicator->setPosition(sf::Vector2f(position.x, position.y + (_rectBackground.getSize().y / 2)));
}

void TurnIndicatorUI::render(sf::RenderWindow& window)
{
	window.draw(_rectBackground);
	_entity1Indicator->render(window);
	_entity2Indicator->render(window);
}

void TurnIndicatorUI::setEntityReferences(FightCharacter* fighter1, FightCharacter* fighter2)
{
	fighter1->addObserverToQueueManager(*_entity1Indicator);
	fighter2->addObserverToQueueManager(*_entity2Indicator);
}

void TurnIndicatorUI::update()
{
	if (_entity1Indicator->getPosition() == _entity2Indicator->getPosition())
	{
		_entity1Indicator->setPosition(sf::Vector2f(_entity1Indicator->getPosition().x, _entity1Indicator->getPosition().y+30));
	}
}
