#define _CRT_SECURE_NO_WARNINGS

#include "university.h"

Adres::Adres()
{
	this->city = "";
	this->street= "";
	this->home = "";
}

Special::Special()
{
	this->name = "";
	this->contestDay = 0;
	this->contestNight = 0;
	this->contestOnline = 0;
	this->cost = 0;
}

Adres::Adres(const Adres& adres)
{
	this->city = adres.city;
	this->street = adres.street;
	this->home = adres.home;
}

University::University()
{
	this->name = "";
	this->adres = Adres();
	this->numOfSpecialties = 0;
	this->specials = nullptr;
}

void University::free()
{
	delete[] this->specials;
}

void DBUniversities::free()
{
	for (int i = 0; i < this->count; i++) {
		this->universities[i].free();
	}
	delete[] this->universities;
}

/*void CopyU(University& universityCopy, const University& universityOriginal)
{
	int i;
	universityCopy.numOfSpecialties = universityOriginal.numOfSpecialties;
	universityCopy.specialties = new string[universityOriginal.numOfSpecialties];
	universityCopy.contestDay = new unsigned int[universityOriginal.numOfSpecialties];
	universityCopy.contestNight = new unsigned int[universityOriginal.numOfSpecialties];
	universityCopy.contestOnline = new unsigned int[universityOriginal.numOfSpecialties];
	universityCopy.cost = new float[universityOriginal.numOfSpecialties];
	for (i = 0; i < universityOriginal.numOfSpecialties; i++)
	{
		universityCopy.specialties[i] = universityOriginal.specialties[i];
		universityCopy.contestDay[i] = universityOriginal.contestDay[i];
		universityCopy.contestNight[i] = universityOriginal.contestNight[i];
		universityCopy.contestOnline[i] = universityOriginal.contestOnline[i];
		universityCopy.cost[i] = universityOriginal.cost[i];
	}
	universityCopy.adres.city = universityOriginal.adres.city;
	universityCopy.adres.street = universityOriginal.adres.street;
	universityCopy.adres.home = universityOriginal.adres.home;
	universityCopy.name = universityOriginal.name;
}

void CopyUOnlyOneSpec(University& universityCopy, const University& universityOriginal, string spec)
{
	int i;
	universityCopy.numOfSpecialties = 1;
	universityCopy.specialties = new string[1];
	universityCopy.contestDay = new unsigned int[1];
	universityCopy.contestNight = new unsigned int[1];
	universityCopy.contestOnline = new unsigned int[1];
	universityCopy.cost = new float[1];
	for (i = 0; i < universityOriginal.numOfSpecialties; i++)
	{
		if (universityOriginal.specialties[i].find(spec) != string::npos)
		{
			universityCopy.specialties[0] = universityOriginal.specialties[i];
			universityCopy.contestDay[0] = universityOriginal.contestDay[i];
			universityCopy.contestNight[0] = universityOriginal.contestNight[i];
			universityCopy.contestOnline[0] = universityOriginal.contestOnline[i];
			universityCopy.cost[0] = universityOriginal.cost[i];
			break;
		}
	}
	universityCopy.adres.city = universityOriginal.adres.city;
	universityCopy.adres.street = universityOriginal.adres.street;
	universityCopy.adres.home = universityOriginal.adres.home;
	universityCopy.name = universityOriginal.name;
}*/

void readNumLine(unsigned int*& mass, const string& str, int n)
{
	std::istringstream iss(str);
	for (int i = 0; i < n; i++)
	{
		iss >> mass[i];
	}
}
void readNumLine(int*& mass, const string& str, int n)
{
	std::istringstream iss(str);
	for (int i = 0; i < n; i++)
	{
		iss >> mass[i];
	}
}
void readNumLine(float*& mass, const string& str, int n)
{
	std::istringstream iss(str);
	for (int i = 0; i < n; i++)
	{
		iss >> mass[i];
	}
}

void strReplaceAll(string& str, const string before, const string after)
{
	size_t pos = str.find(before);
	while (pos != string::npos)
	{
		str.replace(pos, before.length(), after);
		pos = str.find(before);
	}
}

Adres::Adres(const string& line)
{
	stringstream ss(line);
	getline(ss, this->city, ',');
	getline(ss, this->street, ',');
	getline(ss, this->home, ',');
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

	delete[] specialties;
	delete[] contestDay;
	delete[] contestNight;
	delete[] contestOnline;
	delete[] cost;
};

DBUniversities::DBUniversities(const string& fileName)
{
	ifstream f(fileName);
	int n = 0;
	char* num;
	string buffer, token;
	while (getline(f, buffer)) n++;
	cout << n << endl;
	this->count = n;

	f.clear();
	f.seekg(0);

	this->universities = new University[n];
	for (int i = 0; i < n; i++)
	{
		getline(f, buffer);
		strReplaceAll(buffer, " ;", ";");
		strReplaceAll(buffer, "; ", ";");
		strReplaceAll(buffer, " ,", ",");
		strReplaceAll(buffer, ", ", ",");
		this->universities[i] = University(buffer);
	}
	f.close();
}

void Adres::print()
{
	cout << "Адрес: " << this->city << ", "
		<< this->street << ", "
		<< this->home << endl;
}

void University::print()
{
		cout << "Название вуза: " << this->name << endl;
		this->adres.print();
		cout << "Специальности:" << endl;
		for (int j = 0; j < this->numOfSpecialties; j++)
		{
			cout << this->specialties[j] << endl;
			cout << "Конкурс прошлого года (Дневной/Вечерний/Заочный): " <<
				this->contestDay[j] << "/" <<
				this->contestNight[j] << "/" <<
				this->contestOnline[j] << endl;
			cout << "Оплата при договорном обучении: " << this->cost[j] << endl;
		}
		cout << endl;
}

void DBUniversities::print()
{
	for (int i = 0; i < this->count; i++)
	{
		this->universities[i].print();
	}
}

/*void output(DBUniversities& univs)
{
	for (int i = 0; i < univs.count; i++)
	{
		cout << "Название вуза: " << univs.universities[i].name << endl;
		cout << "Адрес: " << univs.universities[i].adres.city << ", "
			<< univs.universities[i].adres.street << ", "
			<< univs.universities[i].adres.home << endl;
		cout << "Специальности:" << endl;
		for (int j = 0; j < univs.universities[i].numOfSpecialties; j++)
		{
			cout << univs.universities[i].specialties[j] << endl;
			cout << "Конкурс прошлого года (Дневной/Вечерний/Заочный): " <<
				univs.universities[i].contestDay[j] << "/" <<
				univs.universities[i].contestNight[j] << "/" <<
				univs.universities[i].contestOnline[j] << endl;
			cout << "Оплата при договорном обучении: " << univs.universities[i].cost[j] << endl;
		}
		cout << endl;
	}
}*/