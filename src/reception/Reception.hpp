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
#include "../encapsulation/Encapsulation.hpp"
#include "../kitchen/Kitchen.hpp"
#include "../log/logs.hpp"
#include "../encapsulation/Process.hpp"

class Reception {
    public:
        Reception(int mult, int cookers, int stockTime, Logs *log);
        ~Reception();
        int requestOrder(std::string &command);
        void launch();
        void status();
        void sendOrders();
        int createKitchen();
        int check_kitchen();
        void forkNewKitchen();

    protected:
        int mult;
        int cookers;
        int stockTime;
        msg_t _sendBuffer;
        std::vector<Pizza *> orderPizza;
        Encapsulation *_shm;
        kitchen_t *_sharedMemory;
        Logs *_log;
    private:
};
#endif /* !RECEPTION_HPP_ */
