#include "Bank.hpp"
#include <iostream>

Bank::Bank(int clientsCount, int accountsCount){
    this->clientsCount = clientsCount;
    this->accountsCount = accountsCount;

    this->clients = new Client*[clientsCount]();
    this->accounts = new Account*[accountsCount]();
}

Bank::~Bank(){
    for(int i = 0; i < clientsCount; i++){
        delete clients[i];
    }

    for(int i = 0; i < accountsCount; i++){
        delete accounts[i];
    }

    delete[] clients;
    delete[] accounts;
}

Client* Bank::GetClient(int clientNumber){
    for(int i = 0; i < this->clientsCount; i++){
        if(clients[i] != nullptr && clients[i]->GetCode() == clientNumber) return clients[i];
    }

    return nullptr;
}

Account* Bank::GetAccount(int accountNumber){
    for(int i = 0; i < this->accountsCount; i++){
        if(accounts[i] != nullptr && accounts[i]->GetNumber() == accountNumber) return accounts[i];
    }

    return nullptr;
}

Client* Bank::CreateClient(int c, std::string n){
    Client* client = new Client(c, n);

    for(int i = 0; i < this->clientsCount; i++){
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
    for(int i = 0; i < this->accountsCount; i++){
        if(accounts[i] == nullptr){
            accounts[i] = account;
            return account;
        }
    }

    std::cout << "Nemôžeme pridať ďaľší účet" << std::endl;
    
    delete account;
    return nullptr;
}

Account* Bank::CreateAccount(int n, Client* c){
    return StoreAccount(new Account(n, c));
}

Account* Bank::CreateAccount(int n, Client* c, double ir){
    return StoreAccount(new Account(n, c, ir));
}

Account* Bank::CreateAccount(int n, Client* c, Client* p){
    return StoreAccount(new Account(n, c, p));
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir){
    return StoreAccount(new Account(n, c, p, ir));
}

void Bank::PrintClients(){
    std::cout << "List klientov:" << std::endl;

    for(int i = 0; i < this->clientsCount; i++){
        if(clients[i] == nullptr) std::cout << "\t<prázdne>" << std::endl;
        else std::cout << "\tID: " << clients[i]->GetCode() << "; Meno: " << clients[i]->GetName() << std::endl;
    }
    
    std::cout << std::endl;
}

void Bank::PrintAccounts(){
    std::cout << "List účtov:" << std::endl;

    for(int i = 0; i < this->accountsCount; i++){
        if(accounts[i] == nullptr) std::cout << "\t<prázdne>" << std::endl;
        else{
            std::cout << "\tID: " << accounts[i]->GetNumber() << std::endl;
            std::cout << "\t\t" << "Vlastník: " << accounts[i]->GetOwner()->GetCode() << " (" << accounts[i]->GetOwner()->GetName() << ")" << std::endl;
            
            std::cout << "\t\tSpoluvlastník: ";
            if(accounts[i]->GetPartner() == nullptr) std::cout << "<prázdne>" << std::endl;
            else std::cout << accounts[i]->GetPartner()->GetCode() << " (" << accounts[i]->GetPartner()->GetName() << ")" << std::endl;

            //dorobit
        } 
    }
}

void Bank::AddInterest(){
    for(int i = 0; i < this->accountsCount; i++){
        if(accounts[i] != nullptr) accounts[i]->AddInterest();
    }
}