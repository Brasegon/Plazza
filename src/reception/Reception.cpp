/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019 [WSL: Debian]
** File description:
** Reception
*/

#include "Reception.hpp"


Reception::Reception(int mult, int cookers, int stockTime) : mult(mult), cookers(cookers), stockTime(stockTime)
{
}

Reception::~Reception()
{
}

int Reception::requestOrder(std::string &command) {
    Order orders(command);
    orders.parseOrder();
    
    for (uint64_t i = 0; i < orders.getPizzaList().size(); i += 1) {
        orderPizza.push_back(orders.getPizzaList()[i]);
    }
    std::cout << "==> Votre commande de " << orders.getPizzaList().size() << " pizza(s) a été effectué." << endl;
    return (0);
}

void Reception::sendOrders() {
    // while (orderPizza.size()) {
    //     std::this_thread::sleep_for (std::chrono::milliseconds(10));
    // }
}

void Reception::status() {
    std::cout << "===== STATUS =====" << std::endl;
    std::cout << "Nombre de Pizza en attente : " << orderPizza.size() << endl;
}
void Reception::launch() {
    string line;
    _shm = new Encapsulation();
    _sharedMemory = openSharedMemory();
    cout << "======= Welcome to Pizza'Tek =======" << endl;
    while (1) {
        cout << "==> Que voulez vous ?" << endl;
        cout << "> ";
        getline(cin, line);
        if (line.compare("quit") == 0) {
            exit(0);
        }
        else if (line.compare("status") == 0) {
            status();
        }
        else if (Reception::requestOrder(line) == -1) {
            cout << "Invalid Request Order" << endl;
        } else {
            sendOrders();
        }
    }
}


