#include "Account.hpp"

Account::Account(int n, Client* c){
    this->number = n;
    this->owner = c;
}

Account::Account(int n, Client* c, double ir){
    this->number = n;
    this->owner = c;
    this->interestRate = ir;
}

Account::Account(int n, Client* c, Client* p){
    this->number = n;
    this->owner = c;
    this->partner = p;
}

Account::Account(int n, Client* c, Client* p, double ir){
    this->number = n;
    this->owner = c;
    this->partner = p;
    this->interestRate = ir;
}

int Account::GetNumber(){
    return this->number;
}

double Account::GetBalance(){
    return this->balance;
}

double Account::GetInterestRate(){
    return this->interestRate;
}

Client* Account::GetOwner(){
    return this->owner;
}

Client* Account::GetPartner(){
    return this->partner;
}

bool Account::CanWithdraw(double balance){
    if(balance <= this->balance) return true;

    return false;
}

void Account::Deposit(double balance){
    this->balance += balance;
}

void Account::Withdraw(double balance){
    this->balance -= balance;
}