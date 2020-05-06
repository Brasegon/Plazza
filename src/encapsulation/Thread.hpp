/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_
#include "../my.hpp"

class IThread {
    public:
    virtual ~IThread() = default;
    virtual void join() = 0;
    virtual void detach() = 0;
};

class Thread : public IThread{
    public:
        Thread(std::thread);
        virtual ~Thread();
        void join();
        void detach();

    protected:
    private:
        std::thread _thread;
};

#endif /* !THREAD_HPP_ */
