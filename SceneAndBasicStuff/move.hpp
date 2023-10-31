#pragma once
#include <string>

enum class Target
{
	Self,
	Enemy,
	All,
};

class Move
{
public:

	Move();
	~Move();

	virtual void operator()() = 0;

	virtual void execute() = 0;
	
	virtual const std::string getName() = 0;
	virtual const float getEffectValue() = 0;
	virtual const float getCost() = 0;
	virtual const Target getTarget() = 0;
};
