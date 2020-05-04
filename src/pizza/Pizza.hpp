/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_
#include "../my.hpp"

class Pizza {

    public:
        Pizza(PizzaType pizzaType, PizzaSize pizzaSize);
        ~Pizza();

    protected:
        PizzaType pizzaType;
        PizzaSize pizzaSize;
        std::vector<std::string> ingredient;
        int time;
    private:
};

#endif /* !PIZZA_HPP_ */
