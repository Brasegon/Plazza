/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Order
*/

#include "Order.hpp"

Order::Order(std::string &command) : _command(command)
{
}

Order::~Order()
{
}

void Order::parseOrder() {
    std::string line;
    int j = 0;
    for (int i = 0; _command[i] != '\0'; i += 1) {
        if ((_command[i] == ' ' && _command[i + 1] == ' ')) {
            _command.erase(i + 1, 1);
            i = 0;
        }
    }
    std::stringstream input(_command);

    while (std::getline(input, line, ';')) {
        while (line[0] == ' ') {
            line.erase(0, 1);
        }
        _orders.push_back(line);
    }
}

void Order::printOrders() {
    for (u_int64_t i = 0; i < _orders.size(); i++)
        std::cout << _orders[i] << endl;
}

void Order::setOrders(std::vector<std::string> &orders) {
    _orders = orders;
}

const std::vector<std::string> &Order::getOrders() const {
    return _orders;
}
