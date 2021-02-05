//**********************************************************
// Author D.S. Malik and R.D. Budde
// 
// class dataType
// This class specifies the members to implement a date.
//**********************************************************

#include <iostream>

using namespace std;

class dateType
{
public:
	void setDate(int month, int day, int year)
		//Function to set the date.
		//The member variables dMonth, dDay, and dYear are set
		//according to the parameters.
		//Postcondition: dMonth = month; dDay = day; dYear = year
	{
		
		if (year >= 1900 && year <= 9999) // determines if it is a valid 4 digit year
		{
			dYear = year;
		}
		else
		{
			dYear = 1900;
			cout << "Month must be a four digit number after 1900" << "\n";
		}
		
		if (month >= 1 && month <= 12) // determines if it is valid month value
		{
			dMonth = month;
		}
		else
		{
			dMonth = 1;
			cout << "Month must be a number between 1 and 12" << "\n";
		}
		
		switch (dMonth)
		{
		case 4: // determines if valid day value for months with only 30 days
		case 6:
		case 9:
		case 11:
		{
			if (day >= 1 && day <= 30)
			{
				dDay = day;
			}
			else
			{
				dDay = 1;
				cout << "Day must be a number between 1 and 30" << "\n";
			}
		} break;

		case 1: // determines if valid day value for months with 31 days
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if (day >= 1 && day <= 31)
			{
				dDay = day;
			}
			else
			{
				dDay = 1;
				cout << "Day must be a number between 1 and 31" << "\n";
			}
		} break;
		case 2:
			if (isLeapYear(year) == true) // determines if valid day value for Feb in a non-leapyear
			{
				if (day >= 1 && day <= 29)
				{
					dDay = day;
				}
				else
				{
					dDay = 1;
					cout << "Day must be a number between 1 and 29" << "\n";
				}
			}
			else
			{
				if (day >= 1 && day <= 28) // determines if valid day value for Feb in a non-leapyear
				{
					dDay = day;
				}
				else
				{
					dDay = 0;
					cout << "Day must be a number between 1 and 28" << "\n";
				}
			}
		}

		
		dDaysInMonth = calcDaysInMonth(dMonth, dYear);
		dIsLeapYear = isLeapYear(dYear);
		calcDaysPast();
		calcDaysRemaining();
		calcDaysRemainingInMonth();


	}

	int getDay() const
		//Function to return the day.
		//Postcondition: The value of dDay is returned.
	{
		return dDay;
	}

	int getMonth() const
		// Funciton to return the month.
		//Postcondition: The value of dMonth is returned.
	{
		return dMonth;
	}

	int getYear() const
		//Function to return th eyear.
		//Postcondition: Thne valu eof dMonth is returned.
	{
		return dYear;
	}

	void printDate() const
		//Function to output the date in the form mm-dd-yyyy.
	{
		cout << "\n";
		cout << dMonth << "-" << dDay << "-" << dYear;
	}

	bool getIsLeapYear()
	{
		return dIsLeapYear;
	}

	int getDaysInMonth()
	{
		return dDaysInMonth;
	}



	int getPastDays()
	{
		return dDaysPast;
	}

	int getRemainindDays()
	{
		return dDaysRemaining;
	}

	void setNewDate(int addedDays)
	{
		calcNewDate(addedDays);
	}
	
	

	dateType(int month = 1, int day = 1, int year = 1900)
		//Constructor to set the date
		//Themember variables dMonth, dDay, and dYear are set according to the parameteres.
		//Postcondition: dMonth = month; dDay = day; dYear = year. If 
		//     no values are specified, the defalut values are used to
		//     initialize the member variables.
	{
		setDate(month, day, year);
	}

private:
	int dMonth; //variable to store the month
	int dDay;   //variable to store the day
	int dYear;  //variable to store the year
	int dDaysPast;
	int dDaysRemaining;
	int dDaysInMonth;
	bool dIsLeapYear;
	int dDaysLeftInMonth;

	bool isLeapYear(int newYear)
		// Function to determine if it is a leapyear
	{
		bool leapYear = false;
		int year = newYear;

		if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0))
		{
			leapYear = true;
		}

		return leapYear;
	}

	int calcDaysInMonth(int newMonth, int newYear)
	{
		int numDays = 0;
		int month = newMonth;
		int year = newYear;
		
		switch (month)
		{
		case 1: numDays = 31; break;
		case 2: {
			if (isLeapYear(dYear) == true)
			{
				numDays = 29;
			}
			else
			{
				numDays = 28;
			} break;
		case 3: numDays = 31; break;
		case 4: numDays = 30; break;
		case 5: numDays = 31; break;
		case 6: numDays = 30; break;
		case 7: numDays = 31; break;
		case 8: numDays = 31; break;
		case 9: numDays = 30; break;
		case 10: numDays = 31; break;
		case 11: numDays = 30; break;
		case 12: numDays = 31; break;
		}
		}
		
		return numDays;
	}
	
	void calcDaysPast()
	{
		dDaysPast = 0;

		for (int i = 1; i < dMonth; i++)
		{
			dDaysPast = dDaysPast + calcDaysInMonth(i, dYear);
		}

		dDaysPast = dDaysPast + dDay;
	}

	void calcDaysRemaining()
	{
		dDaysRemaining = 365-dDaysPast;
	}

	void calcDaysRemainingInMonth()
	{
		dDaysLeftInMonth = dDaysInMonth - dDay;
	}

	void calcNewDate(int newNumDays)
	{
		int addedDays = newNumDays;
		int monthNum = dMonth;
		int yearNum = dYear;
		int dayNum = dDay;

		
		if (addedDays > dDaysRemaining)
		{
			addedDays = addedDays - dDaysRemaining;
			yearNum++;
			while (addedDays >= 365)
			{
				addedDays = addedDays - 365;
				yearNum++;
			}
		}
		
		if (addedDays < dDaysLeftInMonth)
		{
			dayNum = dayNum + addedDays;
		}
		else
		{
			addedDays = addedDays - dDaysLeftInMonth;
			monthNum++;
			
			while (addedDays > calcDaysInMonth(monthNum, yearNum))
			{
				addedDays = addedDays - calcDaysInMonth(monthNum, yearNum);
				monthNum++;
			}

			dayNum = addedDays;
		}

		dMonth = monthNum;
		dDay = dayNum;
		dYear = yearNum;
		
	}
};