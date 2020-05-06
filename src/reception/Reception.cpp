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
int Reception::check_kitchen() {
    for (int i = cookers; i > 0; i--){
        for (int j = 0; j < 20; j++) {
            std::unique_lock<std::mutex> lock(_sharedMemory->mutex);
            if (_sharedMemory->cooker[j] == i)
                return j;
            lock.unlock();
        }
    }
    return (-1);
}
int Reception::createKitchen() {

    for (int i = 0; i < 20; i++) {
        std::unique_lock<std::mutex> lock(_sharedMemory->mutex);
        if (_sharedMemory->cooker[i] == -1) {
            return i;
        }
        lock.unlock();
    }
    return (-1);
}

void Reception::forkNewKitchen() {
    pid_t pid;
    int status = 0;
    int id = 0;

    if ((pid = fork()) == -1)
        perror("fork");
    if (pid == 0) {
        if ((id = createKitchen()) != -1) {
            Kitchen k(id, mult, cookers, stockTime);
            k.run();
            while(true);
        } else {
            cout << "Not created kitchen because max kitchen" << endl;
        }
    }
    waitpid(pid, &status, WNOHANG);
}

void Reception::sendOrders() {
    int id = 0;

    while (orderPizza.size()) {
        std::this_thread::sleep_for (std::chrono::milliseconds(10));
        if ((id = check_kitchen()) != -1) {
            _sendBuffer.pizza = orderPizza[orderPizza.size() - 1];
            _sendBuffer.mtype = id + 1;
            if (msgsnd(_shm->getMsqid(), &_sendBuffer, sizeof(Pizza *), IPC_NOWAIT) < 0)
                cerr << "Erreur msgsnd" << endl;
            orderPizza.pop_back();
        } else {
            forkNewKitchen();
        }
    }
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


