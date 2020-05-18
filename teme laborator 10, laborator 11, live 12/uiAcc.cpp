#include "uiAcc.h"

bool UIAccount::signInaccount() {

    std::cout << std::endl << "----------- Sing in -----------" << std::endl;
    std::string id = ID();
    std::string pass = password();

    Response message = this->service.signIn(id, pass);
    printMessage(message);

    return message.isSuccess();
}

bool UIAccount::logInaccount() {

    std::cout << std::endl << std::endl << "----------- Login -----------" << std::endl;

    std::string id = ID();
    std::string pass = password();
    Response message = this->service.login(id, pass);
    printMessage(message);
    return message.isSuccess();
}

int UIAccount::input_commnd_read() {

    int cmd;
    std::cout << std::endl << "Command:"; std::cin >> cmd;
    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please input a number between 0 and 1!\n";
        return input_commnd_read();
    }
    if (cmd < -1 || cmd > 1) {
        std::cout << "Please input a number between 0 and 1!\n";
        return input_commnd_read();
    }
    return cmd;
}

std::string UIAccount::ID() {

    std::cout << "ID: ";
    std::string id;
    std::cin >> id;
    std::cout << std::endl;

    return id;
}

std::string UIAccount::password() {

    std::cout << "Password: ";
    char* s = new char[10];
    int n = 0, x;
    int i;
    i = 0;
    while (i < 18) {
        x = _getch();
        if (x != 13 and x != 8) {
            s[n++] = x;
            _putch('*');
            i++;
        }
        else
            if (x == 8 and n > 0)
            {
                s[n--];
                _putch('\b');
                _putch(' ');
                _putch('\b');
                i--;
            }
            else
                if (x == 8 and i > 0)
                    i--;
                else
                    if (x == 13)
                        i = 18;

    }

    std::string str;
    str.resize(n);
    for (i = 0; i < n; i++)
        str[i] = s[i];
    return str;
}

void UIAccount::printMessage(Response message) {

    std::vector<std::string> messages = message.getAll();

    for (int i = 0; i < int(messages.size()); i++) {
        std::cout << std::endl << messages[i] << ' ';
    }
}
bool UIAccount::logIn() {

    bool logInsuccess;
    logInsuccess = this->logInaccount();
    if (!logInsuccess) {
        int opt1 = input_commnd_read();
        if (opt1 == 0) {
            return this->signIn();
        }
        else
            return this->logIn();
    }
    else
        return logInsuccess;
}

bool UIAccount::signIn() {
    bool isSuccesssigin;
    isSuccesssigin = this->signInaccount();
    if (!isSuccesssigin) {
        int opt1 = input_commnd_read();
        if (opt1 == 0) {
            return this->signIn();
        }
        else
            return this->logIn();
    }
    else
        return this->logIn();
}
