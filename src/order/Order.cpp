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

}

void Order::setOrders(std::vector<std::string> &orders) {
    _orders = orders;
}

const std::vector<std::string> &Order::getOrders() const {
    return _orders;
}