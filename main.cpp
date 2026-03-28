#include <iostream>
#include "src/Client/Client.hpp"
#include "src/Account/Account.hpp"
#include "src/Bank/Bank.hpp"

int main(void){
    Bank* bank = new Bank(2, 2);

    Client* client = bank->CreateClient(123, "Marek Baňas");
    
    bank->PrintClients();
    
    return 0;
}