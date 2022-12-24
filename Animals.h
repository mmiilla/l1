#pragma once

#include <fstream>
#include <string>

using namespace std;

class Animals
{
public: 

	virtual void write(ofstream& file) const = 0;
	virtual void print() = 0;
	virtual void edit() = 0;

	friend ofstream& operator<< (ofstream& file, const Animals& object) {
		object.write(file);
		return file;
	}

private:
};

