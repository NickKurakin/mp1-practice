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

void DBUniversities::minContest()
{
	for (int i = 0; i < this->count; i++)
	{
		this->universities[i].minContest();
	}
}