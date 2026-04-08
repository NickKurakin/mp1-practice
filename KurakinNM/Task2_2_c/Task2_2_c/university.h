#ifndef _UNIVERSITY_
#define _UNIVERSITY_

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

typedef struct {
	string city;
	string street;
	string home;
} Adres;

typedef struct {
	string name;
	Adres adres;
	unsigned int numOfSpecialties;
	string* specialties;
	unsigned int* contestDay;
	unsigned int* contestNight;
	unsigned int* contestOnline;
	float* cost; // float
} University;

typedef struct {
	University* universities;
	int count;
} DBUniversities;

void freeDBU(DBUniversities* DB);

void read(string fileName, DBUniversities& universities); // DBUniversities*
void output(DBUniversities& univs); // DBUniversities*

void allAboutUniver(DBUniversities* univs, char* name); // DBUniversities*
void allAboutSpec(DBUniversities* univs, char* special); // DBUniversities*
void minContestSpec(DBUniversities* universResult, DBUniversities* univers, char* special); // DBUniversities* //возвращать найденные
void findSpec(DBUniversities* univs); // DBUniversities* // поиск минимального конкурса по какой-либо специальности любого вуза

void cpy(char** output, const char* input);
void CopyU(University* universityCopy, const University* universityOriginal);
void CopyUOnlyOneSpec(University* universityCopy, const University* universityOriginal, char* spec);

#endif