#ifndef CMDMENU_H
#define CMDMENU_H

#include "pokemon.h"

/*
	Don't confuse these with the private member variables in the stats class.
	These are native to the cmd menu. The purpose is that it allows the user 
	to select the ev's without actually setting the ev's with setEffortValues(). 
	When the user selects the desired ev's he can print the pokemon objects stats
	using those selections. Setting a new value every time the user changes an EV
	causes a bug. It makes more sense to let the user select all the wanted EV's 
	before setting them with setEffortValues();
*/
struct pokeMenuEv
{
	int evHp = 0;
	int evAttack = 0;
	int evSpAttack = 0;
	int evDefense = 0;
	int evSpDefense = 0;
	int evSpeed = 0;
};

void clearBuffer();
void outputCurrentEv(const pokeMenuEv &x);
bool getInvalidEV(const pokeMenuEv &x);
void modifyMenuEv(pokeMenuEv &x, int &y, string evName);

/*
	I thought it would be too much to add individual values inside the menu's switch statement so I just defaulted them all to 31.
	I only care about the best possible stats anyways except in special cases. Regardless, it can always be set to different
	values as a argument when you run the PokemonCMDMenu() function.
*/
void PokemonCMDMenu(int ivHp = 31, int ivAttack = 31, int ivSpAttack = 31, int ivDefense = 31, int ivSpDefense = 31, int ivSpeed = 31);

#endif
