/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Thread
*/

#include "Thread.hpp"

Thread::Thread(std::thread t)
{
    _thread.swap(t);
}

Thread::~Thread()
{
}

void Thread::join()
{
    _thread.join();
}

void Thread::detach()
{
    _thread.detach();
}