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
#include "../encapsulation/Mutex.hpp"
#include "../log/logs.hpp"

typedef struct msg {
    long mtype;
    Pizza *pizza;
} msg_t;

class Params {
    public:
        Params(int id, int mult, Cooker *cooker, int stockTime, kitchen_t *sharedMemory, Logs *log, int cook_id);
        ~Params();
        int _id;
        int _mult;
        Cooker *cooker;
        int _stockTime;
        kitchen_t *_sharedMemory;
        Logs *_log;
        int _cook_id;

    protected:
    private:
};
class Kitchen {
    public:
        Kitchen(int id, int mult, int cookers, int stockTime, Logs *log);
        ~Kitchen();
        void run();
        void killedKitchenAndCooks(std::chrono::_V2::steady_clock::time_point &killKitchen);

    protected:
        int _id;
        int _mult;
        int _cookers;
        int _stockTime;
        std::vector<Cooker *> _cookerList;
        pthread_t *_threads;
        kitchen_t *_sharedMemory;
        msg_t _receiveBuffer;
        Mutex *mutex;
        int _msqid;
        Logs *_log;
    private:
};

void reginaCooking(Params *p);
void margaritaCooking(Params *p);
#endif /* !KITCHEN_HPP_ */
