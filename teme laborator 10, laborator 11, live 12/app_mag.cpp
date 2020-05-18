#include <iostream>
#include "testAnimal.h"
#include "testProdus.h"
#include "testArticol.h"
#include "testRepoFile.h"
#include "ui.h"
#include "testServShop.h"
int main()
{
    TestsPet testsPet;
    testsPet.allTestsPet();

    TestsPetStuff testsPetStuff;
    testsPetStuff.allTestsPetStuff();

    TestsProduct testsProduct;
    testsProduct.allTestsProduct();

    TestsRepositoryFile testsRepositoryFile;
    testsRepositoryFile.allTestsRepositoryFile();

    TestsServiceShop testsServiceShop;
    testsServiceShop.runAllTestsShop();

    RepositoryFile* repositoryFile;
    cout << "TXT sau CSV?";
    string opt;
    do {
        getline(cin, opt);
        if (opt == ".txt")
        {
            repositoryFile = new RepositoryFileTXT("Shop.txt");
            break;
        }
        else
        {
            if (opt == ".csv")
            {
                repositoryFile = new RepositoryFileCSV("Shop.csv");
                break;
            }
        }
    } while (true);

    FileRepoAccount repositoryFileAccount("AccountDataBase.txt");
    ServiceAccount serviceAccount(repositoryFileAccount);
    UIAccount uiAccount(serviceAccount);

    Validator validator(repositoryFile);
    repositoryFile->loadFromFile();
    ServiceShop serviceShop(repositoryFile);
    UI ui(serviceShop, uiAccount, validator);
    ui.run();

    return 0;
}
