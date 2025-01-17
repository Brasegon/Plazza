/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include "../encapsulation/Thread.hpp"
bool isActiveThread = true;

Kitchen::Kitchen(int id, int mult, int cookers, int stockTime, Logs *log) : _id(id), _mult(mult), _cookers(cookers), _stockTime(stockTime), _log(log)
{
    mutex = new Mutex();
    _log->writeInfoMessage("Created kitchen : " + to_string(_id));
    _sharedMemory = openSharedMemory();
    mutex->lock();
    _sharedMemory->cooker[_id] = _cookers;
    mutex->unlock();
    key_t key = ftok("/etc/bashrc", 'B');
    _msqid = msgget(key, 0666);

}
void cooking(Params *p) {
    Mutex *mutex = new Mutex();
    while (isActiveThread) {
        if (p->cooker->_isWorking) {
            reginaCooking(p);
        }
    }
}

void Kitchen::killedKitchenAndCooks(std::chrono::_V2::steady_clock::time_point &killKitchen) {
    if (std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - killKitchen).count() > 5) {
        mutex->lock();
        if (_sharedMemory->cooker[_id] == _cookers) {
            _sharedMemory->cooker[_id] = -1;
            isActiveThread = false;
            for (uint64_t i = 0; i < _cookerList.size(); i += 1) {
                _log->writeInfoMessage("Kitchen n°" + to_string(_id) + ": Cooker n°" + to_string(i) + " killed");
            }
            _log->writeInfoMessage("Kitchen n°" + to_string(_id) + ": Killed");
            raise(SIGTERM);
        }
        mutex->unlock();
        killKitchen = std::chrono::steady_clock::now();
    }
}

void Kitchen::run() {
    std::vector<Thread *> t;
    std::chrono::_V2::steady_clock::time_point killKitchen = std::chrono::steady_clock::now();
    std::chrono::_V2::steady_clock::time_point stock = std::chrono::steady_clock::now();
    for (int i = 0; i < _cookers; i += 1) {
        Cooker *cooker = new Cooker();
        _log->writeInfoMessage("Kitchen n°" + to_string(_id) + ": Cooker n°" + to_string(i) + " created");
        _cookerList.push_back(cooker);
        mutex->lock();
        Params *p = new Params(_id, _mult, cooker, _stockTime, _sharedMemory, _log, i);
        Thread *thread = new Thread(std::thread(cooking, p));
        thread->detach();
        t.push_back(thread);
        mutex->unlock();
    }
    while (true) {
        std::vector<string> tab = {
            "does", "tomatoes", "gruyere", "ham", "mushrooms", "steak", "eggplant", "goat cheese", "chief love"
        };
        killedKitchenAndCooks(killKitchen);
        if (std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - stock).count() > _stockTime / 1000) {
            for (int i = 0; i < 9; i++) {
                mutex->lock();
                if (_sharedMemory->ingredient[_id][i] < 5) {
                    _log->writeInfoMessage("Kitchen n°" + to_string(_id) + ": Add 1 " + tab[i]);
                    _sharedMemory->ingredient[_id][i] += 1;
                }
                mutex->unlock();
            }
            stock = std::chrono::steady_clock::now();
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
            _sharedMemory = openSharedMemory();
            key_t key = ftok("/etc/bashrc", 'B');
            _msqid = msgget(key, 0666);
        }

    }
}

Kitchen::~Kitchen()
{
}
Params::Params(int id, int mult, Cooker *cooker, int stockTime, kitchen_t *sharedMemory, Logs *log, int cook_id) : _id(id), _mult(mult), cooker(cooker), _stockTime(stockTime), _sharedMemory(sharedMemory), _log(log), _cook_id(cook_id) {

}

Params::~Params() {

}
