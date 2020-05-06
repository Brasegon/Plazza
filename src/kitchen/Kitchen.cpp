/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include "../encapsulation/Thread.hpp"
bool isActiveThread = true;

Kitchen::Kitchen(int id, int mult, int cookers, int stockTime) : _id(id), _mult(mult), _cookers(cookers), _stockTime(stockTime)
{
    mutex = new Mutex();
    std::cout << "Created kitchen : " << _id << std::endl;
    _sharedMemory = openSharedMemory();
    mutex->lock();
    _sharedMemory->cooker[_id] = _cookers;
    mutex->unlock();
    key_t key = ftok("/etc/bashrc", 'B');
    _msqid = msgget(key, 0666);

}
void cooking(Params *p) {
    while(isActiveThread) {
        if (p->cooker->_isWorking ){
            std::map<std::string, std::function<void (Params *p)>> tab = {
                {"Regina", &reginaCooking},
                {"Margarita", &margaritaCooking},
            };
            tab[p->cooker->getPizza()](p);
        } else {
            std::this_thread::yield();
        }
    }
}
void Kitchen::run() {
    std::vector<Thread *> t;
    auto killKitchen = std::chrono::steady_clock::now();
    for (int i = 0; i < _cookers; i += 1) {
        Cooker *cooker = new Cooker();
        _cookerList.push_back(cooker);
        Params *p = new Params(_id, _mult, cooker, _stockTime, _sharedMemory);
        Thread *thread = new Thread(std::thread(cooking, p));
        t.push_back(thread);
        t[i]->detach();
    }
    while (true) {
        if (std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - killKitchen).count() > 5) {
            if (_sharedMemory->cooker[_id] == _cookers) {

                isActiveThread = false;
                raise(SIGTERM);
            }
        }
        if (msgrcv(_msqid, &_receiveBuffer, sizeof(Pizza *), _id + 1, MSG_NOERROR | IPC_NOWAIT) > 0) {
            for (uint64_t i = 0; i < _cookerList.size(); i += 1) {
                if (!_cookerList[i]->_isWorking) {
                    mutex->lock();
                    if (_sharedMemory->cooker[_id] > 0) {
                        _sharedMemory->cooker[_id] -= 1;
                        _cookerList[i]->_isWorking = true;
                        _cookerList[i]->setPizza(_receiveBuffer.pizza);
                    }
                    mutex->unlock();
                    break;
                }
            }
        }

    }
}

Kitchen::~Kitchen()
{
}
Params::Params(int id, int mult, Cooker *cooker, int stockTime, kitchen_t *sharedMemory) : _id(id), _mult(mult), cooker(cooker), _stockTime(stockTime), _sharedMemory(sharedMemory) {

}

Params::~Params() {

}
