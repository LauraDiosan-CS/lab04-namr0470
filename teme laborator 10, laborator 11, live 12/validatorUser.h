#pragma once
#include "fileRepoAcc.h"

class ValidatorUser {

private:
    FileRepoAccount repofileName;
public:
    ValidatorUser() {}
    ~ValidatorUser() {}
    ValidatorUser(FileRepoAccount& repofileName) {
        this->repofileName = repofileName;
    }

    Account id_exist(std::string id) {

        return this->repofileName.isInFile(id);
    }

};