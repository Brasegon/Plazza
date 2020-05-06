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
    Pizza *pizza;
public:
    Cooker();
    void processCooking();
    ~Cooker();
    bool _isWorking;
};

#endif /* !COOKER_HPP_ */
