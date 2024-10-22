/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** pizzaCooking
*/
#include "../Kitchen.hpp"

std::vector<string> list = {
        "does", "tomatoes", "gruyere", "ham", "mushrooms", "steak", "eggplant", "goat cheese", "chief love"
    };

void reginaCooking(Params *p) {
    uint64_t numberIngredient = 0;
    std::vector<string> ingredient = p->cooker->getIngredient();
    for (uint64_t i = 0; i < ingredient.size(); i += 1) {
        for (uint64_t j = 0; j < list.size(); j += 1) {
            if (ingredient[i] == list[j]) {
                if (p->_sharedMemory->ingredient[p->_id][j] > 0) {
                    p->_sharedMemory->ingredient[p->_id][j] -= 1;
                    numberIngredient += 1;
                }
            }

        }
    }
    if (numberIngredient == p->cooker->getIngredient().size()) {
        p->_log->writeInfoMessage("Kitchen n°" + to_string(p->_id) + ": " + p->cooker->getPizza() + " is cooking by Cooker n°" + to_string(p->_cook_id));
        std::this_thread::sleep_for(std::chrono::seconds(p->cooker->getTime() * p->_mult));
        p->_sharedMemory->cooker[p->_id] += 1;
        p->_log->writeInfoMessage("Kitchen n°" + to_string(p->_id) + ": " + p->cooker->getPizza() + " is ready and work by Cooker n°" + to_string(p->_cook_id));
        p->cooker->_isWorking = false;
    }
}
void margaritaCooking(Params *p) {
    int numberIngredient = 0;
    std::vector<string> ingredient = p->cooker->getIngredient();
    for (uint64_t i = 0; i < ingredient.size(); i += 1) {
        for (uint64_t j = 0; j < list.size(); j += 1) {
            if (ingredient[i] == list[j]) {
                if (p->_sharedMemory->ingredient[p->_id][j] > 0) {
                    p->_sharedMemory->ingredient[p->_id][j] -= 1;
                    numberIngredient += 1;
                }
            }
        }
    }
    if (numberIngredient == 3) {
        p->_log->writeInfoMessage("Kitchen n°" + to_string(p->_id) + ": Margarita is cooking by Cooker n°" + to_string(p->_cook_id));
        std::this_thread::sleep_for(std::chrono::seconds(1 * p->_mult));
        p->_sharedMemory->cooker[p->_id] += 1;
        p->_log->writeInfoMessage("Kitchen n°" + to_string(p->_id) + ": Margarita is ready and work by Cooker n°" + to_string(p->_cook_id));
        p->cooker->_isWorking = false;
    }
}

void americanaCooking(Params *p) {
    int numberIngredient = 0;
    std::vector<string> ingredient = p->cooker->getIngredient();
    for (uint64_t i = 0; i < ingredient.size(); i += 1) {
        for (uint64_t j = 0; j < list.size(); j += 1) {
            if (ingredient[i] == list[j]) {
                if (p->_sharedMemory->ingredient[p->_id][j] > 0) {
                    p->_sharedMemory->ingredient[p->_id][j] -= 1;
                    numberIngredient += 1;
                }
            }
        }
    }
    if (numberIngredient == 4) {
        p->_log->writeInfoMessage("Kitchen n°" + to_string(p->_id) + ": Americana is cooking by Cooker n°" + to_string(p->_cook_id));
        std::this_thread::sleep_for(std::chrono::seconds(1 * p->_mult));
        p->_sharedMemory->cooker[p->_id] += 1;
        p->_log->writeInfoMessage("Kitchen n°" + to_string(p->_id) + ": Margarita is ready and work by Cooker n°" + to_string(p->_cook_id));
        p->cooker->_isWorking = false;
    }
}