//#define _CRT_SECURE_NO_WARNINGS

#include "university.h"

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