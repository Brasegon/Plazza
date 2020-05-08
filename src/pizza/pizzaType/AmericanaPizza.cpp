/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** AmericanaPizza
*/

#include "AmericanaPizza.hpp"

AmericanaPizza::AmericanaPizza(PizzaSize pizzaSize) : Pizza((PizzaType) 4, pizzaSize)
{
    ingredient.push_back("does");
    ingredient.push_back("tomatoes");
    ingredient.push_back("gruyere");
    ingredient.push_back("steak");
    pizzaName = "Americana";
    time = 2;
}

AmericanaPizza::~AmericanaPizza()
{
}

