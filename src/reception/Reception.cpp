/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Reception
*/

#include "Reception.hpp"


Reception::Reception(int mult, int cookers, int stockTime) : mult(mult), cookers(cookers), stockTime(stockTime)
{
}

Reception::~Reception()
{
}

void Reception::launch() {
    string line;

    while (1) {
        cin >> line;
        if (line.compare("quit") == 0) {
            exit(0);
        }
    }
}


