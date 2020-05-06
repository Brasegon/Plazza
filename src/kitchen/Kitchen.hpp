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

typedef struct msg {
    long mtype;
    Pizza *pizza;
} msg_t;

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
        msg_t _receiveBuffer;
        int _msqid;
    private:
};

class Params {
    public:
        Params(int id, int mult, Cooker *cooker, int stockTime, kitchen_t *sharedMemory);
        ~Params();

    protected:
        int _id;
        int _mult;
        Cooker *cooker;
        int _stockTime;
        kitchen_t *_sharedMemory;
    private:
};
#endif /* !KITCHEN_HPP_ */
