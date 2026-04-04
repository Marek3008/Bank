#include "Client.hpp"
#include <iostream>


int Client::objectsCount = 0;

Client::Client(int c, std::string n) : code(c), name(n) {
    Client::objectsCount++;
}
Client::~Client(){
    Client::objectsCount--;
}

int Client::GetCode() const {
    return this->code;
}

std::string Client::GetName() const{
    return this->name;
}

int Client::GetObjectsCount(){
    return Client::objectsCount;
}

void Client::PrintClient() const {
    std::cout << "\tID: " << this->code << "; Meno: " << this->name << std::endl;
}