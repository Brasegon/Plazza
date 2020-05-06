/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** cooker
*/

#ifndef COOKER_HPP_
#define COOKER_HPP_
#include "../my.hpp"
#include "../pizza/Pizza.hpp"

class Cooker
{

private:
    Pizza *_pizza;
public:
    Cooker();
    void processCooking();
    ~Cooker();
    bool _isWorking;
    void setPizza(Pizza *pizza);
    const std::string &getPizza() const;
};

#endif /* !COOKER_HPP_ */
