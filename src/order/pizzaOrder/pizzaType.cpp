/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** pizzaType
*/

#include "../../pizza/pizzaType/MargaritaPizza.hpp"
#include "../../pizza/pizzaType/ReginaPizza.hpp"
#include "../../pizza/pizzaType/AmericanaPizza.hpp"
#include "../../pizza/pizzaType/FantasiaPizza.hpp"

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

Pizza *americanaPizza(PizzaSize size)
{
    Pizza *pizza = new AmericanaPizza(size);
    return pizza;
}

Pizza *fantasiaPizza(PizzaSize size)
{
    Pizza *pizza = new FantasiaPizza(size);
    return pizza;
}