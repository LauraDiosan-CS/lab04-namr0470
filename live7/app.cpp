#include <iostream>
#include "entitate.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "teste.h"
using namespace std;
#define _CRTDBG_MAP_ALLOC
int main()
{
    cout << "...test run...";
    cout<<endl;
    test1();
    test2();
    test3();
    cout << "...good...";
    repoT<Entitate> r;
    serviceT serv;
    ui u(serv);
    u.showui();
    _CrtDumpMemoryLeaks();
    return 0;
}

