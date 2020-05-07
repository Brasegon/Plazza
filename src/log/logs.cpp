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
    this->_logsDir = "log.txt";
    _logsFile = ofstream(this->_logsDir);
    if (_logsFile) {
        cout << "Create log fichier :" << _logsDir << endl;
        this->_logsFile << "====  LOGS " << currentDate << " ====" << endl;
    }
}

Logs::~Logs()
{
    this->_logsFile << "====  END  ====";
    this->_logsFile.close();
}

std::string Logs::getDate(time_t now)
{
    tm *ltm = localtime(&now);
    std::string year = std::to_string(1900 + ltm->tm_year) + ".";
    std::string month = std::to_string(1 + ltm->tm_mon) + "/";
    std::string day = std::to_string(ltm->tm_mday) + "/";
    std::string hour = std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec);
    std::string ret = day + month + year + hour;
    return (ret);
}
void Logs::writeMessage(std::string msg) {
    this->_logsFile << "[" << getDate(time(0)) << "] " << msg << endl;
}

void Logs::getCurrentTime()
{

}