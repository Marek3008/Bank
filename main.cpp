#include <iostream>
#include "src/Bank/Bank.hpp"

int main() {
    Bank* bank = new Bank(30, 30);

    std::string names[] = {"Marek", "Jana", "Peter", "Lucia", "Michal", "Zuzana", "Tomas", "Lenka", "Adam", "Eva"};

    for(int i = 0; i < 20; i++) {
        std::string name = names[i % 10] + " " + std::to_string(i + 1);
        Client* c = bank->CreateClient(100 + i, name);
        Account* a = bank->CreateAccount(5000 + i, c);

        if(a != nullptr) a->Deposit(100.0 * (i + 1));
    }

    bank->CreateAccount(555, new Client(111, "ahoj"), 0.01, new Client(111, "cau"));
    bank->AddInterest();

    bank->PrintClients();
    bank->PrintAccounts();

    std::cout << "Počet klientov: " << Client::GetObjectsCount() << std::endl;
    std::cout << "Počet účtov: " << Account::GetObjectsCount() << std::endl;

    delete bank;
    return 0;
}