#include <iostream>
#include "src/Client/Client.hpp"
#include "src/Account/Account.hpp"
#include "src/Bank/Bank.hpp"

int main(void){
    Bank* bank = new Bank(2, 2);

    Client* client1 = bank->CreateClient(123, "Marek Baňas");
    Client* client2 = bank->CreateClient(1111, "Niekto");
    Account* account = bank->CreateAccount(456, client1, client2);
    
    bank->PrintClients();
    bank->PrintAccounts();
    
    return 0;
}