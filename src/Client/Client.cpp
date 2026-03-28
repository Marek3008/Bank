#include "Client.hpp"

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