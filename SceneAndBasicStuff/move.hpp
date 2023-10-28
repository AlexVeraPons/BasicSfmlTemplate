#pragma once
class Move
{
public:
	Move();
	~Move();
	virtual void operator()() = 0;

public:
	virtual const float getMoveCost() = 0;
};
