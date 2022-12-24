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
		cout << "Выберите породу или введите свою" << endl;
		for (size_t i = 0; i < speciesMassSize; i++)
		{
			cout << i + 1 << ". " << speciesMass[i] << endl ;
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

void Bird::setColor() {
	cout << "Окрас: ";
	getline(cin, color);
}

void Bird::setFoodType() {
	cout << "Тип питания: ";
	getline(cin, foodType);
}

void Bird::setHabitat() {
	cout << "Среда обитания: ";
	getline(cin, habitat);
}

void Bird::edit() {

	int def;
	cout << endl << endl << "Введите:" << endl <<"1-4. Номер поля для редактирования" << endl << "5. Весь объект" << endl << "0. Выход" << endl << "Ввод:";
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
	cout << "Класс: " << className << endl;
	cout << "1.Порода: " << species << endl;
	cout << "2.Окрас: " << color << endl;
	cout << "3.Тип питания: " << foodType << endl;
	cout << "4.Среда обитания: " << foodType << endl;
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