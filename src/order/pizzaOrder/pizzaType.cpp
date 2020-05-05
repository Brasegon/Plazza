/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** pizzaType
*/

#include "../../pizza/pizzaType/MargaritaPizza.hpp"
#include "../../pizza/pizzaType/ReginaPizza.hpp"

Pizza *margaritaPizza(PizzaSize size)
{
    Pizza *pizza = new MargaritaPizza(size);
    return pizza;
}

Pizza *reginaPizza(PizzaSize size)
{
    Pizza *pizza = new ReginaPizza(size);
    return pizza;
}