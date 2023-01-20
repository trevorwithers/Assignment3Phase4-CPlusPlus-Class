#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//Trevor Withers
//This program will create a report for the Kingston Bird Watchers Society
//showing sightings in the area
int main()
{
	//housekeeping----------------------------------------------------------------------------------------------

	const int SIZE = 10;
	int ctr;
	string birdType[SIZE];
	int noSightings[SIZE];
	int totalNumber = 0, mostSeen = 0;
	double avgSightings = 0.0;
	ofstream fout("birds.dat");

	if (!fout.is_open()) //Checks that file is openable





	{
		cout << "Program will now crash..." << endl;
		exit(-1);
	}

	//input----------------------------------------------------------------------------------------------------

	fout << right << setw(40) << "Kingston Bird Watchers Society" << endl; //Writes to file at top and is not repeated
	fout << left << setw(25) << "Type of Bird" << right << setw(25) << "# of sightings" << endl << endl;
	for (ctr = 0; ctr < SIZE; ctr++)
	{
		cout << "Please Enter Bird Type or press ctrl Z to exit: ";
		getline(cin, birdType[ctr]);
		if (cin.eof()) //End program if ctrl z is entered
		{
			cout << "Program terminated..." << endl;
			break;
		}
		while (birdType[ctr].length == 0) //Validates data entry
		{
			cout << "Nothing inputted. Please Enter Bird Type or press ctrl Z to exit: ";
			getline(cin, birdType[ctr]);
			if (cin.eof())
			{
				cout << "Program terminated..." << endl;
				break;
			}
		}
		if (cin.eof())
		{
			cout << "Program terminated..." << endl;
			break;
		}
		cout << "Pleade Enter Number of Sightings or press ctrl Z to exit: ";
		cin >> noSightings[ctr];
		if (cin.eof())
		{
			cout << "Program terminated..." << endl;
			break;
		}
		while (cin.fail() || noSightings[ctr] < 0 || noSightings[ctr] > 100) //Validates data entry
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Not a valid number. Pleade Enter Number of Sightings or press ctrl Z to exit: ";
			cin >> noSightings[ctr];
			if (cin.eof())
			{
				cout << "Program terminated..." << endl;
				break;
			}
		}
		if (cin.eof())
		{
			cout << "Program terminated..." << endl;
			break;
		}
		if (noSightings[ctr] > noSightings[mostSeen]) //Determines most seen bird
		{
			mostSeen = ctr;
		}
		totalNumber += noSightings[ctr];
		cin.ignore(80, '\n');
	}

	//processing------------------------------------------------------------------------------------------------


	if (ctr > 0) //Determins the average number of bird sightings
	{
		avgSightings = totalNumber / (double)ctr;
	}

	//output-----------------------------------------------------------------------------------------------------

	for (int i = 0; i < ctr; i++) //Prints out report of bird sightings
	{
		fout << left << setw(20) << birdType[i];
		fout << right << setw(15) << noSightings[i];
		if (noSightings[i] < avgSightings) //Determines which bird type was seen below average
		{
			fout << left << setw(5) << " ***below average***";
		}
		fout << endl;
	}
	fout << endl << "Total number of sightings: " << totalNumber << endl;
	fout << "The average number of sightings was: " << avgSightings << endl;
	fout << "The " << birdType[mostSeen] << " was the most seen bird." << endl;
	cout << "The program has ended. The report is as follows:" << endl << endl;
	system("type birds.dat");
	system("pause");
	/*
		Please Enter Bird Type or press ctrl Z to exit: Robin
		Pleade Enter Number of Sightings or press ctrl Z to exit: 5
		Please Enter Bird Type or press ctrl Z to exit: Seagul
		Pleade Enter Number of Sightings or press ctrl Z to exit: 99
		Please Enter Bird Type or press ctrl Z to exit: Blue Jay
		Pleade Enter Number of Sightings or press ctrl Z to exit: 3
		Please Enter Bird Type or press ctrl Z to exit: ^Z
		Program terminated...
		The program has ended. The report is as follows:

				  Kingston Bird Watchers Society
		Type of Bird                        # of sightings
		
		Robin                             5 ***below average***
		Seagul                           99
		Blue Jay                          3 ***below average***

		Total number of sightings: 107
		The average number of sightings was: 35.6667
		The Seagul was the most seen bird.
		Press any key to continue . . .
	*/
}