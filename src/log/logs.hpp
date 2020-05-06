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
    auto _currentTime;
    std::string _logsDir;
    ofstream _logsFile;
private:
    void getDate(time_t time);
    void getCurrentTime();
public:
    Logs(/* args */);
    ~Logs();
    void initLogs();
};

#endif /* !LOGS_HPP_ */
