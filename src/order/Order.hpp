/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Order
*/

#ifndef ORDER_HPP_
#define ORDER_HPP_
#include "../my.hpp"
#include "../pizza/Pizza.hpp"
class Order {
    public:
        Order(std::string &command);
        virtual ~Order();

        void parseOrder();
        int createPizza(std::vector<string> order);
        
        //printer
        void printOrders();
        //setter
        void setOrders(std::vector<std::string> &order);
        // getter
        const std::vector<std::string> &getOrders() const;
        int getOrderPizzaName(std::string name, std::string size, int number);
        const std::vector<Pizza *> &getPizzaList() const;
        //dump
        void dump();
    protected:
        std::string _command;
        std::vector<std::string> _orders;
        std::vector<Pizza *> pizzaList;
    private:
};
Pizza *margaritaPizza(PizzaSize size);
#endif /* !ORDER_HPP_ */
