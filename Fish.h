#pragma once
#include "Animals.h"
#include <iostream>
#include <string>

using namespace std;

class Fish : public Animals
{
public:
	
	
	Fish();
	Fish(ifstream& file);

	void setSpecies();
	void setColor();
	void setFoodType();

	void print();
	void edit();
	void write(ofstream& file) const;

	static string* speciesMass;
	static int speciesMassSize;

private:

	string species;
	string color;
	string foodType;
	string className = "аћср";
};

