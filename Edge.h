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
 
	//string source;
	//string destination;
	
	//vector<transportation> t;

public:
	Edge();
	void addtation(vector<transportation>);
	void removetation(vector<transportation>);
	void updatetationPrice(vector<transportation>);



};

