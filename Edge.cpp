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
void Edge::addTransportation()
{
	transportation newTransportation;
	cout << "Enter the name of the new transportation you want to add \n";
	cin >> newTransportation.Vechilename;
	cout << "Enter the price of the new transportation you want to add \n";
	cin >> newTransportation.VechilePrice;
	transportations.push_back(newTransportation);
}

void Edge::removeTransportation()
{
	string transportationName;
	cout << "Enter the Vechile you want to remove\n";
	cin >> transportationName;
	for (int i = 0; i < transportations.size(); i++)
	{
		if (transportations[i].Vechilename == transportationName)
		{
			transportations.erase(transportations.begin() + i);
		}
	}
}

void Edge::updateTransportation()
{
	string transportationName;
	float transporartionPrice;
	cout << "Enter the Vehicle you want to update\n";
	cin >> transportationName;
	for (int i = 0; i < transportations.size(); i++)
	{
		if (transportations[i].Vechilename == transportationName)
		{
			cout << "Enter the new price of the vehicle\n";
			cin >> transporartionPrice;
			transportations[i].VechilePrice = transporartionPrice;
		}
	}
}


