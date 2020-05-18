#pragma once
#include "fileRepoAcc.h"
#include "validatorUser.h"
#include "error.h"

class ServiceAccount {

private:
    FileRepoAccount repoFile;
    ValidatorUser validator;
public:
    ServiceAccount() {}
    ~ServiceAccount() {}
    ServiceAccount(FileRepoAccount& repo) :validator(repo) {
        this->repoFile = repo;
    }

    Response login(std::string id, std::string pass) {

        Response message;
        Account account(id, pass);
        Account existingAccount = this->validator.id_exist(id);
        if (account == existingAccount) {
            message.append("----------- Login successful -----------");
            message.setSuccess(true);
            message.append("");
            return message;
        }
        else {

            message.append("----------------------");
            message.append("ID or password incorrect");
            message.append("Try again (1) or sign in (0)");
            message.append("");
            message.setSuccess(false);
            return message;
        }

    }

    Response signIn(std::string id, std::string pass) {

        Response message;

        Account account = this->validator.id_exist(id);
        if (account.get_id() != id and account.get_pass() != pass) {
            message.append("----------- Sign in successful -----------");
            message.append("");
            Account account2(id, pass);
            this->repoFile.saveinFile(account2);
            message.setSuccess(true);
            return message;
        }
        else {
            message.append("----------------------");
            message.append("ID already exist ");
            message.append("----------------------");
            message.append("Try again (1) or sign in (0)");
            message.append("");
            message.setSuccess(false);
            return message;
        }
    }
};