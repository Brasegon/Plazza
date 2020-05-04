/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Margarita
*/

#include "MargaritaPizza.hpp"

MargaritaPizza::MargaritaPizza(PizzaSize pizzaSize) : Pizza((PizzaType) 2, pizzaSize)
{
    ingredient.push_back("doe");
    ingredient.push_back("tomato");
    ingredient.push_back("gruyere");
    time = 1;

}

MargaritaPizza::~MargaritaPizza()
{
}