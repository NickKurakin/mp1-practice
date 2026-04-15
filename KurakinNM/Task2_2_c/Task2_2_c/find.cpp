#include "university.h"

void allAboutUniver(DBUniversities& univers, string name)
{
	int i, j;
	for (i = 0; i < univers.count; i++)
	{
		if (univers.universities[i].name.find(name) != string::npos)
		{
			cout << "Название вуза: " << univers.universities[i].name << endl;
			cout << "Адрес: " << univers.universities[i].adres.city << ", " << 
				univers.universities[i].adres.street << ", " <<
				univers.universities[i].adres.home << endl;
			cout << "Специальности:" << endl;
			for (j = 0; j < univers.universities[i].numOfSpecialties; j++)
			{
				cout << univers.universities[i].specialties[j] << endl;
				cout << "Конкурс прошлого года (Дневной/Вечерний/Заочный):" <<
					univers.universities[i].contestDay[j] << "/" << 
					univers.universities[i].contestNight[j] << "/" <<
					univers.universities[i].contestOnline[j] << endl;
				cout << "Оплата при договорном обучении: " << univers.universities[i].cost[j] << "р." << endl;
			}
			cout << endl;
			break;
		};
	}
	if (i == univers.count)
	{
		cout << "Вуз не найден." << endl;
	}
}

void allAboutSpec(DBUniversities& univs, string special)
{
	int i, j, n = 0;
	for (i = 0; i < univs.count; i++)
	{
		for (j = 0; j < univs.universities[i].numOfSpecialties; j++)
		{
			if (univs.universities[i].specialties[j].find(special) != string::npos)
			{
				cout << "Специальность: " << univs.universities[i].specialties[j] << endl;
				cout << "Вуз: " << univs.universities[i].name << endl;
				cout << "Конкурс прошлого года (Дневной/Вечерний/Заочный):" <<
					univs.universities[i].contestDay[j] << "/" <<
					univs.universities[i].contestNight[j] << "/" <<
					univs.universities[i].contestOnline[j] << endl;
				cout << "Оплата при договорном обучении: " << univs.universities[i].cost[j] << "р." << endl;
				cout << endl;

				n++;
				break;
			}
		}
	}
	if (n == 0)
	{
		cout << "Специальность не найдена." << endl;
	}
}

void minContestSpec(DBUniversities& universResult, DBUniversities& univers, string special)
{
	int i, j, n = 0;
	int DU = -1, DS = -1;
	int NU = -1, NS = -1;
	int OU = -1, OS = -1;
	for (i = 0; i < univers.count; i++)
	{
		for (j = 0; j < univers.universities[i].numOfSpecialties; j++)
		{
			if (univers.universities[i].specialties[j].find(special) != string::npos)
			{
				if (DU != -1)
				{
					if (univers.universities[i].contestDay[j] < univers.universities[DU].contestDay[DS]) { DU = i; DS = j; }
					if (univers.universities[i].contestNight[j] < univers.universities[NU].contestNight[NS]) { NU = i; NS = j; }
					if (univers.universities[i].contestOnline[j] < univers.universities[OU].contestOnline[OS]) { OU = i; OS = j; }
				}
				else
				{
					DU = i; DS = j;
					NU = i; NS = j;
					OU = i; OS = j;
				}
				break;
			}
		}
	}
	if (DU == -1) cout << "Специальность не найдена." << endl;
	else {
		if (DU != NU && NU != OU && DU != OU) {
			universResult.count = 3;
			universResult.universities = new University[3];
			CopyUOnlyOneSpec(universResult.universities[0], univers.universities[DU], special);
			CopyUOnlyOneSpec(universResult.universities[1], univers.universities[NU], special);
			CopyUOnlyOneSpec(universResult.universities[2], univers.universities[OU], special);
		}
		else if (DU == NU && NU == OU) {
			universResult.count = 1;
			universResult.universities = new University[1];
			CopyUOnlyOneSpec(universResult.universities[0], univers.universities[DU], special);
		}
		else {
			universResult.count = 2;
			universResult.universities = new University[2];
			CopyUOnlyOneSpec(universResult.universities[0], univers.universities[DU], special);
			if (DU != NU) CopyUOnlyOneSpec(universResult.universities[1], univers.universities[NU], special);
			else CopyUOnlyOneSpec(universResult.universities[1], univers.universities[OU], special);
		};
	}
}

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
}

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