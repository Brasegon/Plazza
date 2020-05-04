/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Order
*/

#ifndef ORDER_HPP_
#define ORDER_HPP_
#include "../my.hpp"
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
        PizzaType getOrderPizzaName(std::string name) const;
    
    protected:
        std::string _command;
        std::vector<std::string> _orders;
    private:
};

#endif /* !ORDER_HPP_ */
