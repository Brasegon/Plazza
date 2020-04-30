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
    std::stringstream input(_command);
    std::string line;
    while (std::getline(input, line, ';')) {
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