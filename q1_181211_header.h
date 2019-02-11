#pragma once
#include<iostream>
#include<string>
using namespace std;

class CricketTeam
{
	string*membernames;
	int no_of_members;
	char*teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;

public:
	//Constructors
	CricketTeam();
	CricketTeam(string name, int memberno);
	CricketTeam(string filepath);
	
	//Getters
	string Getcaptain();
	int Getrank();
	string GetteamName();
	int Getno_of_members();
	
	//Setters
	void Setcaptain(string cap);
	void Setrank(int ranking);
	void SetteamName(string teamN);
	void Setno_of_members(int memberno);

	//Functions
	void inputTeamMember(string name);
	void inputScore(int score);
	double avgScore();
	void Printlatestinfo();
	void Printinfo();
	bool teamCompare(CricketTeam team2);

	//Destructor
	~CricketTeam();
};