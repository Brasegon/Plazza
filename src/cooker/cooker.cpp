/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** cooker
*/

#include "cooker.hpp"

Cooker::Cooker() : _isWorking(false)
{
}

// Cooker::~Cooker()
// {
//     if (this->_pizzaReady)
//         delete this->_receiveBuffer;
// }
void Cooker::setPizza(Pizza *pizza) {
    _pizza = pizza;
}
const std::string &Cooker::getPizza() const {
    return (_pizza->getName());
}
const int &Cooker::getTime() const {
    return (_pizza->time);
}
const std::vector<string> &Cooker::getIngredient() const {
    return _pizza->getIngredient();
}
void Cooker::processCooking()
{
    while (12) {
        
    }
}