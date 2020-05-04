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
    std::vector<string> order;
    for (uint64_t i = 0; i < _orders.size(); i += 1) {
        std::stringstream input(_orders[i]);
        while (std::getline(input, line, ' ')) {
            order.push_back(line);
        }
        if (this->createPizza(order) == -1) {
            cout << "Error Order" << endl;
            order.clear();
            return;
        }
        order.clear();
    }
}

int Order::getOrderPizzaName(std::string name, std::string size) {
    std::map<std::string, std::function<Pizza *(PizzaSize size_p)>> tab = {
        {"margarita", &margaritaPizza}
    };
    std::map<std::string, PizzaSize> sizePizza = {
        {"S", S},
        {"M", M},
        {"L", L},
        {"XL", XL},
        {"XXL", XXL}
    };
    if (tab[name] && sizePizza[size]) {
        Pizza *pizza(tab[name](sizePizza[size]));
        pizzaList.push_back(pizza);
        return (0);
    }
    return (-1);
}

int Order::createPizza(std::vector<string> order) {
    if (order.size() != 3) {
        return (-1);
    }
    if (order[1] != "S" && order[1] != "M" && order[1] != "L" && order[1] != "XL" && order[1] != "XXL") {
        return (-1);
    }
    if (getOrderPizzaName(order[0], order[1]) == -1) {
        return (-1);
    }
    return (0);
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

const std::vector<Pizza *> &Order::getPizzaList() const
{
    return pizzaList;
}