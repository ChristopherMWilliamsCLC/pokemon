/*
Example: Adamant or adamant both work but aDaMaNt or AdAmAnT will fail.

here is a list of all Pokémon natures and their effects on stats:
1.	Adamant: +Attack, -Special Attack
2.	Bashful: No effect
3.	Bold: +Defense, -Attack
4.	Brave: +Attack, -Speed
5.	Calm: +Special Defense, -Attack
6.	Careful: +Special Defense, -Special Attack
7.	Docile: No effect
8.	Gentle: +Special Defense, -Defense
9.	Hardy: No effect
10.	Hasty: +Speed, -Defense
11.	Impish: +Defense, -Special Attack
12.	Jolly: +Speed, -Special Attack
13.	Lax: +Defense, -Special Defense
14.	Lonely: +Attack, -Defense
15.	Mild: +Special Attack, -Defense
16.	Modest: +Special Attack, -Attack
17.	Naive: +Speed, -Special Defense
18.	Naughty: +Attack, -Special Defense
19.	Quiet: +Special Attack, -Speed
20.	Quirky: No effect
21.	Rash: +Special Attack, -Special Defense
22.	Relaxed: +Defense, -Speed
23.	Sassy: +Special Defense, -Speed
24.	Serious: No effect
25.	Timid: +Speed, -Attack
*/

#ifndef NATURE_H
#define NATURE_H

#include <iostream>
#include <string>

using namespace std;

class nature
{
public:
	nature();
	void printNature();
	void setNature(string);
	string getNature() const;

private:
	string pokeNature;
};

#endif