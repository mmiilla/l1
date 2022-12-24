#include "Keeper.h"
#include <exception>

Keeper::Keeper()
{}

Animals** Keeper::getList()
{
	return this->Zoo;
}

int Keeper::getSize()
{
	return this->ZooSize;
}

Keeper::~Keeper() 
{
	delete[] Zoo;
	ZooSize = 0;
}

void Keeper::add(Animals* el) {
	Animals** newMass = new Animals * [ZooSize + 1];

	for (int i = 0; i < ZooSize; i++) {
		newMass[i] = Zoo[i];
	}

	newMass[ZooSize++] = el;
	delete[] Zoo;
	Zoo = newMass;
}

void Keeper::remove(int num) {
	Animals** newMass = new Animals * [ZooSize - 1];

	int k = 0;
	for (int i = 0; i < ZooSize; i++) {
		if (i != num)
		{
			newMass[k] = Zoo[k];
			k++;
		}
	}

	delete[] Zoo;
	Zoo = newMass;
	ZooSize--;
}

void Keeper::save() {
	ofstream zoo;

	zoo.open(fileName);
	try
	{
		if (!zoo.is_open()) 
		throw exception("�� ������� ������� ����.");
		
		zoo << ZooSize << endl;
		for (size_t i = 0; i < ZooSize; i++) 
		{
			zoo << *Zoo[i];
			zoo << endl;
		}
		cout << "���������!";
		zoo.close();

		cout << endl << "������� ����� �������";
		_getch();
	}
	catch (const exception& err)
	{
		cout << err.what() << endl;
	}
	catch (...)
	{
		cout << "����������� ������!";
	}
}

void Keeper::load() {

	ifstream zoo(fileName);
	string line;

	try
	{
		if (!zoo.is_open()) 
		throw exception("�� ������� ������� ����.");

		getline(zoo, line);
		int zooCnt = stoi(line); 

		if (zooCnt <= 0) 
		throw exception("���� ���� ��� ���������");

		int i = 0;
		Animals** newMass = new Animals * [zooCnt];

		while (getline(zoo, line))
		{

			if (string ("�����") == line) {
				newMass[i++] = new Cat(zoo);
			}
			else if (string("�����") == line) {
				newMass[i++] = new Bird(zoo);
			}
			else if (string("����") == line) {
				newMass[i++] = new Fish(zoo);
			}
			else
			{
			throw exception("����������� ��� ������");
			}
		}

		delete[]Zoo;
		Zoo = newMass;
		ZooSize = zooCnt;

		cout << "��������(�) " << ZooSize << " ������(��)";
	}
	catch (const exception& err)
	{
		cout << err.what() << endl;
	}
	catch (...)
	{
		cout << "����������� ������!";
	}

	zoo.close();

	cout << endl << "������� ����� �������";
	_getch();
}

void Keeper::print()
{
	if (isEmpty()) return;

	for (int i = 0; i < ZooSize; i++) {
		Zoo[i]->print();
		cout << endl;
	}

	cout << endl << "������� ����� �������" << endl;
	_getch();
}

bool Keeper::isEmpty()
{
	if (ZooSize > 0) 
	{
		return false;
	}
	else
	{
		cout << "�����" << endl << "������� ����� �������";
		_getch();
		return true;
	}
}

