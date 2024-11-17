#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <memory>
#include <algorithm>

// Interfaz para los observadores
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0; // Método llamado cuando hay cambios
};

// Clase base para implementar el patrón Observer
class Subject {
public:
    virtual ~Subject() = default;

    // Agrega un observador
    void addObserver(const std::shared_ptr<Observer>& observer) {
        observers.push_back(observer);
    }

    // Elimina un observador
    void removeObserver(const std::shared_ptr<Observer>& observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    // Notifica a todos los observadores
    void notifyObservers() const {
        for (const auto& observer : observers) {
            if (observer) {
                observer->update();
            }
        }
    }

protected:
    std::vector<std::shared_ptr<Observer>> observers; // Lista de observadores
};

#endif // OBSERVER_H
