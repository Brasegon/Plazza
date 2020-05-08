/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** AmericanaPizza
*/

#include "FantasiaPizza.hpp"

FantasiaPizza::FantasiaPizza(PizzaSize pizzaSize) : Pizza((PizzaType) 8, pizzaSize)
{
    ingredient.push_back("does");
    ingredient.push_back("tomatoes");
    ingredient.push_back("eggplant");
    ingredient.push_back("goat cheese");
    ingredient.push_back("chief love");
    pizzaName = "Fantasia";
    time = 4;
}

FantasiaPizza::~FantasiaPizza()
{
}

