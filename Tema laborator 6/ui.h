#pragma once
#include "service.h"

class ui {
private:
	serviceT serv;
	void addElem();
	void deleteElem();
	void updateElem();
	void showAll();
public:
	ui();
	ui(serviceT&);
	void showui();
	~ui();
};