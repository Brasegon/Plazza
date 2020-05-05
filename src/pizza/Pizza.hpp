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
        Pizza(PizzaType type, PizzaSize size);
        Pizza(Pizza &cpy);
        ~Pizza();

        const std::vector<std::string> &getIngredient() const;
        const std::string &getName() const;
    protected:
        PizzaType pizzaType;
        PizzaSize pizzaSize;
        std::string pizzaName;
        std::vector<std::string> ingredient;
        int time;
    private:
};

#endif /* !PIZZA_HPP_ */
