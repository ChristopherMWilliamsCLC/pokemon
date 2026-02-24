#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iomanip>
#include "nature.h"
#include "basestatvect.h"
#include "mysql.h"
#include "customsql.h"

using namespace std;

class stats: public nature
{
public:

	// Constructor.
	stats();

	struct individualValues
	{
		int ivHp = 31;
		int ivAttack = 31;
		int ivSpAttack = 31;
		int ivDefense = 31;
		int ivSpDefense = 31;
		int ivSpeed = 31;
	};

	struct effortValues
	{
		int evHp = 0;
		int evAttack = 0;
		int evSpAttack = 0;
		int evDefense = 0;
		int evSpDefense = 0;
		int evSpeed = 0;
	};

	// Output.
	void printStats();

	// Setters.
	void setIndividualValues(individualValues iv);
	void setEffortValues(effortValues ev);
	void setLevel(int level);
	void setBaseStats(string pokeName);

	// Getters.
	string getIndividualValues() const;
	string getIvHp() const;
	string getIvAttack() const;
	string getIvSpAttack() const;
	string getIvDefense() const;
	string getIvSpDefense() const;
	string getIvSpeed() const;
	string getEffortValues() const;
	string getEvHp() const;
	string getEvAttack() const;
	string getEvSpAttack() const;
	string getEvDefense() const;
	string getEvSpDefense() const;
	string getEvSpeed() const;
	int getLevel() const;
	string getBaseStats() const;
	string getFinalHp() const;
	string getFinalAttack() const;
	string getFinalSpAttack() const;
	string getFinalDefense() const;
	string getFinalSpDefense() const;
	string getFinalSpeed() const;

	// Static members.
	void printHighestHp();
	void printHighestAttack();
	void printHighestSpAttack();
	void printHighestDefense();
	void printHighestSpDefense();
	void printHighestSpeed();

private:
	int level;
	individualValues iv;
	effortValues ev;	
	int hp;
	int attack;
	int sp_attack;
	int defense;
	int sp_defense;
	int speed;
	int iv_hp;
	int iv_attack;
	int iv_sp_attack;
	int iv_defense;
	int iv_sp_defense;
	int iv_speed;
	int ev_hp;
	int ev_attack;
	int ev_sp_attack;
	int ev_defense;
	int ev_sp_defense;
	int ev_speed;	
	void loadBaseStats();
	void setStatsToCalc();
	void setStatsToDefault();
};
#endif
