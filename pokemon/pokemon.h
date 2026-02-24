/*
	Some pokemon names have been tweaked to work in a file.

	Nidoran_F = Female Nidoran
	nidoran_F 
	Nidoran_M = Male Nidoran
	nidoran_m
	Mr_Mime 
	mr_mime
	basestats.txt file for more..
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include "stats.h"
#include <ostream>

using namespace std;

class pokemon : public stats
{
public:
	pokemon();
	pokemon(string pokeName, string pokeNature, int level, const stats::individualValues& iv, const stats::effortValues& ev);
	void printPokemon();
	//string toString() const;
	void setName(string);
	string getName() const;

private:
	string name;
};
#endif
