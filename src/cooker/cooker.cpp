/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** cooker
*/

#include "cooker.hpp"

Cooker::Cooker() : _isWorking(false)
{
    std::cout << "Created cooker" << std::endl;
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
void Cooker::processCooking()
{
    while (12) {
        
    }
}