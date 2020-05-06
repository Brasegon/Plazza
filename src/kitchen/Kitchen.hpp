/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_
#include "../my.hpp"
#include "../cooker/cooker.hpp"

class Kitchen {
    public:
        Kitchen(int id, int mult, int cookers, int stockTime);
        ~Kitchen();
        void run();

    protected:
        int _id;
        int _mult;
        int _cookers;
        int _stockTime;
        pthread_t *_threads;
        kitchen_t *_sharedMemory;
        int _msqid;
    private:
};

#endif /* !KITCHEN_HPP_ */
