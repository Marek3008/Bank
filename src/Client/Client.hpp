#pragma once

#include <string>

class Client{
    private:
        int code;
        std::string name;
    
    public:
        Client(int c, std::string n);

        int GetCode();
        std::string GetName();
        void PrintClient();
};