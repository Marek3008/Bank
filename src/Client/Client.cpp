#include "Client.hpp"
#include <iostream>

Client::Client(int c, std::string n){
    this->code = c;
    this->name = n;
}

int Client::GetCode(){
    return this->code;
}

std::string Client::GetName(){
    return this->name;
}

void Client::PrintClient(){
    std::cout << "\tID: " << this->code << "; Meno: " << this->name << std::endl;
}