/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Encapsulation
*/

#ifndef ENCAPSULATION_HPP_
#define ENCAPSULATION_HPP_
#include "../my.hpp"

class Encapsulation {
    public:
        Encapsulation();
        ~Encapsulation();

    protected:
    private:
        kitchen_t *_sharedMemory;
        int _shmid;
        int _msqid;
};

#endif /* !ENCAPSULATION_HPP_ */
