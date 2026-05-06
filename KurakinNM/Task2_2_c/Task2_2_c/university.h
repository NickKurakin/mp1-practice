#ifndef _UNIVERSITY_
#define _UNIVERSITY_

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct Adres {
private:
	string city;
	string street;
	string home;

public:
	Adres();
	Adres(const string& line);
	Adres(const string& city, const string& street, const string& home);

	void print();
};

struct Special {
private:
	string universityName;
	string name;
	unsigned int contestDay;
	unsigned int contestNight;
	unsigned int contestOnline;
	float cost;

public:
	Special();
	Special(const string& universityName, const string& name, unsigned int contestDay, unsigned int contestNight, unsigned int contestOnline, float cost);

	void print();
	void fullInfoPrint();
	bool checkName(const string& name);
};

struct University {
private:
	string name;
	Adres adres;
	unsigned int numOfSpecialties;
	Special* specials;

public:
	University();
	University(const string& line);
	University(const University& universityOriginal);
	University(const University& universityOriginal, const Special& spec);

	~University();

	void copy(const University& universityOriginal);
	void print();

	bool checkName(const string& name);
	Special* checkSpecial(const string& special);
};

struct DBUniversities {
private:
	University* universities;
	int count;

public:
	DBUniversities();
	DBUniversities(const DBUniversities& DB);
	DBUniversities(const string& fileName);

	~DBUniversities();

	void allAboutUniver(const string& name);
	void allAboutSpec(const string& special);

	void print();

};

void allAboutSpec(const DBUniversities& univs, const string& special);
void minContestSpec(DBUniversities& universResult, const DBUniversities& univers, const string& special);
void findSpec(const DBUniversities& univs);

void readNumLine(unsigned int*& mass, const string& str, int n);
void readNumLine(int*& mass, const string& str, int n);
void readNumLine(float*& mass, const string& str, int n);
void strReplaceAll(string& str, const string before, const string after);

#endif