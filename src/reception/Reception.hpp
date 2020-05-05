/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_
#include "../my.hpp"
#include "../order/Order.hpp"
class Reception {
    public:
        Reception(int mult, int cookers, int stockTime);
        ~Reception();
        int requestOrder(std::string &command);
        void launch();
        void status();
        void sendOrders();

    protected:
        int mult;
        int cookers;
        int stockTime;
        std::vector<Pizza *> orderPizza;
    private:
};

#endif /* !RECEPTION_HPP_ */
