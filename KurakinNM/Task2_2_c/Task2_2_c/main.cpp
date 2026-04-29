#include "university.h"
#include <locale.h>
#include <string.h>

int main()
{
	//DBUniversities DBUnivers, FindedDBUnivers;
	int i, j, work = 1,option;
	string str;
	system("chcp 1251");
	system("cls");
	DBUniversities DBUnivers("universities.txt");

	while(work)
	{
		cout << "===========================================" << endl;
		cout << "Выберите режим поиска " << 
			"(1 - всё о данном вузе, " <<
			"2 - всё о данной специальности, " << 
			"3 - поиск минимального конкурса по данной специальности, " <<
			"4 - по специальностям каждого вуза, " <<
			"5 - вывести все вузы, " <<
			"0 - выход):";
		cin >> option;
		switch (option)
		{
		case 0:
			work = 0;
			break;
		case 1:
			while (getchar() != '\n');
			cout << "Введите название вуза: ";
			cin >> str;
			cin.ignore();
			DBUnivers.allAboutUniver(str);
			break;
		/*case 2:
			while (getchar() != '\n');
			cout << "Введите название специальности: ";
			cin >> str;
			cin.ignore();
			allAboutSpec(DBUnivers, str);
			break;
		case 3:
			while (getchar() != '\n');
			cout << "Введите название специальности: ";
			cin >> str;
			cin.ignore();
			minContestSpec(FindedDBUnivers, DBUnivers, str);
			FindedDBUnivers.print();
			FindedDBUnivers.~DBUniversities();
			break;
		case 4:
			findSpec(DBUnivers);
			break;*/
		case 5:
			DBUnivers.print();
			break;
		default:
			while (getchar() != '\n');
			cout << "Некорекный ввод.\n";
			break;
		}
	}

	return 0;
}