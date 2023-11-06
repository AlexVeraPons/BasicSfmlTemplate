#include "queueManager.hpp"

QueueManager::QueueManager() : _queuePosition(100) { }

QueueManager::QueueManager(float initialQueuePosition)
	: _queuePosition(initialQueuePosition) { }

QueueManager::~QueueManager() { }

float QueueManager::getQueuePosition() const
{
	return _queuePosition;
}

void QueueManager::setQueuePosition(float position)
{
	_queuePosition = position;
	Subject<float>::notifyObservers(_queuePosition);
}

void QueueManager::advanceQueuePosition(float amount)
{
	_queuePosition += amount;
	Subject<float>::notifyObservers(_queuePosition);
}

void QueueManager::resetQueuePosition()
{
	_queuePosition = 100;
	Subject<float>::notifyObservers(_queuePosition);
}
