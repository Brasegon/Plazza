/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Regina
*/

#include "Regina.hpp"

Regina::Regina(PizzaSize pizzaSize) : Pizza((PizzaType) 1, pizzaSize)
{
    ingredient.push_back("doe");
    ingredient.push_back("tomato");
    ingredient.push_back("gruyere");
    ingredient.push_back("ham");
    ingredient.push_back("mushrooms");
    time = 2;
}

Regina::~Regina()
{
}
