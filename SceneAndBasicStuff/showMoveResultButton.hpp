#pragma once
#include "textHighliteButton.hpp"
#include "fightCharacter.hpp"
#include "move.hpp"


class ShowMoveResultButton : public TextHighliteButton
{
private:
	float _cost;
	FightCharacter* _owner;



public:
	ShowMoveResultButton(std::string identifier,
		sf::Font& font,
		std::string buttonText,
		sf::Vector2f size,
		FightCharacter* owner,
		float cost
	);

	~ShowMoveResultButton();

protected:
	void onHover() override;
	void onHoverExit() override;
};

