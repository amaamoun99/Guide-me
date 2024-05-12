#include "Transporatations.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;


void Transporatations::Menu()
{
	int choice;
	bool flag = true;
	system("cls");
	int consoleWidth = 120;
	int padding = (consoleWidth - 25) / 2;
	while (flag)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << string(padding, ' ') << "\t\t\tUpdate Edge\n"
			<< string(padding, ' ') << "-------------------------------------\n";


		cout << string(padding, ' ') << "1-Update Transportation\n"
			<< string(padding, ' ') << "2-Add Transportation\n"
			<< string(padding, ' ') << "3-Remove Transportation\n"
			<< string(padding, ' ') << "4-Go Back\n"
			<< string(padding, ' ') << "Choice:";
		cin >> choice;
		system("pause");

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
		case 4:
			flag = false;
			break;
		default:
			cout << string(padding, ' ') << "Enter a valid number!\n";
			system("pause");
		}

	}
	
}

void Transporatations::addTransportation()
{
	system("cls");
	bool flag = false;
	transportation newTransportation;
	string nameCheck;
	int consoleWidth = 120;
	int padding = (consoleWidth - 25) / 2;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << string(padding, ' ') << "\t\tAdd Transportation\n"
		<< string(padding, ' ') << "-------------------------------------\n";

	cout << string(padding, ' ') << "Enter the name of the new transportation: ";
	cin >> nameCheck;
	if (transportations.empty()) {
		newTransportation.Vechilename = nameCheck;
		cout << string(padding, ' ') << "Enter the price of the new transportation: ";
		cin >> newTransportation.VechilePrice;
		transportations.push_back(newTransportation);

		cout << "\n\n";
		cout << string(padding, ' ') << "Added Successfully!\n";
		system("pause");


	}
	else {
		for (int i = 0; i < transportations.size(); i++)
		{
			if (transportations[i].Vechilename == nameCheck)
			{
				cout << string(padding, ' ') << "This already exist,Enter a new one!";
				addTransportation();
				flag = true;
			}
		}
		if (!flag) {
			newTransportation.Vechilename = nameCheck;
			cout<< string(padding, ' ') << "Enter the price of the new transportation: ";
			cin >> newTransportation.VechilePrice;
			transportations.push_back(newTransportation);
			cout << "\n\n";
			cout << string(padding, ' ') << "Added Successfully!\n";
			system("pause");
		}
	}
}

void Transporatations::removeTransportation()
{
	int consoleWidth = 120;
	int padding = (consoleWidth - 25) / 2;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << string(padding, ' ') << "\t\t Remove Transportation\n"
		<< string(padding, ' ') << "-------------------------------------\n";
	for (int i = 0; i < transportations.size(); i++)
	{
		cout << string(padding, ' ') << i + 1 << "-" << transportations[i].Vechilename;
	}
	string transportationName;
	cout << string(padding, ' ') << "-------------------------------------\n";
	cout << string(padding, ' ') << "Enter the Vechile you want to remove: ";
	cin >> transportationName;
	for (int i = 0; i < transportations.size(); i++)
	{
		if (transportations[i].Vechilename == transportationName)
		{
			transportations.erase(transportations.begin() + i);
		}
	}
	cout << "\n\n";
	cout << string(padding, ' ') << "Deleted Successfully!\n";
	system("pause");
}

void Transporatations::updateTransportation()
{
	system("cls");
	bool flag = true;
	int consoleWidth = 120;
	int padding = (consoleWidth - 25) / 2;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << string(padding, ' ') << "\t\tUpdate Transportation\n"
		<< string(padding, ' ') << "-------------------------------------\n";
	string transportationName;
	float transporartionPrice;
	for (int i = 0; i < transportations.size(); i++)
	{
		cout << string(padding, ' ') << i+1 << "-" << transportations[i].Vechilename << endl;
	}
	cout << string(padding, ' ') << "Enter the Vehicle you want to update:";
	cin >> transportationName;
	for (int i = 0; i < transportations.size(); i++)
	{
		if (transportations[i].Vechilename == transportationName)
		{
			while (flag)
			{
				system("cls");
				int choice;
				cout << "\n\n\n\n\n\n\n\n\n\n";
				cout << string(padding, ' ') << "\t\tUpdate Transportation\n"
					<< string(padding, ' ') << "-------------------------------------\n";
				cout << string(padding, ' ') << "What procedure you want to do?\n";
				cout << string(padding, ' ') << "1- Change Name\n"
					<< string(padding, ' ') << "2- Change Price\n"
					<< string(padding, ' ') << "3- Exit\n"
					<< string(padding, ' ') << "Choice:";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << string(padding, ' ') << "-------------------------------------\n";
					cout << string(padding, ' ') << "Enter the new name";
					cin >> transportations[i].Vechilename;
					cout << "\n\n";
					cout << string(padding, ' ') << "Updated Successfully!\n";
					system("pause");
					break;
				case 2:
					cout << string(padding, ' ') << "-------------------------------------\n";
					cout << string(padding, ' ') << "Enter the new price";
					cin >> transportations[i].VechilePrice;
					cout << "\n\n";
					cout << string(padding, ' ') << "Updated Successfully!\n";
					system("pause");
					break;
				case 3:
					flag = false;
					break;
				default:
					break;
				}
			}
			
		}
	}
}


