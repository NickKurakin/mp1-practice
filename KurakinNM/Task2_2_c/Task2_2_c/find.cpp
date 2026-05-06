#include "university.h"

void DBUniversities::allAboutUniver(const string& name)
{
	int i;
	for (i = 0; i < this->count; i++)
	{
		if (this->universities[i].checkName(name))
		{
			this->universities[i].print();
			break;
		};
	}
	if (i == this->count)
	{
		cout << "Вуз не найден." << endl;
	}
}

void DBUniversities::allAboutSpec(const string& special)
{
	int n = 0;
	Special* spec = nullptr;
	for (int i = 0; i < this->count; i++)
	{
		spec = this->universities[i].checkSpecial(special);
		if (spec != nullptr)
		{
			spec->fullInfoPrint();
			cout << endl;
			n++;
		}
	}
	if (n == 0)
	{
		cout << "Специальность не найдена." << endl;
	}
}
DBUniversities* DBUniversities::minContestSpec(const string& special)
{
	int i, j, n = 0;
	int DU = -1, DS = -1;
	int NU = -1, NS = -1;
	int OU = -1, OS = -1;
	Special* spec = nullptr;
	DBUniversities* result = nullptr;
	for (int i = 0; i < this->count; i++)
	{
		spec = this->universities[i].checkSpecial(special);
		if (spec != nullptr)
		{
			if (DU != -1)
			{
				if (spec->contestDay < DS) { DU = i; DS = spec->contestDay; }
				if (spec->contestNight < NS) { NU = i; NS = spec->contestNight; }
				if (spec->contestOnline < OS) { OU = i; OS = spec->contestOnline; }
			}
			else
			{
				DU = i; DS = spec->contestDay;
				NU = i; NS = spec->contestNight;
				OU = i; OS = spec->contestOnline;
			}
		}
	}
	if (DU == -1) cout << "Специальность не найдена." << endl;
	else {
		result = new DBUniversities(University(this->universities[DU], *this->universities[DU].checkSpecial(special)),
			University(this->universities[NU], *this->universities[NU].checkSpecial(special)),
			University(this->universities[OU], *this->universities[OU].checkSpecial(special)));
	}
	return result;
}
/*
void findSpec(DBUniversities& univs)
{
	int i, j;
	int DS = -1;
	int NS = -1;
	int OS = -1;
	for (i = 0; i < univs.count; i++)
	{
		DS = -1;
		NS = -1;
		OS = -1;
		cout << "Название вуза: " << univs.universities[i].name << endl;
		cout << "Адрес: " << univs.universities[i].adres.city << ", " <<
			univs.universities[i].adres.street << ", " <<
			univs.universities[i].adres.home << endl;

		for (j = 0; j < univs.universities[i].numOfSpecialties; j++)
		{
			if (DS != -1)
			{
				if (univs.universities[i].contestDay[j] < univs.universities[i].contestDay[DS]) DS = j;
				if (univs.universities[i].contestNight[j] < univs.universities[i].contestNight[NS]) NS = j;
				if (univs.universities[i].contestOnline[j] < univs.universities[i].contestOnline[OS]) OS = j;
			}
			else
			{
				DS = j;
				NS = j;
				OS = j;
			}
		}
		cout << "Минимальный дневной конкурс: " << univs.universities[i].contestDay[DS] << endl;
		cout << "Специальность: " << univs.universities[i].specialties[DS] << endl;
		cout << "Минимальный вечерний конкурс: " << univs.universities[i].contestNight[NS] << endl;
		cout << "Специальность: " << univs.universities[i].specialties[NS] << endl;
		cout << "Минимальный заочный конкурс: " << univs.universities[i].contestOnline[OS] << endl;
		cout << "Специальность: " << univs.universities[i].specialties[OS] << endl;
		cout << endl;
	}
}*/

/*void cpy(char* input, char** output, int len)
{

	(*output) = (char*)malloc(len + 1);
	strncpy(*output, input, len + 1);
}

int find(BOOK* lib, BOOK** findedBooks, int numOfBooks, char* str)
{
	int i, j, k, n = 0, strLen;
	char* p;
	strLen = strlen(str) - 1;
	for (i = 0; i < numOfBooks; i++)
	{
		for (j = 0; j < lib[i].numberOfAuthors; j++)
		{
			if (strstr(lib[i].authors[j], str))
			{
				n++;
				break;
			};
		}
	}

	*findedBooks = (BOOK*)malloc(n * sizeof(BOOK));
	n = 0;

	for (i = 0; i < numOfBooks; i++)
	{
		for (j = 0; j < lib[i].numberOfAuthors; j++)
		{
			if (strstr(lib[i].authors[j], str))
			{
				cpy(lib[i].title, &((*findedBooks)[n].title), strlen(lib[i].title));
				cpy(lib[i].ed, &((*findedBooks)[n].ed), strlen(lib[i].ed));

				(*findedBooks)[n].year = lib[i].year;
				(*findedBooks)[n].numberOfAuthors = lib[i].numberOfAuthors;

				(*findedBooks)[n].authors = (char**)malloc(lib[i].numberOfAuthors * sizeof(char*));
				for (k = 0; k < lib[i].numberOfAuthors; k++)
				{
					cpy(lib[i].authors[k], &((*findedBooks)[n].authors[k]), strlen(lib[i].authors[k]));
				}
				n++;
				break;
			}
		}
	}
	return n;
}*/