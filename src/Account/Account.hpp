#pragma once

#include "../Client/Client.hpp"

class Account{
    private:
        int number;
        double balance = 0;
        double interestRate;
        static int objectsCount;

        Client* owner;
        Client* partner;

    public:
        /*Account(int n, Client* c);
        Account(int n, Client* c, double ir);
        Account(int n, Client* c, Client* p);*/
        Account(int n, Client* c, Client* p = nullptr, double ir = 0.01);
        ~Account();

        int GetNumber() const;
        double GetBalance() const;
        double GetInterestRate() const;
        Client* GetOwner() const;
        Client* GetPartner() const;
        static int GetObjectsCount();

        Client* SetPartner(Client* p);

        bool CanWithdraw(double balance) const;

        void Deposit(double balance);
        void Withdraw(double balance);
        void AddInterest();

        void PrintAccount() const;
};