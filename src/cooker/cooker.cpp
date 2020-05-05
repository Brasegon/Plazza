/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** cooker
*/

#include "cooker.hpp"

Cooker::Cooker(Kitchen *kitchen, int multiplier, int id)
{
    this->_multiplier = multiplier;
    this->_id = id;
    this->_kitchen = kitchen;
    std::cout << "Created cooker: " << id << std::endl;
}

Cooker::~Cooker()
{
}

void Cooker::processCooking()
{
    while (12) {
        
    }
}