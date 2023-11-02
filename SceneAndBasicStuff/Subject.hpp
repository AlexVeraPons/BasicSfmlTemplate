#pragma once
#include <vector>
#include "observer.hpp"
#include <functional>  // For std::reference_wrapper

template<typename T>
class Subject
{
public:
    void addObserver(Observer<T>& observer)
    {
        observers.push_back(observer);
    }

    void notifyObservers(const T& value)
    {
        for (Observer<T>& observer : observers) {
            observer.onNotified(value);
        }
    }

private:
    std::vector<std::reference_wrapper<Observer<T>>> observers;
};

