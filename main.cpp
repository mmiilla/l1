#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "Keeper.h"
#include "Bird.h"
#include "Fish.h"
#include "Cat.h"

using namespace std;

Keeper keeper;

void add()
{
	system("@cls||clear");

	cout << "1. Добавить кошку" << endl;
	cout << "2. Добавить рыбу" << endl;
	cout << "3. Добавить птицу" << endl;

	cout << "Номер команды:";
	int command;
	cin >> command;
	cin.ignore();

	system("@cls||clear");

	switch (command)
	{
	case 1:
		keeper.add(new Cat());
		return;
	case 2:
		keeper.add(new Fish());
		return;
	case 3:
		keeper.add(new Bird());
		return;
	}
}


void edit() {
	if (keeper.isEmpty()) return;

	while (true) {
		system("@cls||clear");

		for (int i = 0; i < keeper.ZooSize; i++) {
			cout << "Номер: " << (i + 1) << endl;
			keeper.Zoo[i]->print();
			cout << endl;
		}

		int num;

		cout <<  "Введите номер объекта: ";
		cin >> num;
		cin.ignore();

		if (num < 1 || num > keeper.ZooSize) {
			cout << endl << "Такого объекта нет" << endl;

			cout << endl << "Нажмите любую клавишу";
			_getch();

			continue;
		};

		system("@cls||clear");
		keeper.Zoo[num - 1]->print();
		keeper.Zoo[num - 1]->edit();
		return;
	}
}

void del() {
	if (keeper.isEmpty()) return;

	while (true) {
		system("@cls||clear");

		for (int i = 0; i < keeper.ZooSize; i++) {
			cout << "Номер: " << (i + 1) << endl;
			keeper.Zoo[i]->print();
			cout << endl;
		}

		int num;

		cout << "Введите номер объекта: ";
		cin >> num;
		cin.ignore();

		if (num < 1 || num > keeper.ZooSize) {
			cout << endl << "Такого объекта нет" << endl;

			cout << endl << "Нажмите любую клавишу";
			_getch();

			continue;
		};

		system("@cls||clear");
		keeper.remove(num-1);
		return;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {

		cout << "1. Открыть список объектов" << endl;
		cout << "2. Добавить объект" << endl;
		cout << "3. Редактировать объект" << endl;
		cout << "4. Удалить объект" << endl;
		cout << "5. Удалить все объекты" << endl;
		cout << "6. Сохранить" << endl;
		cout << "7. Загрузить" << endl;
		cout << "ESC. Выход" << endl;
		
		cout << "Номер команды:";
		int command;
		cin >> command;

		system("@cls||clear");

		switch (command)
		{
		case 1:
			keeper.print();
			break;
		case 2:
			add();
			break;
		case 3:
			edit();
			break;
		case 4:
			del();
			break;
		case 5:
			keeper.~Keeper();
			break;
		case 6:
			keeper.save();
			break;
		case 7:
			keeper.load();
			break;
		case 27:
			exit(0);
		default:
			break;
		}
		system("@cls||clear");
	}

}

