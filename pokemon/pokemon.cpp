#include "pokemon.h"

pokemon::pokemon()
{
	name = "";
}

pokemon::pokemon(string pokeName, string pokeNature, int level, const stats::individualValues& iv, const stats::effortValues& ev)
{
	name = pokeName;
	setNature(pokeNature);
	setLevel(level);
	setBaseStats(name);
	setIndividualValues(iv);
	setEffortValues(ev);
}

void pokemon::printPokemon()
{
	// Print pokemon name.
	cout << "Pokemon: " << name << endl;

	// Print pokemon nature.
	printNature();
	cout << "_________________________________" << endl;
	cout << endl;

	// Print pokemon stats.
	printStats();
	cout << "_________________________________" << endl << endl;
}

void pokemon::setName(string pokeName)
{
	name = pokeName;
}

string pokemon::getName() const
{
	return name;
}