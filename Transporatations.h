#pragma once
#include <string>
#include<vector>
using namespace std;


struct transportation
{
	string Vechilename;
	float VechilePrice;


};

class Transporatations
{
public:

	vector<transportation> transportations;

public:
	void Menu();
	void addTransportation();
	void removeTransportation();
	void updateTransportation();



};

