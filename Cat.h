#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include "Animals.h"

using namespace std;

class Cat : public Animals
{
public:

	Cat();
	Cat(ifstream& file);

	void setSpecies();
	void setColor();
	void setOwnerName();
	void setCatName();
	
	void print();
	void edit();
	void write(ofstream& file) const;

	static string* speciesMass;
	static int speciesMassSize;

private:

	string species;
	string color;
	string ownerName;
	string catName;
	string className = "Кошка";
};

