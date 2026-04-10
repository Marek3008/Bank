#include "Account.hpp"
#include <iostream>


int Account::objectsCount = 0;

Account::Account(int n, Client* c, Client* p, double ir) : number(n), interestRate(ir), owner(c), partner(p)  {
    Account::objectsCount++;
}

Account::Account(int n, Client* c, double ir, Client* p) : number(n), interestRate(ir), owner(c), partner(p) {
    Account::objectsCount++;
}

Account::~Account(){
    Account::objectsCount--;
}

/*Account::Account(int n, Client* c) : Account(n, c, nullptr, 0.0) {}

Account::Account(int n, Client* c, double ir) : Account(n, c, nullptr, ir) {}

Account::Account(int n, Client* c, Client* p) : Account(n, c, p, 0.0) {}*/

int Account::GetNumber() const {
    return this->number;
}

double Account::GetBalance() const {
    return this->balance;
}

double Account::GetInterestRate() const {
    return this->interestRate;
}

Client* Account::GetOwner() const {
    return this->owner;
}

Client* Account::GetPartner() const {
    return this->partner;
}

int Account::GetObjectsCount(){
    return Account::objectsCount;
}

Client* Account::SetPartner(Client* p){
    this->partner = p;

    return this->partner;
}

void Account::SetInterestRate(double ir){
    this->interestRate = ir;
}

bool Account::CanWithdraw(double amount) const {
    if(amount <= this->balance) return true;

    return false;
}

void Account::Deposit(double balance){
    this->balance += balance;
}

void Account::Withdraw(double amount){
    if(CanWithdraw(amount)) this->balance -= amount;
}

void Account::AddInterest(){
    this->balance += this->balance * this->interestRate;
}

void Account::PrintAccount() const {
    std::cout << "\tID: " << this->number << std::endl;
    std::cout << "\t\t" << "Vlastník: " << this->owner->GetCode() << " (" << this->owner->GetName() << ")" << std::endl;
    
    std::cout << "\t\tSpoluvlastník: ";
    if(this->partner == nullptr) std::cout << "<prázdne>" << std::endl;
    else std::cout << this->partner->GetCode() << " (" << this->partner->GetName() << ")" << std::endl;

    std::cout << "\t\tBilancia: " << this->balance << std::endl;
}