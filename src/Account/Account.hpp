#pragma once

#include "../Client/Client.hpp"

class Account{
    private:
        int number;
        double balance = 0;
        Client* owner;
        double interestRate;
        static int objectsCount;
        
    public:
        Account(int n, Client* c, double ir = 0.01);
        virtual ~Account();

        int GetNumber() const;
        double GetBalance() const;
        double GetInterestRate() const;
        Client* GetOwner() const;
        static int GetObjectsCount();

        void SetInterestRate(double ir);

        bool CanWithdraw(double balance) const;

        void Deposit(double balance);
        void Withdraw(double balance);
        void AddInterest();

        virtual void PrintAccount() const;
};