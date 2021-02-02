#define _CRT_SECURE_NO_WARNINGS // Supresses C4996 error on line 22 (localtime is no longer used)

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int sec, min, hr; // Variables for seconds, minutes and hours
	string mer; // string to fold the meridiem (PM / AM)
	int secPrev = 0;

	while (true)
	{
		time_t totalSeconds = time(0); // variable to store total time in seconds

		// Get values of seconds, minutes and hours
		struct tm* ct = localtime(&totalSeconds);

		sec = ct->tm_sec;
		min = ct->tm_min;
		hr = ct->tm_hour;

		// Convert into 12 hour format
		if (hr >= 12) 
		{
			mer = " PM";
		}
		else
		{
			mer = " AM";
		}
		hr = hr > 12 ? hr - 12 : hr;

		// Draw / Print the time
		if (sec == secPrev + 1 || (secPrev == 59 && sec == 0)) 
		{
			system("CLS");
			cout << "Current Time (Local):" << "\n";
			cout << hr << ":"<< min << ":"<< sec << mer << "\n";
		}

		// Update the seconds
		secPrev = sec;
	}
	return 0;
}