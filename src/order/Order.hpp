/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Order
*/

#ifndef ORDER_HPP_
#define ORDER_HPP_
#include "../my.hpp"
class Order {
    public:
        Order(std::string &command);
        virtual ~Order();
    protected:
        std::string _command;
    private:
};

#endif /* !ORDER_HPP_ */
