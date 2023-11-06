#pragma once
#include "Subject.hpp"

class QueueManager : public Subject<float>
{
private:
	float _queuePosition;
public:
	QueueManager();
	QueueManager(float initialQueuePosition);
	~QueueManager();

	float getQueuePosition() const;
	void setQueuePosition(float position);
	void advanceQueuePosition(float amount);
	void resetQueuePosition();
};

