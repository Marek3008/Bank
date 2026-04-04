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
        /*Account* CreateAccount(int n, Client* c);
        Account* CreateAccount(int n, Client* c, double ir);
        Account* CreateAccount(int n, Client* c, Client* p);*/
        Account* CreateAccount(int n, Client* c, Client* p = nullptr, double ir = 0.01);

        void PrintClients() const;
        void PrintAccounts() const;
        void AddInterest();
};