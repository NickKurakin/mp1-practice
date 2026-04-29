#include "university.h"

Special::Special()
{
	this->name = "";
	this->contestDay = 0;
	this->contestNight = 0;
	this->contestOnline = 0;
	this->cost = 0;
}

Special::Special(const Special& special)
{
	this->name = special.name;
	this->contestDay = special.contestDay;
	this->contestNight = special.contestNight;
	this->contestOnline = special.contestOnline;
	this->cost = special.cost;
}

Special::Special(const string& name, unsigned int contestDay, unsigned int contestNight, unsigned int contestOnline, float cost)
{
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