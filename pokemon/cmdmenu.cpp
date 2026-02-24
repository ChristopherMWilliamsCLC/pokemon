#include "cmdmenu.h"

void clearBuffer()
{
	cin.clear();
	cin.ignore(200, '\n');
}

void outputCurrentEv(const pokeMenuEv &x)
{
	cout << "HP ev is: " << x.evHp << endl;
	cout << "Attack ev is: " << x.evAttack << endl;
	cout << "Sp. Attack ev is: " << x.evSpAttack << endl;
	cout << "Defense ev is: " << x.evDefense << endl;
	cout << "Sp. Defense ev is: " << x.evSpDefense << endl;
	cout << "Speed ev is: " << x.evSpeed << endl;
	cout << "EV Total: " << x.evHp + x.evAttack + x.evSpAttack + x.evDefense + x.evSpDefense + x.evSpeed << endl;
	cout << endl;
}

bool getInvalidEV(const pokeMenuEv &x)
{
	return x.evHp +
		   x.evAttack +
		   x.evSpAttack +
		   x.evDefense +
		   x.evSpDefense +
		   x.evSpeed < 0 ||
		   x.evHp +
		   x.evAttack +
		   x.evSpAttack +
		   x.evDefense +
		   x.evSpDefense +
		   x.evSpeed > 510
		   ||
		   x.evHp < 0 || x.evHp > 255 ||
		   x.evAttack < 0 || x.evAttack > 255 ||
		   x.evSpAttack < 0 || x.evSpAttack > 255 ||
		   x.evDefense < 0 || x.evDefense > 255 ||
		   x.evSpDefense < 0 || x.evSpDefense > 255 ||
		   x.evSpeed < 0 || x.evSpeed > 255;
}

void modifyMenuEv(pokeMenuEv &x, int &y, string evName)
{
	// Simple function that outputs the  current EV values.
	outputCurrentEv(x);
	cout << "Please enter the new value." << endl;
	cin >> y;
	cout << endl;
	// If the total of all EV's are less than 0 or greater than 510 or if a individual EV is less than 0 or greater than 255.
	if (getInvalidEV(x))
	{
		// Reset EV to 0 and output a error message.
		y = 0;
		cout << "ERROR: Effort values must not exceed 255, and the sum of all EV values combined must not exceed 510." << endl << endl;
		cout << evName << " RESET TO: 0" << endl << endl;
	}
	outputCurrentEv(x);
	// Clear the buffer if the client enters a non-numerical value.
	clearBuffer();
}

void PokemonCMDMenu(int ivHp, int ivAttack, int ivSpAttack, int ivDefense, int ivSpDefense, int ivSpeed)
{
	int level = 0;
	string name, sNature;
	bool done = false;
	pokeMenuEv effortValues;
	stats::effortValues ev;
	pokemon::individualValues iv;
	pokemon* p = new pokemon;	

	while (!done)
	{
		cout << "1) Set the pokemons name." << endl;
		cout << "2) Set the pokemons level." << endl;
		cout << "3) Set the pokemons nature." << endl;
		cout << "4) Set HP effort value." << endl;
		cout << "5) Set Attack effort value." << endl;
		cout << "6) Set Sp. Attack effort value." << endl;
		cout << "7) Set Defense effort value." << endl;
		cout << "8) Set Sp. Defense effort value." << endl;
		cout << "9) Set Speed effort value." << endl;
		cout << "10) Print the pokemon's final stats." << endl;
		cout << "Enter any key to exit." << endl << endl;

		int iChoice = 0;
		cin >> iChoice;
		cout << endl;
		switch (iChoice)
		{
		case 1:
			if (name != "")
				cout << "The current name is set as: " << name << endl;
			cout << "Enter the pokemons name." << endl;
			cin >> name;
			cout << endl;
			continue;
		case 2:
			if (level != 0)
				cout << "The current level is set as: " << level << endl;
			cout << "Enter the pokemons level." << endl;
			cin >> level;
			cout << endl;
			clearBuffer();
			continue;
		case 3:
			if (sNature != "")
				cout << "The current nature is set as: " << sNature << endl;
			cout << "Enter the pokemons nature." << endl;
			cin >> sNature;
			cout << endl;
			continue;
		case 4:
			modifyMenuEv(effortValues, effortValues.evHp, "HP");
			continue;
		case 5:
			modifyMenuEv(effortValues, effortValues.evAttack, "ATTACK");
			continue;
		case 6:
			modifyMenuEv(effortValues, effortValues.evSpAttack, "SP. ATTACK");
			continue;
		case 7:
			modifyMenuEv(effortValues, effortValues.evDefense, "DEFENSE");
			continue;
		case 8:
			modifyMenuEv(effortValues, effortValues.evSpDefense, "SP. DEFENSE");
			continue;
		case 9:
			modifyMenuEv(effortValues, effortValues.evSpeed, "SPEED");
			continue;
		case 10:
			// Set the pokemons iv's with the CMD menus iv's.
			iv.ivHp = ivHp;
			iv.ivAttack = ivAttack;
			iv.ivSpAttack = ivSpAttack;
			iv.ivDefense = ivDefense;
			iv.ivSpDefense = ivSpDefense;
			iv.ivSpeed = ivSpeed;

			// Set the pokemons ev's with the CMD menus ev's.
			ev.evHp = effortValues.evHp;
			ev.evAttack = effortValues.evAttack;
			ev.evSpAttack = effortValues.evSpAttack;
			ev.evDefense = effortValues.evDefense;
			ev.evSpDefense = effortValues.evSpDefense;
			ev.evSpeed = effortValues.evSpeed;

			// Create and print a pokemon object from the variables specified in the switch statement.
			p->setName(name);
			p->setIndividualValues(iv);
			p->setBaseStats(name);
			p->setLevel(level);
			p->setNature(sNature);
			p->setEffortValues(ev);
			p->printPokemon();

			// Reset all the CMD menu variables in the function to re-use in the next iteration of the loop.
			name = "";
			sNature = "";
			level = 0;
			effortValues.evHp = 0;
			effortValues.evAttack = 0;
			effortValues.evSpAttack = 0;
			effortValues.evDefense = 0;
			effortValues.evSpDefense = 0;
			effortValues.evSpeed = 0;

			// Delete the pokemon object that was just printed and create a new one to use in the next iteration of the loop.
			delete p;
			p = nullptr;
			p = new pokemon;

			// Continue to the next iteration of the loop.
			continue;
		default:
			// Clean the data and terminate the loop.
			delete p;
			p = nullptr;
			done = true;
			break;
		}
	}
}