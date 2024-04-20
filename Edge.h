#pragma once
#include <string>
#include<vector>
using namespace std;


struct transportation
{
	string Vechilename;
	float VechilePrice;


};

class Edge
{
public:

	vector<transportation> transportations;

public:
	Edge();
	void addTransportation();
	void removeTransportation();
	void updateTransportation();



};

