#pragma once

#include <string>

class Client{
    private:
        int code;
        std::string name;
        static int objectsCount;
    
    public:
        Client(int c, std::string n);
        ~Client();

        int GetCode() const;
        std::string GetName() const;
        static int GetObjectsCount();
        void PrintClient() const;
};