#include "Cat.h"
#include <conio.h>

string* Cat::speciesMass = {};
int Cat::speciesMassSize = 0;

Cat::Cat() {
	setSpecies();
	setColor();
	setOwnerName();
	setCatName();
}

void Cat::setSpecies() {
	if (speciesMassSize > 0)
	{
		cout << "Выберите породу или введите свою" << endl;
		for (size_t i = 0; i < speciesMassSize; i++)
		{
			cout << i + 1 << ". " << speciesMass[i] << endl;
		}
		cout << "0. Своя порода" << endl << "Ввод: ";

		int command;
		cin >> command;
		cin.ignore();
		if (command == 0)
		{
			cout << "Порода: ";
			string s;
			getline(cin, s);
			species = s;

			system("@cls||clear");
			cout << "Порода: " << species << endl;

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
			cout << "Порода: " << species << endl;

			return;
		}
	}
	else
	{
		speciesMassSize++;
		cout << "Порода:";
		string s;
		getline(cin, s);
		species = s;
		string* newSpMass = new string[1];
		newSpMass[0] = s;
		speciesMass = newSpMass;
		return;
	}
}

void Cat::setColor() {
	cout << "Окрас: ";
	getline(cin, color);
}


void Cat::setOwnerName() {
	cout << "Имя владельца: ";
	getline(cin, ownerName);
}

void Cat::setCatName() {
	cout << "Кличка: ";
	getline(cin, catName);
}

void Cat::edit() {

		int def;
		cout << endl << endl << "Введите:" << endl << "1-4. Номер поля для редактирования" << endl << "5. Весь объект" << endl << "0. Выход" << endl << "Ввод:";
		cin >> def;
		string s;
		getline(cin, s);

		switch (def)
		{
		case 1:
			setSpecies();
			break;
		case 2:
			setColor();
			break;
		case 3:
			setOwnerName();
			break;
		case 4:
			setCatName();
			break;
		case 5:
			setSpecies();
			setColor();
			setOwnerName();
			setCatName();
			break;
		case 0:
			break;
		default:
			break;
		}
}

void Cat::print() {
	cout << "Класс: " << className << endl;
	cout << "Порода: " << species << endl;
	cout << "Окрас: " << color << endl;
	cout << "Имя владельца: " << ownerName << endl;
	cout << "Кличка: " << catName << endl;
}

void Cat::write(ofstream& file) const {
	file << className << endl;
	file << species << endl;
	file << color << endl;
	file << ownerName << endl;
	file << catName << endl;
}

Cat::Cat(ifstream& file) {
	int definitionsSize = 4;
	string* definitions = new string[definitionsSize];

	for (int i = 0; i < definitionsSize; i++) {
		string def;
		getline(file, def);
		definitions[i] = def;
	}

	species = definitions[0];
	color = definitions[1];
	ownerName = definitions[2];
	catName = definitions[3];
}