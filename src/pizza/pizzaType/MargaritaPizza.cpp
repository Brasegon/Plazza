/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Margarita
*/

#include "MargaritaPizza.hpp"

MargaritaPizza::MargaritaPizza(PizzaSize pizzaSize) : Pizza((PizzaType) 2, pizzaSize)
{
    ingredient.push_back("does");
    ingredient.push_back("tomatoes");
    ingredient.push_back("gruyere");
    pizzaName = "Margarita";
    time = 1;

}

MargaritaPizza::~MargaritaPizza()
{
}
