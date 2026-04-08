#define _CRT_SECURE_NO_WARNINGS

#include "university.h"

void freeDBU(DBUniversities* DB)
{
	for (int i = 0; i < DB->count; i++) {
		delete[] DB->universities[i].specialties;
		delete[] DB->universities[i].contestDay;
		delete[] DB->universities[i].contestNight;
		delete[] DB->universities[i].contestOnline;
		delete[] DB->universities[i].cost;
	}
	delete[] DB->universities;
}

void cpy(char** output, const char* input)
{
	int len = strlen(input);
	(*output) = (char*)malloc(len + 1);
	strncpy(*output, input, len + 1);
}

/*void CopyU(University* universityCopy, const University* universityOriginal)
{
	int i;
	universityCopy->numOfSpecialties = universityOriginal->numOfSpecialties;
	universityCopy->specialties = (char**)malloc(universityOriginal->numOfSpecialties * sizeof(char*));
	universityCopy->contestDay = (unsigned int*)malloc(universityOriginal->numOfSpecialties * sizeof(unsigned int));
	universityCopy->contestNight = (unsigned int*)malloc(universityOriginal->numOfSpecialties * sizeof(unsigned int));
	universityCopy->contestOnline = (unsigned int*)malloc(universityOriginal->numOfSpecialties * sizeof(unsigned int));
	universityCopy->cost = (unsigned int*)malloc(universityOriginal->numOfSpecialties * sizeof(unsigned int));
	for (i = 0; i < universityOriginal->numOfSpecialties; i++)
	{
		cpy(&(universityCopy->specialties[i]), universityOriginal->specialties[i]);
		universityCopy->contestDay[i] = universityOriginal->contestDay[i];
		universityCopy->contestNight[i] = universityOriginal->contestNight[i];
		universityCopy->contestOnline[i] = universityOriginal->contestOnline[i];
		universityCopy->cost[i] = universityOriginal->cost[i];
	}
	cpy(&(universityCopy->adres.city), universityOriginal->adres.city);
	cpy(&(universityCopy->adres.street), universityOriginal->adres.street);
	cpy(&(universityCopy->adres.home), universityOriginal->adres.home);
	cpy(&(universityCopy->name), universityOriginal->name);
}*/

/*void CopyUOnlyOneSpec(University* universityCopy, const University*  universityOriginal, char* spec)
{
	int i;
	universityCopy->numOfSpecialties = 1;
	universityCopy->specialties = (char**)malloc(sizeof(char*));
	universityCopy->contestDay = (unsigned int*)malloc(sizeof(unsigned int));
	universityCopy->contestNight = (unsigned int*)malloc(sizeof(unsigned int));
	universityCopy->contestOnline = (unsigned int*)malloc(sizeof(unsigned int));
	universityCopy->cost = (unsigned int*)malloc(sizeof(unsigned int));
	for (i = 0; i < universityOriginal->numOfSpecialties; i++)
	{
		if (strstr(universityOriginal->specialties[i], spec)) {
			cpy(&(universityCopy->specialties[0]), universityOriginal->specialties[i]);
			universityCopy->contestDay[0] = universityOriginal->contestDay[i];
			universityCopy->contestNight[0] = universityOriginal->contestNight[i];
			universityCopy->contestOnline[0] = universityOriginal->contestOnline[i];
			universityCopy->cost[0] = universityOriginal->cost[i];
			break;
		}
	}
	cpy(&(universityCopy->adres.city), universityOriginal->adres.city);
	cpy(&(universityCopy->adres.street), universityOriginal->adres.street);
	cpy(&(universityCopy->adres.home), universityOriginal->adres.home);
	cpy(&(universityCopy->name), universityOriginal->name);
}*/

void bariers(char* str, int* start, int* numOfSims)
{
	while (str[*start] == ' ') (*start)++;
	while (str[*numOfSims - 1] == ' ') (*numOfSims)--;
	*numOfSims -= *start;
}

void readWord(char* input, char** output)
{
	int start = 0, numOfSims = strlen(input);
	bariers(input, &start, &numOfSims);
	(*output) = (char*)malloc(numOfSims + 1);
	strncpy(*output, input + start, numOfSims);
	(*output)[numOfSims] = '\0';
}
void readNumLine(char** input, unsigned int* outNums, int len)
{
	int i;
	char* num;
	for (i = 0; i < len; i++)
	{
		readWord(*input, &num);
		outNums[i] = atoi(num);
		*input = strtok(NULL, ",;");
		free(num);
	}
}

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

void readFloatLine(char** input, float* outNums, int len)
{
	int i;
	char* num;
	for (i = 0; i < len; i++)
	{
		readWord(*input, &num);
		outNums[i] = atof(num);
		*input = strtok(NULL, ",;");
		free(num);
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

void read(string fileName, DBUniversities& DBunivers)
{
	ifstream f(fileName);
	int n = 0;
	char* num;
	string buffer, token;
	while (getline(f, buffer)) n++;
	cout << n << endl;
	DBunivers.count = n;

	f.seekg(0);

	DBunivers.universities = new University[n];
	for (int i = 0; i < n; i++)
	{
		getline(f, buffer);
		DBunivers.universities[i].numOfSpecialties = (count(buffer.begin(), buffer.end(), ',') - 2) / 5 + 1;
		DBunivers.universities[i].specialties = new string[DBunivers.universities[i].numOfSpecialties];
		DBunivers.universities[i].contestDay = new unsigned int[DBunivers.universities[i].numOfSpecialties];
		DBunivers.universities[i].contestNight = new unsigned int[DBunivers.universities[i].numOfSpecialties];
		DBunivers.universities[i].contestOnline = new unsigned int[DBunivers.universities[i].numOfSpecialties];
		DBunivers.universities[i].cost = new float[DBunivers.universities[i].numOfSpecialties];
	}


	f.seekg(0);
	for (int i = 0; i < n; i++)
	{
		getline(f, buffer);
		strReplaceAll(buffer, " ;", ";");
		strReplaceAll(buffer, "; ", ";");
		strReplaceAll(buffer, " ,", ",");
		strReplaceAll(buffer, ", ", ",");
		stringstream ss(buffer);
		getline(ss, DBunivers.universities[i].name, ';');
		getline(ss, DBunivers.universities[i].adres.city, ',');
		getline(ss, DBunivers.universities[i].adres.street, ',');
		getline(ss, DBunivers.universities[i].adres.home, ';');
		getline(ss, token, ';');
		for (int j = 0; j < DBunivers.universities[i].numOfSpecialties; j++)
		{
			stringstream ss2(token);
			getline(ss2, DBunivers.universities[i].specialties[j], ',');
		}
		getline(ss, token, ';');
		strReplaceAll(token, ",", " ");
		readNumLine(DBunivers.universities[i].contestDay, token, DBunivers.universities[i].numOfSpecialties);
		getline(ss, token, ';');
		strReplaceAll(token, ",", " ");
		readNumLine(DBunivers.universities[i].contestNight, token, DBunivers.universities[i].numOfSpecialties);
		getline(ss, token, ';');
		strReplaceAll(token, ",", " ");
		readNumLine(DBunivers.universities[i].contestOnline, token, DBunivers.universities[i].numOfSpecialties);
		getline(ss, token, ';');
		strReplaceAll(token, ",", " ");
		readNumLine(DBunivers.universities[i].cost, token, DBunivers.universities[i].numOfSpecialties);
	}
	f.close();
}

void output(DBUniversities& univs)
{
	for (int i = 0; i < univs.count; i++)
	{
		cout << "Название вуза: " << univs.universities[i].name << endl;
		cout << "Адрес: " << univs.universities[i].adres.city << ", "
			<< univs.universities[i].adres.street << ", "
			<< univs.universities[i].adres.home << endl;
		cout << "Специальности:\n";
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
}