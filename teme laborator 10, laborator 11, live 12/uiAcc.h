#pragma once
#include <iostream>
#include "servAcc.h"
#include <conio.h>

class UIAccount {

private:
    ServiceAccount service;
    bool signInaccount();
    bool logInaccount();
public:
    UIAccount() {}
    ~UIAccount() {}
    UIAccount(ServiceAccount& service) :service(service) {}
    bool logIn();
    bool signIn();
    int input_commnd_read();
    std::string ID();
    std::string password();
    void printMessage(Response);

    bool runAccount() {

        int opt;
        bool responseLogin = false;
        std::cout << "" << std::endl;
        std::cout << "----You need to loggin to have access----" << std::endl;
        std::cout << "  --Press 1 to have access to login" << std::endl << "  --Press 0 to sing in" << std::endl;
        opt = input_commnd_read();
        if (opt == 1) {
            responseLogin = this->logIn();
        }
        else
            if (opt == 0) {
                responseLogin = this->signIn();
            }
        return responseLogin;
    }
};