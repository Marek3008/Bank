#include "Account.hpp"
#include "PartnerAccount/PartnerAccount.hpp"
#include <iostream>


int Account::objectsCount = 0;

Account::Account(int n, Client* c, double ir) : number(n), owner(c), interestRate(ir) {
    Account::objectsCount++;
}

Account::~Account(){
    Account::objectsCount--;
}

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

int Account::GetObjectsCount(){
    return Account::objectsCount;
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

    std::cout << "\t\tBilancia: " << this->balance << std::endl;
}