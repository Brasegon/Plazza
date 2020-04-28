/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** main
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "reception/Reception.hpp"
#include "my.hpp"

int main(int ac, char **av) {
    int mult, cooker, stockTime;

    if (ac != 4) {
        cout << "It's incorrect" << endl;
        exit(84);
    }
    try {
        mult = stoi(av[1]);
        cooker = stoi(av[2]);
        stockTime = stoi(av[3]);
    } catch(const std::exception& e) {
        cerr << e.what() << endl;
        exit(84);
    }
    Reception reception(mult, cooker, stockTime);
    reception.launch();
}