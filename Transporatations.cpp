#include "Transporatations.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;


void Transporatations::Menu()
{
	int choice;
	cout << "What procedure you want to do?\n";
	cout << "1-Update Transportation\n 2-Add Transportation\n 3-Remove Transportation\n Your Choice:";
	cin >> choice;

	switch (choice)
	{
	case 1:
		updateTransportation(); 
		break;
	case 2:
		addTransportation();
		break;
	case 3:
		removeTransportation();
		break;
	default:
		break;
	}
}

void Transporatations::addTransportation()
{
	bool flag = false;
	transportation newTransportation;
	string nameCheck;
	cout << "Enter the name of the new transportation you want to add \n";
	cin >> nameCheck;
	if (transportations.empty()) {
		newTransportation.Vechilename = nameCheck;
		cout << "Enter the price of the new transportation you want to add \n";
		cin >> newTransportation.VechilePrice;
		transportations.push_back(newTransportation);


	}
	else {
		newTransportation.Vechilename = nameCheck;
		for (int i = 0; i < transportations.size(); i++)
		{
			if (transportations[i].Vechilename == nameCheck)
			{
				cout << "This already exist!\nEnter a new one";
				addTransportation();
				flag = true;
			}
		}
		if (!flag) {
			newTransportation.Vechilename = nameCheck;
			cout << "Enter the price of the new transportation you want to add \n";
			cin >> newTransportation.VechilePrice;
			transportations.push_back(newTransportation);
		}
	}
}

void Transporatations::removeTransportation()
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

void Transporatations::updateTransportation()
{
	string transportationName;
	float transporartionPrice;
	cout << "Enter the Vehicle you want to update\n";
	cin >> transportationName;
	for (int i = 0; i < transportations.size(); i++)
	{
		if (transportations[i].Vechilename == transportationName)
		{
			int choice;
			cout << "What procedure you want to do?\n";
			cout << "1-Change Name\n 2-Change Price";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter the new name";
				cin >> transportations[i].Vechilename;
				break;
			case 2:
				cout << "Enter the new price";
				cin >> transportations[i].VechilePrice;
				break;
			default:
				break;
			}
		}
	}
}


