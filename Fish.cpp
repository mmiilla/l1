#include "Fish.h"
#include <conio.h>

string* Fish::speciesMass = {};
int Fish::speciesMassSize = 0;

Fish::Fish() {
	setSpecies();
	setColor();
	setFoodType();
}

void Fish::setSpecies() {
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

void Fish::setColor() {
	cout << "Окрас: ";
	getline(cin, color);
}

void Fish::setFoodType() {
	cout << "Тип питания: ";
	getline(cin, foodType);
}

void Fish::edit() {
	
		int def;
		cout << endl << endl << "Введите:" << endl << "1-3. Номер поля для редактирования" << endl << "4. Весь объект" << endl << "0. Выход" << endl << "Ввод:";
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
			setFoodType();
			break;
		case 4:
			setSpecies();
			setColor();
			setFoodType();
			break;
		case 0:
			break;
		default:
			break;
		}
}

void Fish::print() {
	cout << "Класс: " << className << endl;
	cout << "Порода: " << species << endl;
	cout << "Окрас: " << color << endl;
	cout << "Тип питания: " << foodType << endl;
}

void Fish::write(ofstream& file) const {
	file << className << endl;
	file << species << endl;
	file << color << endl;
	file << foodType << endl;
}

Fish::Fish(ifstream& file) {
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
}