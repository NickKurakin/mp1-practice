#include "university.h"

Adres::Adres()
{
	this->city = "";
	this->street = "";
	this->home = "";
}

Adres::Adres(const string& line)
{
	stringstream ss(line);
	getline(ss, this->city, ',');
	getline(ss, this->street, ',');
	getline(ss, this->home, ',');
}

Adres::Adres(const string& city, const string& street, const string& home)
{
	this->city = city;
	this->street = street;
	this->home = home;
}

void Adres::print()
{
	cout << "Адрес: " << this->city << ", "
		<< this->street << ", "
		<< this->home << endl;
}

bool Adres::operator==(const Adres& adres) const
{
	if (this->city == adres.city &&
		this->street == adres.street &&
		this->home == adres.home) return true;
	return false;
}
bool Adres::operator!=(const Adres& adres) const
{
	return !(this->operator==(adres));
}