#include "showMoveResultButton.hpp"
#include "fightCharacter.hpp"
#include "queueManager.hpp"

ShowMoveResultButton::ShowMoveResultButton(
	std::string identifier,
	sf::Font& font,
	std::string buttonText,
	sf::Vector2f size,
	FightCharacter* owner,
	float cost
) : TextHighliteButton(identifier, font, buttonText, size),
_cost(cost),
_owner(owner) { }

ShowMoveResultButton::~ShowMoveResultButton() { }

void ShowMoveResultButton::onHover()
{
	TextHighliteButton::onHover();

	if (_owner->getQueuePosition() != _cost)
	{
		_owner->setQueuePosition(_cost);
	}
}

void ShowMoveResultButton::onHoverExit()
{
	TextHighliteButton::onHoverExit();

	_owner->setQueuePosition(0);
}
