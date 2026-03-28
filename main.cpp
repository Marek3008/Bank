#include <iostream>
#include "src/Client/Client.hpp"
#include "src/Account/Account.hpp"


int main(void){
    Client* client = new Client(123, "Marek Baňas");
    Account* account = new Account(1685351, client);

    std::cout << "Account Number: " << account->GetNumber() << std::endl;
    std::cout << "Owner: " << account->GetOwner()->GetName() << std::endl;
    
    return 0;
}