#pragma once

#include "../Client/Client.hpp"
#include "../Account/Account.hpp"

class Bank{
    private:
        Client** clients;
        int clientsCapacity;

        Account** accounts;
        int accountsCapacity;

        Account* StoreAccount(Account* account);

    public:
        Bank(int clientsCapacity, int accountsCapacity);
        ~Bank();

        Client* GetClient(int clientNumber) const;
        Account* GetAccount(int accountNumber) const;

        Client* CreateClient(int c, std::string n);
        Account* CreateAccount(int n, Client* c, double ir = 0.01, Client* p = nullptr);

        void PrintClients() const;
        void PrintAccounts() const;
        void AddInterest();
};