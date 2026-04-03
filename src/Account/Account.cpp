#include "Account.hpp"
#include <iostream>

Account::Account(int n, Client* c){
    this->number = n;
    this->owner = c;
    this->partner = nullptr;
}

Account::Account(int n, Client* c, double ir){
    this->number = n;
    this->owner = c;
    this->interestRate = ir;
    this->partner = nullptr;
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

void Account::AddInterest(){
    this->balance += this->balance * this->interestRate;
}

void Account::PrintAccount(){
    std::cout << "\tID: " << this->number << std::endl;
    std::cout << "\t\t" << "Vlastník: " << this->owner->GetCode() << " (" << this->owner->GetName() << ")" << std::endl;
    
    std::cout << "\t\tSpoluvlastník: ";
    if(this->partner == nullptr) std::cout << "<prázdne>" << std::endl;
    else std::cout << this->partner->GetCode() << " (" << this->partner->GetName() << ")" << std::endl;

    std::cout << "\t\tBilancia: " << this->balance << std::endl;
}