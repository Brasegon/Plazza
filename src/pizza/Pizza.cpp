/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Pizza
*/

#include "Pizza.hpp"

Pizza::Pizza(PizzaType pizzaType, PizzaSize pizzaSize) : pizzaType(pizzaType), pizzaSize(pizzaSize)
{
}

Pizza::Pizza(Pizza &cpy)
{
    pizzaType = cpy.pizzaType;
    pizzaSize = cpy.pizzaSize;
    ingredient = cpy.ingredient;
    time = cpy.time;
}
const std::vector<std::string> &Pizza::getIngredient() const {
    return ingredient;
}
Pizza::~Pizza()
{
}
