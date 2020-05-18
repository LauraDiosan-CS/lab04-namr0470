#pragma once
#include "articol.h"
#include "animal.h"
#include "repoFile.h"
#include "serviceShop.h"
#include "repoFileTXT.h"
#include "assert.h"
void test_live()
{
	RepositoryFile* repo=new RepositoryFileTXT("TestsServiecShop.txt");
	Articol*  a1 = new animal("554", "papagal","01.04.2020",  100, 2, 5);
	Articol* a2 = new produs("554", "mancare_pesti", "11.12.2019", 30,12,"01.01.2022");
	Articol* a3= new animal("555", "papagal", "03.05.2020",60,  1, 3);
	Articol* a4= new animal("554", "papagal","07.03.2020",  70, 3, 3);
	Articol* a5=new produs("554", "mancare_pesti", "11.12.2019", 30,20, "01.01.2022");

	ServiceShop serviceShop(repo);
	serviceShop.addShop("554", "papagal", "01.04.2020", 100, 2, 5);
	serviceShop.addShop("554", "mancare_pesti", "11.12.2019", 30, 12, "01.01.2022");
	serviceShop.addShop("555", "papagal", "03.05.2020", 60, 1, 3);

	assert(serviceShop.getSize() == 3);
	assert(serviceShop.getArticol(0) == a1);
	assert(serviceShop.getArticol(1) == a2);
	assert(serviceShop.getArticol(2) == a3);

	serviceShop.addShop("554", "papagal", "07.03.2020", 70, 3, 3);
	assert(serviceShop.getSize() == 3);
	
	
}
