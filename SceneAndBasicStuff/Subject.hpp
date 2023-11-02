#pragma once

template<typename T>
class Subject
{
public:
    void register_observer(observer<T>& o)
    {
        observers.push_back(o);
    }

    void notify_observers(const T& message)
    {
        for (observer<T>& o : observers) {
            o.notify(message);
        }
    }

private:
    std::vector<std::reference_wrapper<observer<T>>> observers;
};

template<typename T>
class observer
{
public:
    virtual void notify(const T& message) = 0;
};

class observer_concrete : public observer<int>
{
public:
    void notify(const int&) override;
};

