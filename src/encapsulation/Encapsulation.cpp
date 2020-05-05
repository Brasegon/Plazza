/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Encapsulation
*/

#include "Encapsulation.hpp"

Encapsulation::Encapsulation()
{
    key_t key = ftok("/etc/bashrc", 'A');
    _shmid = shmget(key, sizeof(kitchen_t), 0666 | IPC_CREAT);
    _sharedMemory = (kitchen_t *)shmat(_shmid, NULL, 0);

    key_t key2 = ftok("/etc/bashrc", 'B');
    _msqid = msgget(key2, IPC_CREAT | 0666);

    for (int i = 0; i < 20; i++) {
        _sharedMemory->status[i][0] = -1;
        _sharedMemory->status[i][1] = 5;
        _sharedMemory->status[i][2] = 5;
        _sharedMemory->status[i][3] = 5;
        _sharedMemory->status[i][4] = 5;
        _sharedMemory->status[i][5] = 5;
        _sharedMemory->status[i][6] = 5;
        _sharedMemory->status[i][7] = 5;
        _sharedMemory->status[i][8] = 5;
        _sharedMemory->status[i][9] = 5;
    }
}

kitchen_t *openSharedMemory()
{
    void *sharedMemory;
    int shmid;
    key_t key = ftok("/etc/bashrc", 'A');
    shmid = shmget(key, sizeof(kitchen_t), 0666);
    sharedMemory = shmat(shmid, NULL, 0);
    return (kitchen_t *)sharedMemory;
}

Encapsulation::~Encapsulation()
{
}