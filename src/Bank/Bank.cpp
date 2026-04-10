#include "Bank.hpp"
#include "../Account/PartnerAccount/PartnerAccount.hpp"
#include <iostream>

Bank::Bank(int clientsCapacity, int accountsCapacity) : clientsCapacity(clientsCapacity), accountsCapacity(accountsCapacity){
    this->clients = new Client*[clientsCapacity]();
    this->accounts = new Account*[accountsCapacity]();
}

Bank::~Bank(){
    for(int i = 0; i < this->clientsCapacity; i++){
        delete clients[i];
    }

    for(int i = 0; i < this->accountsCapacity; i++){
        delete accounts[i];
    }

    delete[] clients;
    delete[] accounts;
}

Client* Bank::GetClient(int clientNumber) const {
    for(int i = 0; i < this->clientsCapacity; i++){
        if(clients[i] != nullptr && clients[i]->GetCode() == clientNumber) return clients[i];
    }

    return nullptr;
}

Account* Bank::GetAccount(int accountNumber) const {
    for(int i = 0; i < this->accountsCapacity; i++){
        if(accounts[i] != nullptr && accounts[i]->GetNumber() == accountNumber) return accounts[i];
    }

    return nullptr;
}

Client* Bank::CreateClient(int c, std::string n){
    Client* client = new Client(c, n);

    for(int i = 0; i < this->clientsCapacity; i++){
        if(clients[i] == nullptr){
            clients[i] = client;
            return client;
        }
    }

    std::cout << "Nemôžeme pridať ďaľšieho klienta" << std::endl;

    delete client;
    return nullptr;
}

Account* Bank::StoreAccount(Account* account){
    for(int i = 0; i < this->accountsCapacity; i++){
        if(accounts[i] == nullptr){
            accounts[i] = account;
            return account;
        }
    }

    std::cout << "Nemôžeme pridať ďaľší účet" << std::endl;
    
    delete account;
    return nullptr;
}

/*Account* Bank::CreateAccount(int n, Client* c){
    return StoreAccount(new Account(n, c));
}

Account* Bank::CreateAccount(int n, Client* c, double ir){
    return StoreAccount(new Account(n, c, ir));
}

Account* Bank::CreateAccount(int n, Client* c, Client* p){
    return StoreAccount(new Account(n, c, p));
}*/

Account* Bank::CreateAccount(int n, Client* c, double ir, Client* p){
    if (p != nullptr) return StoreAccount(new PartnerAccount(n, c, p, ir));

    return StoreAccount(new Account(n, c, ir));
}

void Bank::PrintClients() const {
    std::cout << "List klientov:" << std::endl;

    for(int i = 0; i < this->clientsCapacity; i++){
        if(clients[i] == nullptr) std::cout << "\t<prázdne>" << std::endl;
        else clients[i]->PrintClient();
    }
    
    std::cout << std::endl;
}

void Bank::PrintAccounts() const {
    std::cout << "List účtov:" << std::endl;

    for(int i = 0; i < this->accountsCapacity; i++){
        if(accounts[i] == nullptr) std::cout << "\t<prázdne>" << std::endl;
        else accounts[i]->PrintAccount();
    }
}

void Bank::AddInterest(){
    for(int i = 0; i < this->accountsCapacity; i++){
        if(accounts[i] != nullptr) accounts[i]->AddInterest();
    }
}