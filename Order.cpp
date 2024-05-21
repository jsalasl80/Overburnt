#include "Order.h"

int Order::getRecipeId() {
    return recipeId;
}

int Order::getWaitTime() {
    return waitTime;
}

void Order::calculateWaitTime() {
    // Aquí se calcularía el tiempo de espera basado en algunos criterios
    waitTime = 10; // Ejemplo de tiempo de espera fijo
}

bool Order::isReady() const {
    return waitTime <= 0;
}

void Order::markAsCompleted() {
    waitTime = 0;
}
