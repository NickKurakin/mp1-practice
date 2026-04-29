//#define _CRT_SECURE_NO_WARNINGS

#include "university.h"

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