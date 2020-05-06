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

Cooker::~Cooker()
{
    if (this->_pizzaReady)
        delete this->_receiveBuffer;
}

void Cooker::processCooking()
{
    while (12) {
        
    }
}