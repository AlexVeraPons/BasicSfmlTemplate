#pragma once

template<typename T>
class Observer
{
public:
    virtual void onNotified(const T& value) = 0;
};
