/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_
#include "../my.hpp"

class Reception {
    public:
        Reception(int mult, int cookers, int stockTime);
        ~Reception();

        void launch();

    protected:
        int mult;
        int cookers;
        int stockTime;
    private:
};

#endif /* !RECEPTION_HPP_ */
