/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** my
*/

#ifndef MY_HPP_
#define MY_HPP_

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <map>
#include <functional>
#include <thread>
#include <chrono>
#include <mutex>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

enum PizzaType
{
    Error = -1,
    Regina = 1 ,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};
enum PizzaSize
{
    ErrorSize = -1,
    S = 1 ,
    M = 2 ,
    L = 4 ,
    XL = 8 ,
    XXL = 16
};


typedef struct kitchen {
    int status[20][10];
    std::mutex mutex;
} kitchen_t ;

kitchen_t *openSharedMemory();

#endif /* !MY_HPP_ */
