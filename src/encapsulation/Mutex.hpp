/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
#define MUTEX_HPP_
#include "../my.hpp"

class IMutex {
    public:
    virtual ~IMutex () = default ;
    virtual void lock () = 0;
    virtual void unlock () = 0;
    virtual void trylock () = 0;


    protected:
    private:
};

class Mutex : public IMutex {
    public:
        Mutex();
        virtual ~Mutex();
        void lock();
        void unlock();
        void trylock();

    protected:
        std::mutex mutex;
    private:
};

#endif /* !MUTEX_HPP_ */
