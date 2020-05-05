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
proctected:
    int _multiplier;
    int _id;
    Kitchen *_kitchen;
    bool _commandToCook
private:
public:
    Cooker(Kitchen *kitchen, int multiplier, int id);
    void processCooking();
    ~Cooker();
};

#endif /* !COOKER_HPP_ */
