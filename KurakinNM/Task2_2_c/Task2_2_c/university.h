#ifndef _UNIVERSITY_
#define _UNIVERSITY_

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct Adres {
	string city;
	string street;
	string home;

	Adres();
	Adres(const string& line);
	Adres(const Adres& adres);

	void print();
};

struct Special {
	string name;
	unsigned int contestDay;
	unsigned int contestNight;
	unsigned int contestOnline;
	float cost;
};

struct University {
	string name;
	Adres adres;
	unsigned int numOfSpecialties;
	string* specialties;
	unsigned int* contestDay;
	unsigned int* contestNight;
	unsigned int* contestOnline;
	float* cost;

	University();
	University(const string& line);
	//University(const University& universityOriginal);
	//University(const University& universityOriginal, const string& spec);
	void print();

	void free();
};

struct DBUniversities {
	University* universities;
	int count;

	DBUniversities(const string& fileName);
	void print();

	void free();
};

void read(string fileName, DBUniversities& universities);
//void output(DBUniversities& univs);

void allAboutUniver(const DBUniversities& univs, const string& name);
void allAboutSpec(const DBUniversities& univs, const string& special);
void minContestSpec(DBUniversities& universResult, const DBUniversities& univers, const string& special);
void findSpec(const DBUniversities& univs);

void CopyU(University& universityCopy, const University& universityOriginal);
void CopyUOnlyOneSpec(University& universityCopy, const University& universityOriginal, const string& spec);

#endif