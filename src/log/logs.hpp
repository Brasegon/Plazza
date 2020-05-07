/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** logs
*/

#ifndef LOGS_HPP_
#define LOGS_HPP_

#include "../my.hpp"

class Logs
{
protected:
    time_t _currentTime;
    std::string _logsDir;
    ofstream _logsFile;
private:
    std::string getDate(time_t time);
    void getCurrentTime();
public:
    Logs(/* args */);
    ~Logs();
    void initLogs();
    void writeMessage(std::string msg);
};

#endif /* !LOGS_HPP_ */
