/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(int id, int mult, int cookers, int stockTime) : _id(id), _mult(mult), _cookers(cookers), _stockTime(stockTime)
{
    std::cout << "Created kitchen : " << _id << std::endl;
    _sharedMemory = openSharedMemory();
    std::unique_lock<std::mutex> lock(_sharedMemory->mutex);
    _sharedMemory->status[_id][0] = _cookers;
    lock.unlock();
    key_t key = ftok("/etc/bashrc", 'B');
    _msqid = msgget(key, 0666);

}
void test(int i) {
    std::this_thread::sleep_for (std::chrono::seconds(1));
}
void Kitchen::run() {
    std::thread t[_cookers];
    for (int i = 0; i < _cookers; i += 1) {
        //Cooker *cooker = new Cooker();
        t[i] = std::thread(test, i);
        t[i].detach();
    }
}

Kitchen::~Kitchen()
{
}
