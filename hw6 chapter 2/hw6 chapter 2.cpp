#include <iostream>
#include <string.h>
using namespace std;
#define MAX_STR 20
#define SIZE 10
struct Event
{
	char title[MAX_STR]; // the name of the event
	char place[MAX_STR]; // the place where the event took place
	int year;

};
struct Sportsman
{

	int id; // id number
	char pName[MAX_STR]; // private name
	char fName[MAX_STR]; // family name
	bool gender; // the gender of the sportsman, true - woman, false � man
	int numEvents; // number of events the sportsman played
	Event* events; // array of events where the sportsman played
};

bool addSportsman(Sportsman sport[], int size, int* num, int add);
int countEvent(char eventname[], int eventyear, Sportsman sport[], int size);
bool checkWomenEvent(char eventName[], int eventyear, Sportsman sport[], int size);
void compareCountries(Sportsman sport[], int size);
void printsport(Sportsman sport[], int size);

int main()
{
	int num = 0;
	Sportsman sport[10];
	addSportsman(sport, SIZE, &num, 5);
	printsport(sport, num);
	char event[] = "o";
	int year = 1;
	cout << "\n number of same sports man int the year " << year << " place " << event << ": " << countEvent(event, year, sport, num);
	if (checkWomenEvent(event, year, sport, num))
	{
		cout << "\nthere are at least 2 woman in the event " << event << " at the year " << year;
	}
	else
	{
		cout << "\nthere are less than 2 woman in the event " << event << " at the year " << year;

	}
	compareCountries(sport, num);
	for (int i = 0; i < num; i++)
	{
		delete[] sport[i].events;
	}
}


void printsport(Sportsman sport[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nsports man number\t"<<i<<endl;
		cout << "name: " << sport[i].pName << endl;
		cout << "familyname: " << sport[i].fName << endl;
		cout << "gender " << sport[i].gender << endl;
		cout << "number of events " << sport[i].numEvents << endl;
		for (int j = 0; j < sport[i].numEvents; j++)
		{
			cout << "event title" << sport[i].events[j].title << endl;
			cout << "event place " << sport[i].events[j].place << endl;
			cout << "event year " << sport[i].events[j].year << endl;
		}
	}



}

bool addSportsman(Sportsman sport[], int size, int* num, int add)
{

	if (*num + add >= size)
	{
		cout << "\nsorry not enough space!";
		return false;
	}

	for (int i = *num; i < *num + add; i++)
	{
		cout << "\nplease enter id: ";
		cin >> sport[i].id;

		if (sport[i].id == sport[i - 1].id)
		{
			cout << "allready inside";
			sport[i].id = NULL;
			return false;
		}

		cout << "\nplease enter private name: ";
		cin >> sport[i].pName;
		cout << "\nplease enter family name: ";
		cin >> sport[i].fName;
		cout << "\nplease enter gender 1=female 0=male : ";
		cin >> sport[i].gender;
		cout << "\nplease enter number of events : ";
		cin >> sport[i].numEvents;
		Event* eventsnew = new Event[sport[i].numEvents];
		if (!eventsnew)
		{
			cout << "ERROR";
			return false;
		}
		for (int j = 0; j < sport[i].numEvents; j++)
		{
			cout << "\nevent number " << j + 1;
			cout << "\nplease enter title ";
			cin >> eventsnew[j].title;
			cout << "\nplease enter place ";
			cin >> eventsnew[j].place;
			cout << "\nplease enter year ";
			cin >> eventsnew[j].year;
		}
		sport[i].events = eventsnew;
	}
	*num += add;


}


void compareCountries(Sportsman sport[], int size)
{
	cout << "\ncountry compare\n";
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size - 1; j++)
		{
			if (flag && strcmp(sport[i].events->place, sport[j + 1].events->place) == 0 && strcmp(sport[i].events->title, sport[j + 1].events->title) != 0 && sport[i].events->year == sport[j + 1].events->year)
			{
				cout << "\nthe name of the event " << sport[i].events->title;
				cout << "\nthe name of the other event " << sport[j + 1].events->title;
				cout << "\nthe year of the event " << sport[i].events->year;
				flag = false;
			}
		}
		cout << endl;
		flag = true;
	}

}

bool checkWomenEvent(char eventName[], int eventyear, Sportsman sport[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		cout << eventName << endl;
		cout << sport[i].events->title << endl;
		cout << strcmp(sport[i].events->title, eventName);
		if (sport[i].gender == 1 && strcmp(sport[i].events->title, eventName) == 0 && sport[i].events->year == eventyear)
		{
			sum++;
		}
		if (sum >= 2)
		{
			return true;
		}
	}
	return false;
}

int countEvent(char eventname[], int eventyear, Sportsman sport[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(sport[i].events->title) == *eventname && sport[i].events->year == eventyear)
		{
			sum++;
		}
	}
	return sum;

}