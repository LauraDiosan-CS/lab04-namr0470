#pragma once
#include <fstream>
#include <string>
#include "account.h"
class FileRepoAccount {

private:
    std::string fileName;

public:
    FileRepoAccount() {
        this->fileName = "";
    }

    ~FileRepoAccount() {
        this->fileName = "";
    }

    FileRepoAccount(std::string file) {
        this->fileName = file;
    }

    Account isInFile(std::string id) {

        std::fstream file;
        file.open(this->fileName, std::ios::out | std::ios::in | std::ios::app);
        if (file.is_open()) {

            while (!file.eof()) {
                Account account;
                file >> account;
                if (account.get_id() == id)
                    return account;
            }
        }
        return Account("", "");
    }

    void saveinFile(Account account) {

        std::fstream file;
        file.open(this->fileName, std::ios::out | std::ios::in | std::ios::app);
        if (file.is_open()) {

            file << account;
        }
        file.close();
    }
};