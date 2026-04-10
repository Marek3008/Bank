#pragma once

#include "../Account.hpp"
#include "../../Client/Client.hpp"


class PartnerAccount : public Account{
    private:
        Client* partner;

    public:
        PartnerAccount(int n, Client* o, Client* p, double ir = 0.01);

        Client* GetPartner() const;
        void PrintAccount() const override;
};