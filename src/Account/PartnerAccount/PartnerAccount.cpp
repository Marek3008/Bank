#include "PartnerAccount.hpp"
#include <iostream>

PartnerAccount::PartnerAccount(int n, Client* o, Client* p, double ir) : Account(n, o, ir), partner(p) {}

Client* PartnerAccount::GetPartner() const {
    return this->partner;
};

void PartnerAccount::PrintAccount() const {
    Account::PrintAccount();

    std::cout << "\t\tSpoluvlastník: ";
    std::cout << this->partner->GetCode() << " (" << this->partner->GetName() << ")" << std::endl;
}