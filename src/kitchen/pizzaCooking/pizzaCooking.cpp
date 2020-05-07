/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** pizzaCooking
*/
#include "../Kitchen.hpp"

void reginaCooking(Params *p) {
    if (p->_sharedMemory->ingredient[p->_id][1] > 0
        && p->_sharedMemory->ingredient[p->_id][2] > 0
        && p->_sharedMemory->ingredient[p->_id][3] > 0
        && p->_sharedMemory->ingredient[p->_id][4] > 0
        && p->_sharedMemory->ingredient[p->_id][5] > 0) {
            p->_log->writeMessage("Kitchen n°" + to_string(p->_id) + ": Regina is cooking");
            p->_sharedMemory->ingredient[p->_id][1] -= 1;
            p->_sharedMemory->ingredient[p->_id][2] -= 1;
            p->_sharedMemory->ingredient[p->_id][3] -= 1;
            p->_sharedMemory->ingredient[p->_id][4] -= 1;
            p->_sharedMemory->ingredient[p->_id][5] -= 1;
            std::this_thread::sleep_for(std::chrono::seconds(2 * p->_mult));
            p->_sharedMemory->cooker[p->_id] += 1;
            p->_log->writeMessage("Kitchen n°" + to_string(p->_id) + ": Regina is ready");
            p->cooker->_isWorking = false;
        }
}
void margaritaCooking(Params *p) {
    p->_log->writeMessage("Kitchen n°" + to_string(p->_id) + ": Stock : \t" + to_string(p->_sharedMemory->ingredient[p->_id][1]));
    if (p->_sharedMemory->ingredient[p->_id][1] > 0
        && p->_sharedMemory->ingredient[p->_id][2] > 0
        && p->_sharedMemory->ingredient[p->_id][3] > 0) {
            p->_log->writeMessage("Kitchen n°" + to_string(p->_id) + ": Margarita is cooking");
            p->_sharedMemory->ingredient[p->_id][1] -= 1;
            p->_sharedMemory->ingredient[p->_id][2] -= 1;
            p->_sharedMemory->ingredient[p->_id][3] -= 1;
            std::this_thread::sleep_for(std::chrono::seconds(1 * p->_mult));
            p->_sharedMemory->cooker[p->_id] += 1;
            p->_log->writeMessage("Kitchen n°" + to_string(p->_id) + ": Margarita is ready");
            p->cooker->_isWorking = false;
        }
}