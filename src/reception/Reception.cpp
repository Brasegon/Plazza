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

int Reception::requestOrder(std::string &command) {
    Order orders(command);
    orders.parseOrder();
    orders.dump();
    return (0);
}

void Reception::launch() {
    string line;

    while (1) {
        cout << "> ";
        getline(cin, line);
        if (line.compare("quit") == 0) {
            exit(0);
        }
        if (Reception::requestOrder(line) == -1) {
            cout << "Invalid Request Order" << endl;
        }
    }
}


