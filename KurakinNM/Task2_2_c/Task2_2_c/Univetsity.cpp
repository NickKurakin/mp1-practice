#include "university.h"

University::University()
{
	this->name = "";
	this->adres = Adres();
	this->numOfSpecialties = 0;
	this->specials = nullptr;
}

University::University(const University& universityOriginal)
{
	this->name = universityOriginal.name;
	this->adres = Adres(universityOriginal.adres);
	this->numOfSpecialties = universityOriginal.numOfSpecialties;
	this->specials = new Special[this->numOfSpecialties];
	for (int i = 0; i < this->numOfSpecialties; i++)
	{
		this->specials[i] = Special(universityOriginal.specials[i]);
	}
}

University::University(const University& universityOriginal, const Special& spec)
{
	this->name = universityOriginal.name;
	this->adres = Adres(universityOriginal.adres);
	this->numOfSpecialties = 1;
	this->specials = new Special[1];
	this->specials[0] = Special(spec);
}

University::University(const string& line)
{
	this->numOfSpecialties = (count(line.begin(), line.end(), ',') - 2) / 5 + 1;
	this->specials = new Special[this->numOfSpecialties];

	string token;
	string* specialties = new string[this->numOfSpecialties];
	unsigned int* contestDay = new unsigned int[this->numOfSpecialties];
	unsigned int* contestNight = new unsigned int[this->numOfSpecialties];
	unsigned int* contestOnline = new unsigned int[this->numOfSpecialties];
	float* cost = new float[this->numOfSpecialties];

	stringstream ss(line);
	getline(ss, this->name, ';');
	getline(ss, token, ';');
	this->adres = Adres(token);

	getline(ss, token, ';');
	stringstream ss2(token);
	for (int j = 0; j < this->numOfSpecialties; j++)
	{
		getline(ss2, specialties[j], ',');
	}
	getline(ss, token, ';');
	strReplaceAll(token, ",", " ");
	readNumLine(contestDay, token, this->numOfSpecialties);
	getline(ss, token, ';');
	strReplaceAll(token, ",", " ");
	readNumLine(contestNight, token, this->numOfSpecialties);
	getline(ss, token, ';');
	strReplaceAll(token, ",", " ");
	readNumLine(contestOnline, token, this->numOfSpecialties);
	getline(ss, token, ';');
	strReplaceAll(token, ",", " ");
	readNumLine(cost, token, this->numOfSpecialties);

	for (int i = 0; i < this->numOfSpecialties; i++)
	{
		this->specials[i] = Special(specialties[i], contestDay[i], contestNight[i], contestOnline[i], cost[i]);
	}

	delete[] specialties;
	delete[] contestDay;
	delete[] contestNight;
	delete[] contestOnline;
	delete[] cost;
};

University::~University()
{
	delete[] this->specials;
}

void University::print()
{
	cout << "Название вуза: " << this->name << endl;
	this->adres.print();
	cout << "Специальности:" << endl;
	for (int i = 0; i < this->numOfSpecialties; i++)
	{
		this->specials[i].print();
	}
	cout << endl;
}

void University::copy(const University& universityOriginal)
{
	if (this->numOfSpecialties > 0) delete[] this->specials;

	this->name = universityOriginal.name;
	this->adres = Adres(universityOriginal.adres);
	this->numOfSpecialties = universityOriginal.numOfSpecialties;
	this->specials = new Special[this->numOfSpecialties];
	for (int i = 0; i < this->numOfSpecialties; i++)
	{
		this->specials[i] = Special(universityOriginal.specials[i]);
	}
}

bool University::checkName(const string& name)
{
	return this->name.find(name) != string::npos;
}