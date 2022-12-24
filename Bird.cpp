#include "Bird.h"
#include <conio.h>
#include <windows.h>

string* Bird::speciesMass = {};
int Bird::speciesMassSize = 0;

Bird::Bird() {
	setSpecies();
	setColor();
	setFoodType();
	setHabitat();	
}

void Bird::setSpecies() {

	if (speciesMassSize > 0)
	{
		cout << "�������� ������ ��� ������� ����" << endl;
		for (size_t i = 0; i < speciesMassSize; i++)
		{
			cout << i + 1 << ". " << speciesMass[i] << endl ;
		}
		cout << "0. ���� ������" << endl << "����: ";

		int command;
			cin >> command;
			cin.ignore();
			if (command == 0)
			{
				cout << "������: ";
				string s;
				getline(cin, s);
				species = s;

				system("@cls||clear");
				cout << "������: " << species << endl;

				string* newSpMass = new string[speciesMassSize + 1];
				for (size_t i = 0; i < speciesMassSize; i++)
				{
					newSpMass[i] = speciesMass[i];
				}
				newSpMass[speciesMassSize++] = s;
				delete[] speciesMass;
				speciesMass = newSpMass;
				return;
			}
			else
			{
				species = speciesMass[command - 1];

				system("@cls||clear");
				cout << "������: " << species << endl;

				return;
			}
	}
	else
	{
		speciesMassSize++;
		cout << "������:";
		string s;
		getline(cin, s);
		species = s;
		string* newSpMass = new string[1];
		newSpMass[0] = s;
		speciesMass = newSpMass;
		return;
	}
}

void Bird::setColor() {
	cout << "�����: ";
	getline(cin, color);
}

void Bird::setFoodType() {
	cout << "��� �������: ";
	getline(cin, foodType);
}

void Bird::setHabitat() {
	cout << "����� ��������: ";
	getline(cin, habitat);
}

void Bird::edit() {

	int def;
	cout << endl << endl << "�������:" << endl <<"1-4. ����� ���� ��� ��������������" << endl << "5. ���� ������" << endl << "0. �����" << endl << "����:";
	cin >> def;
	cin.ignore();
	/*string s;
	getline(cin, s);*/

		switch (def)
		{
		case 1:
			setSpecies();
			break;
		case 2:
			setColor();
			break;
		case 3:
			setFoodType();
			break;
		case 4:
			setHabitat();
			break;
		case 5:
			setSpecies();
			setColor();
			setFoodType();
			setHabitat();;
			break;
		case 0:
			break;
		default:
			break;
		}	
}

void Bird::print() {
	cout << "�����: " << className << endl;
	cout << "1.������: " << species << endl;
	cout << "2.�����: " << color << endl;
	cout << "3.��� �������: " << foodType << endl;
	cout << "4.����� ��������: " << foodType << endl;
}

void Bird::write(ofstream& file) const {
	file << className << endl;
	file << species << endl;
	file << color << endl;
	file << foodType << endl;
	file << habitat << endl;
}

Bird::Bird(ifstream& file) {
	int definitionsSize = 4;
	string* definitions = new string[definitionsSize];

	for (int i = 0; i < definitionsSize; i++) {
		string def;
		getline(file, def);
		definitions[i] = def;
	}

	species = definitions[0];
	color = definitions[1];
	foodType = definitions[2];
	habitat = definitions[3];
}