/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Process
*/

#include "Process.hpp"

Process::Process()
{
    _pid = fork();
    if (_pid < 0) {
        std::cerr << "Fork failed" << "\n";
    }
}

const pid_t &Process::getPid() const {
    return _pid;
}

void Process::wait()
{
    int status;
    waitpid(_pid, &status, WNOHANG);
}

Process::~Process()
{
}
