#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

struct Observer {
  public:
    explicit Observer(int value) : m_value(value) {}

    void notify(const std::string& from) { std::cout << "notify say number from " << from << ": " << m_value << std::endl; }

  private:
    int m_value;
};

struct Observable {
    explicit Observable(std::string&& name) {

    }

    void registerObserver(const std::shared_ptr<Observer> &observer) {
        m_observers.emplace_back(observer);
    }

    void notify() {
        for (auto &obs : m_observers) {
            auto ptr = obs.lock();
            if (ptr)
                ptr->notify(this->m_name);
        }
        std::cout << "=======================\n";
    }

  private:
    std::string m_name;
    std::vector<std::weak_ptr<Observer>> m_observers;
};

void observer_test() {

    Observable observable("first Observable");

    auto obs1 = std::make_shared<Observer>(1);
    observable.registerObserver(obs1);

    auto obs2 = std::make_shared<Observer>(2);
    observable.registerObserver(obs2);

    auto obs3 = std::make_shared<Observer>(3);
    observable.registerObserver(obs3);

    {
        auto obs4 = std::make_shared<Observer>(4);
        observable.registerObserver(obs4);
        observable.notify();
    }

    const std::shared_ptr<Observer>& obs5 = std::make_shared<Observer>(5);
    observable.registerObserver(obs5);

    observable.notify();
}

void weak_ptr_example() {
    std::weak_ptr<int> weak;
    {
        auto shared = std::make_shared<int>(42);

        weak = shared;

        auto x = weak.lock();
        assert(x);
    }
    auto x = weak.lock();
    assert(!x);
}

int main() {

    weak_ptr_example();
    observer_test();

    return 0;
}