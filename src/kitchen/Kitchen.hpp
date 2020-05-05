/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_
#include "../my.hpp"

class Kitchen {
    public:
        Kitchen(int id, int mult, int cookers, int stockTime);
        ~Kitchen();

    protected:
        int _id;
        int _mult;
        int _cookers;
        int _stockTime;
        kitchen_t *_sharedMemory;
        int _msqid;
    private:
};

#endif /* !KITCHEN_HPP_ */
