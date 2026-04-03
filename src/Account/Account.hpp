#pragma once

#include "../Client/Client.hpp"

class Account{
    private:
        int number;
        double balance = 0;
        double interestRate = 0.01;

        Client* owner;
        Client* partner;

    public:
        Account(int n, Client* c);
        Account(int n, Client* c, double ir);
        Account(int n, Client* c, Client* p);
        Account(int n, Client* c, Client* p, double ir);

        int GetNumber();
        double GetBalance();
        double GetInterestRate();
        Client* GetOwner();
        Client* GetPartner();

        bool CanWithdraw(double balance);

        void Deposit(double balance);
        void Withdraw(double balance);
        void AddInterest();

        void PrintAccount();
};