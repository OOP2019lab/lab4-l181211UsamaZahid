#include <iostream>
#include "q1_181211_header.h"
#include <string.h>
#include <fstream>
using namespace std;

//Default Constructor
CricketTeam::CricketTeam()
{
	membernames = nullptr;
	no_of_members = -1;
	teamName = nullptr;
	for (int i = 0; i < 10; i++)
		Scoreinlast10matches[i] = -1;
	Rank = -1;
	captain = " ";
}

//Parameter Constructor
CricketTeam::CricketTeam(string name, int memberno)
{
	membernames = new string[memberno];
	for (int i = 0; i < memberno; i++)
		membernames[i] = " ";
	no_of_members = memberno;
	
	int len = name.length();
	teamName = new char[len+1];
	for (int i = 0; i < len; i++)
		teamName[i] = name.c_str()[i];
	teamName[len] = '\0';
	
	for (int i = 0; i < 10; i++)
		Scoreinlast10matches[i] = -1;
	Rank = -1;
	captain = " ";
}

//File Constructor
CricketTeam::CricketTeam(string filepath)
{
	ifstream readfile;
	readfile.open(filepath);
	string teamN="";
	string empty;
	string memberno;
	string ranking;
	getline(readfile,empty,':');
	getline(readfile, teamN);
	int len = teamN.size();
	teamName = new char[len+1];
	int i;
	for (i = 0; i < len; i++)
		teamName[i] = teamN.c_str()[i];
	teamName[i] = '\0';
	getline(readfile, empty, ':');
	getline(readfile, memberno);
	no_of_members = stoi(memberno);
	membernames = new string [no_of_members];
	for (int i = 0; i < no_of_members; i++)
		getline(readfile, membernames[i]);
	getline(readfile, empty, ':');
	getline(readfile, ranking);
	Rank = stoi(ranking);
	getline(readfile, empty, ':');
	getline(readfile, captain);
	getline(readfile, empty, ':');
	string score;
	for (int i = 0; i < 10; i++)
	{
		getline(readfile, score, ',');
		Scoreinlast10matches[i] = stoi(score);
	}
}

//Default Consatructor
CricketTeam::~CricketTeam()
{
	membernames = nullptr;
	teamName = nullptr;
	delete[]membernames;
	delete[]teamName;
}

//Getter for Captain
string CricketTeam::Getcaptain()
{
	return captain;
}
//Setter for Captain
void CricketTeam::Setcaptain(string cap)
{
	captain = cap;
}

//Getter for Rank
int CricketTeam::Getrank()
{
	return Rank;
}
//Setter for Rank
void CricketTeam::Setrank(int ranking)
{
	Rank = ranking;
}

//Getter for Team Name
string CricketTeam::GetteamName()
{
	return teamName;
}
//Setter for Team Name
void CricketTeam::SetteamName(string teamN)
{
	int len = teamN.length();
	if (teamName != nullptr)
		delete[]teamName;
	teamName = new char[len + 1];
	for (int i = 0; i < len; i++)
		teamName[i] = teamN.c_str()[i];
	teamName[len] = '\0';
}

//Getter for No of members
int CricketTeam::Getno_of_members()
{
	return no_of_members;
}
//Setter for No of members
void CricketTeam::Setno_of_members(int memberno)
{
	no_of_members = memberno;
	if (membernames != nullptr)
		delete[]membernames;
	membernames = new string[memberno];
}

//Input of Team Members
void CricketTeam::inputTeamMember(string name)
{
	if (membernames == nullptr)
		membernames = new string[no_of_members]();
	bool stored = 0;
	for (int i=0;i<no_of_members && stored!=1;i++)
	{
		if (membernames[i] == " ")
		{
			membernames[i] = name;
			stored = 1;
		}
	}
	if (stored==0)
		cout << "No Space available\n";
}

//Input of Team Latest Score
void CricketTeam::inputScore(int score)
{
	bool stored = 0;
	for (int i = 0;i < 10;i++)
	{
		if (Scoreinlast10matches[i] == -1)
		{
			Scoreinlast10matches[i] = score;
			i = 10;
			stored = 1;
		}
	}
	if (stored == 0)
	{
		for (int i = 0;i < 9;i++)
			Scoreinlast10matches[i] = Scoreinlast10matches[i + 1];
		Scoreinlast10matches[9] = score;
	}
}

//Calculation of Average Score of team
double CricketTeam::avgScore()
{
	double sum = 0;
	int j = 0;
	for (int i = 0; i < 10; i++)
		if (Scoreinlast10matches[i] != -1)
		{
			sum = sum + Scoreinlast10matches[i];
			j++;
		}
	return sum / j;
}

//Prints information of TeamName, Captain and its LatestScore
void CricketTeam::Printlatestinfo()
{
	cout << "\nTeam Name: " << teamName;
	cout << "\nCaptain: " << captain;
	cout << "\nLatest Score: " << Scoreinlast10matches[9] << endl;
}

//Prints all Team information
void CricketTeam::Printinfo()
{
	cout << "\nTeam Name: " << teamName;
	cout << "\nTotal Members: " << no_of_members << endl;
	for (int i = 0;i < no_of_members;i++)
		cout << membernames[i] << endl;
	cout << "Rank: " << Rank;
	cout << "\nCaptain: " << captain;
	cout << "\nScore: ";
	for (int i = 0;i < 10;i++)
	{
		if (Scoreinlast10matches[i] != -1)
			cout << Scoreinlast10matches[i];
		if (i < 9 && Scoreinlast10matches[i] != -1)
			cout << ",";
	}
}

//Compares two teams checking whether input team is better
bool CricketTeam::teamCompare(CricketTeam team2)
{
	if (team2.avgScore()>avgScore())
		return true;
	else
		return false;
}