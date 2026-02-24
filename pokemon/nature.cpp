#include "nature.h"

nature::nature()
{
	pokeNature = "The only valid natures are as follows:\n \n"
		"1. Adamant: +Attack, -Special Attack\n"
		"2. Bashful: No effect\n"
		"3. Bold: +Defense, -Attack\n"
		"4. Brave: +Attack, -Speed\n"
		"5. Calm: +Special Defense, -Attack\n"
		"6. Careful: +Special Defense, -Special Attack\n"
		"7. Docile: No effect\n"
		"8. Gentle: +Special Defense, -Defense\n"
		"9. Hardy: No effect\n"
		"10. Hasty: +Speed, -Defense\n"
		"11. Impish: +Defense, -Special Attack\n"
		"12. Jolly: +Speed, -Special Attack\n"
		"13. Lax: +Defense, -Special Defense\n"
		"14. Lonely: +Attack, -Defense\n"
		"15. Mild: +Special Attack, -Defense\n"
		"16. Modest: +Special Attack, -Attack\n"
		"17. Naive: +Speed, -Special Defense\n"
		"18. Naughty: +Attack, -Special Defense\n"
		"19. Quiet: +Special Attack, -Speed\n"
		"20. Quirky: No effect\n"
		"21. Rash: +Special Attack, -Special Defense\n"
		"22. Relaxed: +Defense, -Speed\n"
		"23. Sassy: +Special Defense, -Speed\n"
		"24. Serious: No effect\n"
		"25. Timid: +Speed, -Attack";
}

void nature::printNature()
{
	cout << "Nature: " << pokeNature << endl;
}

void nature::setNature(string pokeNat)
{
	if (pokeNat == "Adamant" ||
		pokeNat == "Bashful" ||
		pokeNat == "Bold" ||
		pokeNat == "Brave" ||
		pokeNat == "Calm" ||
		pokeNat == "Careful" ||
		pokeNat == "Docile" ||
		pokeNat == "Gentle" ||
		pokeNat == "Hardy" ||
		pokeNat == "Hasty" ||
		pokeNat == "Impish" ||
		pokeNat == "Jolly" ||
		pokeNat == "Lax" ||
		pokeNat == "Lonely" ||
		pokeNat == "Mild" ||
		pokeNat == "Modest" ||
		pokeNat == "Naive" ||
		pokeNat == "Naughty" ||
		pokeNat == "Quiet" ||
		pokeNat == "Quirky" ||
		pokeNat == "Rash" ||
		pokeNat == "Relaxed" ||
		pokeNat == "Sassy" ||
		pokeNat == "Serious" ||
		pokeNat == "Timid" ||
		pokeNat == "adamant" ||
		pokeNat == "bashful" ||
		pokeNat == "bold" ||
		pokeNat == "brave" ||
		pokeNat == "calm" ||
		pokeNat == "careful" ||
		pokeNat == "docile" ||
		pokeNat == "gentle" ||
		pokeNat == "hardy" ||
		pokeNat == "hasty" ||
		pokeNat == "impish" ||
		pokeNat == "jolly" ||
		pokeNat == "lax" ||
		pokeNat == "lonely" ||
		pokeNat == "mild" ||
		pokeNat == "modest" ||
		pokeNat == "naive" ||
		pokeNat == "naughty" ||
		pokeNat == "quiet" ||
		pokeNat == "quirky" ||
		pokeNat == "rash" ||
		pokeNat == "relaxed" ||
		pokeNat == "sassy" ||
		pokeNat == "serious" ||
		pokeNat == "timid")
	{
		pokeNature = pokeNat;
	}
}

string nature::getNature() const
{
	return pokeNature;
}