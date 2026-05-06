#include "university.h"

Special::Special()
{
	this->universityName = "";
	this->name = "";
	this->contestDay = 0;
	this->contestNight = 0;
	this->contestOnline = 0;
	this->cost = 0;
}

Special::Special(const string& universityName, const string& name, unsigned int contestDay, unsigned int contestNight, unsigned int contestOnline, float cost)
{
	this->universityName = universityName;
	this->name = name;
	this->contestDay = contestDay;
	this->contestNight = contestNight;
	this->contestOnline = contestOnline;
	this->cost = cost;
}

void Special::print() {
		cout << this->name << endl;
		cout << "Конкурс прошлого года (Дневной/Вечерний/Заочный): " <<
			this->contestDay << "/" <<
			this->contestNight << "/" <<
			this->contestOnline << endl;
		cout << "Оплата при договорном обучении: " << this->cost << endl;
}
void Special::fullInfoPrint() {
	cout << "Специальность: " << this->name << endl;
	cout << "Вуз: " << this->universityName << endl;
	cout << "Конкурс прошлого года (Дневной/Вечерний/Заочный): " <<
		this->contestDay << "/" <<
		this->contestNight << "/" <<
		this->contestOnline << endl;
	cout << "Оплата при договорном обучении: " << this->cost << endl;
}

bool Special::checkName(const string& name)
{
	return this->name.find(name) != string::npos;
}