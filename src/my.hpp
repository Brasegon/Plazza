/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** my
*/

#ifndef MY_HPP_
#define MY_HPP_

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

enum PizzaType
{
    Error = -1,
    Regina = 1 ,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};
enum PizzaSize
{
    S = 1 ,
    M = 2 ,
    L = 4 ,
    XL = 8 ,
    XXL = 16
};

PizzaType margarita();

#endif /* !MY_HPP_ */
