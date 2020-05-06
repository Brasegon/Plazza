/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Mutex
*/

#include "Mutex.hpp"

Mutex::Mutex()
{
}

Mutex::~Mutex()
{
}

void Mutex::lock()
{
    mutex.lock();
}
void Mutex::unlock()
{
    mutex.unlock();
}
void Mutex::trylock()
{
    mutex.try_lock();
}