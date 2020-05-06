/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** cooker
*/

#ifndef COOKER_HPP_
#define COOKER_HPP_
#include "../my.hpp"
#include "../pizza/Pizza.hpp"

class Cooker
{

private:
    bool _actif;
public:
    Cooker();
    void processCooking();
    ~Cooker();
};

#endif /* !COOKER_HPP_ */
