#include "../Client/Client.hpp"
#include "../Account/Account.hpp"

class Bank{
    private:
        Client** clients;
        int clientsCount;

        Account** accounts;
        int accountsCount;

        Account* StoreAccount(Account* account);

    public:
        Bank(int clientsCount, int accountsCount);
        ~Bank();

        Client* GetClient(int clientNumber);
        Account* GetAccount(int accountNumber);

        Client* CreateClient(int c, std::string n);
        Account* CreateAccount(int n, Client* c);
        Account* CreateAccount(int n, Client* c, double ir);
        Account* CreateAccount(int n, Client* c, Client* p);
        Account* CreateAccount(int n, Client* c, Client* p, double ir);

        void PrintClients();
        void PrintAccounts();
        void AddInterest();
};