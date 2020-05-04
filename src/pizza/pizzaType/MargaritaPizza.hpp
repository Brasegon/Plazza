/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Margarita
*/

#ifndef MARGARITA_HPP_
#define MARGARITA_HPP_
#include "../Pizza.hpp"
class MargaritaPizza : public Pizza {
    public:
        explicit MargaritaPizza(PizzaSize pizzaSize);
        virtual ~MargaritaPizza();

    protected:
    private:
};

#endif /* !MARGARITA_HPP_ */
