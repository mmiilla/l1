#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <conio.h>

#include "Animals.h"
#include "Fish.h"
#include "Cat.h"
#include "Bird.h"

using namespace std;

class Keeper
{
public:

	Keeper();

	void add(Animals* el);

	void remove(int num);

	void save();

	void load();

	void print();

	bool isEmpty();

	Animals** getList();

	int getSize();

	~Keeper();

	Animals** Zoo = {};
	int ZooSize = 0;
	string fileName = "Zoo.txt";

private:
	
};

