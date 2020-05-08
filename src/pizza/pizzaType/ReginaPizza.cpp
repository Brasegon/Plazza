/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Regina
*/

#include "ReginaPizza.hpp"

ReginaPizza::ReginaPizza(PizzaSize pizzaSize) : Pizza((PizzaType) 1, pizzaSize)
{
    ingredient.push_back("does");
    ingredient.push_back("tomatoes");
    ingredient.push_back("gruyere");
    ingredient.push_back("ham");
    ingredient.push_back("mushrooms");
    pizzaName = "Regina";
    time = 2;
}

ReginaPizza::~ReginaPizza()
{
}
