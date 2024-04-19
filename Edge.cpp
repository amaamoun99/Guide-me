#include "Edge.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

Edge::Edge()
{
	//destination = this->destination;
	//source = this->source;


}
void Edge::addtation(vector<transportation> t)
{
	transportation addedtation;
	cout << "Enter the name of the new tation you want to add \n";
	cin >> addedtation.Vechilename;
	cout << "Enter the price of the new tation you want to add \n";
	cin >> addedtation.VechilePrice;

	t.push_back(addedtation);
}

void Edge::removetation(vector<transportation> t)
{
	string tationName;
	cout << "Enter the Vechile you want to remove\n";
	cin >> tationName;
	for (int i = 0; i <t.size(); i++)
	{
		if (t[i].Vechilename == tationName)
		{
			t.erase(t.begin() +i);
		}
	}
}

void Edge::updatetationPrice(vector<transportation> t)
{
	string tationName;
	float TransporartionPrice;
	cout << "Enter the Vehicle you want to remove\n";
	cin >> tationName;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].Vechilename == tationName)
		{
			cout << "Enter the new price of the vehicle\n";
			cin >> TransporartionPrice;
			t[i].VechilePrice = TransporartionPrice;
		}
	}
}


