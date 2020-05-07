/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Process
*/

#ifndef PROCESS_HPP_
#define PROCESS_HPP_
#include "../my.hpp"

class Process {
    public:
        Process();
        ~Process();
        const pid_t &getPid() const;
        void wait();
    protected:
    private:
        pid_t _pid;
};

#endif /* !PROCESS_HPP_ */
