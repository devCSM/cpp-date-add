//	Writen by: Robin D. Budde
//	Date: Tuesday, November 20, 2018
/*	Description: 

	This program takes and displays a date.

*/

#include <iostream>
#include <string>
#include "dateType.h"

using namespace std;

int userMenu()
{
	int choice;

	cout << "\n";
	cout << "*********************** Menu ***********************" << "\n";
	cout << "1. Enter a new date." << "\n";
	cout << "2. Add a fixed number of days to current date." << "\n";
	cout << "999. Exit program." << "\n";
	cout << ">> Choose an option from the menu above." << "\n";

	cin >> choice;

	return choice;
}

void setDate()
{

}

int main()
{
	// declare and initialize variables
	int month = 0, day = 0, year = 0;
	dateType myDate; // instantiate a new object of type dateType
	int daysToAdd = 0;

	int choice = userMenu();

	while (choice != 999)
	{
		switch (choice)
		{
		case 1:
		{
			// get month part
			cout << "\n";
			cout << "Enter a month: ";
			cin >> month;

			// get day part
			cout << "\n";
			cout << "Enter a day: ";
			cin >> day;

			// get year part
			cout << "\n";
			cout << "Enter a year: ";
			cin >> year;

			// set date
			myDate.setDate(month, day, year);

			// display date
			cout << "You entered the date: ";
			myDate.printDate();
			cout << "\n";

			// display date parts
			cout << "\n";
			cout << "The month is: " << myDate.getMonth() << "\n";
			cout << "The day is: " << myDate.getDay() << "\n";
			cout << "The year is: " << myDate.getYear() << "\n";

			// test for leap year
			if (myDate.getIsLeapYear() == true)
			{
				cout << myDate.getYear() << " is a leap year." << "\n";
			}
			else
			{
				cout << myDate.getYear() << " is a not leap year." << "\n";
			}

			// return the number of days in a month
			cout << "Then number of days in month " << myDate.getMonth() << " are " << myDate.getDaysInMonth() << ".\n";

			// return the number of days passed in the year
			cout << myDate.getPastDays() << " have passed so far in this year." << ".\n";

			// return the number of days remaining in the year
			cout << "There are " << myDate.getRemainindDays() << " remaining in this year." << ".\n";
		} break;

		case 2:
		{
		// add fixed number to date

			cout << "\n";
			cout << "Enter a number of days to add to current date: ";
			cin >> daysToAdd;
			cout << "\n";
		
			cout << "When you add " << daysToAdd << " days to ";
			myDate.printDate();
		
			myDate.setNewDate(daysToAdd);
		
			cout << " you get ";
			myDate.printDate();

		} break;
		}
		choice = userMenu();
	}

	system("PAUSE");
	return 0;
}