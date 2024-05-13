#pragma once
#include <string>
#include<vector>
#include<list>
using namespace std;


struct transportation
{
	string Vechilename;
	float VechilePrice;


};

class Transporatations
{
public:

	list<transportation> transportations;

public:
	void Menu();
	void addTransportation();
	void removeTransportation();
	void updateTransportation();



};

