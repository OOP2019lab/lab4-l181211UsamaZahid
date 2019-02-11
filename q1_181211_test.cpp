#include <iostream>
#include "q1_181211_header.h"
using namespace std;

//Input and Compare of both Teams
int main()
{
	//Pakistan team input using file
	CricketTeam Pakistan("q1_181211_in.txt");
	
	//Austrailia team input using normal method
	CricketTeam Austrailia("Austrailia", 4);
	Austrailia.Setrank(2);
	Austrailia.Setcaptain("James");
	Austrailia.inputTeamMember("Howard");
	Austrailia.inputTeamMember("Mathew");
	Austrailia.inputTeamMember("James");
	Austrailia.inputTeamMember("Robert");
	Austrailia.inputTeamMember("Adam");
	Austrailia.inputScore(240);
	Austrailia.inputScore(100);
	Austrailia.inputScore(50);
	Austrailia.inputScore(190);
	Austrailia.inputScore(460);
	Austrailia.inputScore(340);
	Austrailia.inputScore(120);
	Austrailia.inputScore(135);
	Austrailia.inputScore(140);
	Austrailia.inputScore(90);
	Austrailia.inputScore(200);
	
	//Comparing both teams score
	if (Pakistan.teamCompare(Austrailia) == 1)
		Austrailia.Printinfo();
	else
		Pakistan.Printinfo();
	cout << endl;
	system("pause");
}