/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** logs
*/

#include "logs.hpp"


Logs::Logs()
{
    this->_currentTime = time(0);
    auto currentDate = getDate(this->_currentTime);
    this->_logsDir = "../../misc/logs/" << currentDate << ".txt"
    this->_logsFile(this->_logsDir);
    this->_logsFile << "====  LOGS  ====";
}

Logs::~Logs()
{
    this->_logsFile << "====  END  ====";
    this->_logsFile.close();
}

std::string Logs::getDate(time_t now)
{
    tm *ltm = localtime(&now);
    std::string year = 1900 + ltm->tm_year + ";";
    std::string month = 1 + ltm->tm_mon + ";";
    std::string day = ltm->tm_mday + ";";
    std::string hour = ltm->tm_hour + ":" + ltm->tm_min;
    std::string ret = year + month + day + hour;
    return (ret);
}

void Logs::getCurrentTime()
{

}