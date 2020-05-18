#include "utils.h"
#include <iostream>

std::vector<std::string> splitLine(std::string linie, char delim)
{

    std::stringstream ss(linie);
    std::string item;
    std::vector<std::string> elems;

    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

bool except_date(std::string string) {

    int list_of_days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int nrok = 0, nrzile, nrluni, i;
    int nran = 0;

    if ('9' >= string[0] and string[0] >= '0' and '9' >= string[1] and string[1] >= '0' and string[2] == '.' and string[5] == '.') {
        nrzile = (string[0] - '0') * 10 + (string[1] - '0');
        nrluni = (string[3] - '0') * 10 + (string[4] - '0');
    }
    else
        return false;

    i = 6;

    while (i < int(string.size())) {
        if (string[i] == '.')
            return false;
        nran = nran * 10 + (string[i] - '0');
        i = i + 1;
    }

    if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] >= nrzile and nrzile > 0 and (nran % 4 == 0 or nran % 400 == 0))
        nrok = nrok + 1;
    else
        if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] > nrzile and nrzile > 0)
            nrok = nrok + 1;
    if (nrok == 1)
        return true;
    else
        return false;
}
void menu() {
    std::cout << std::endl << "0.Logout" << std::endl;
    std::cout << "1.Add a pet" << std::endl;
    std::cout << "2.Add a pet stuff" << std::endl;
    std::cout << "3.Print all shop" << std::endl;
    std::cout << "4.Update pet" << std::endl;
    std::cout << "5.Update pet stuff" << std::endl;
    std::cout << "6.Delete a pet" << std::endl;
    std::cout << "7.Delete a pet stuff" << std::endl;
    /* std::cout << "2.Search by name" << std::endl;
     std::cout << "3.Search by date" << std::endl;
     std::cout << "4.Buy a number of pieces by a given code" << std::endl;*/
}