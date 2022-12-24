#pragma once
#include "Animals.h"
#include <iostream>
#include <string>

using namespace std;

class Bird : public Animals
{
public:

	Bird();
	Bird(ifstream& file);

	void setSpecies();
	void setColor();
	void setFoodType();
	void setHabitat();

	void print();
	void edit();
	void write(ofstream& file) const;

	static string* speciesMass;
	static int speciesMassSize;
	
private:

	string species;
	string color;
	string foodType;
	string habitat;
	string className = "ѕтица";;
	
};

