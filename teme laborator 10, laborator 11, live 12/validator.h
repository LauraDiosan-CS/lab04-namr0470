#pragma once
#include <iostream>
#include "repoFile.h"

class Validator {
private:
    RepositoryFile* repositoryFile;

public:
    Validator() {}
    Validator(RepositoryFile* repositoryFile) :repositoryFile(repositoryFile) {}

    int inputCommndRead(std::string msg) {

        int cmd;
        std::cout << std::endl << msg; std::cin >> cmd;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid try again\n";
            return inputCommndRead(msg);
        }
        return cmd;
    }

    bool idExist(std::string id) {

        vector<Articol*>array = this->repositoryFile->getAll();
        for (auto it : array) {
            if (it->get_id() == id)
                return false;
        }
        return true;
    }
};