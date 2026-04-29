#include "university.h"

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

void DBUniversities::free()
{
	for (int i = 0; i < this->count; i++) {
		this->universities[i].free();
	}
	delete[] this->universities;
}

void DBUniversities::print()
{
	for (int i = 0; i < this->count; i++)
	{
		this->universities[i].print();
	}
}