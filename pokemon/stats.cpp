#include "stats.h"
#include "customsql.cpp"

stats::stats()
{
	level = 0;
	hp = 1;
	attack = 1;
	sp_attack = 1;
	defense = 1;
	sp_defense = 1;
	speed = 1;
	iv_hp = 1;
	iv_attack = 1;
	iv_sp_attack = 1;
	iv_defense = 1;
	iv_sp_defense = 1;
	iv_speed = 1;
	ev_hp = 0;
	ev_attack = 0;
	ev_sp_attack = 0;
	ev_defense = 0;
	ev_sp_defense = 0;
	ev_speed = 0;
}

void stats::printStats()
{
	// Create a nature object using the default constructor.
	nature invalidNature;

	// If the nature is the default nature using the nature class's default constructor it's not a valid nature.
	string invalid = invalidNature.getNature();

	// Check if the pokemon is invalid.
	bool invalidPokemon = getNature() == invalid ||
						  getBaseStats() == "1 1 1 1 1 1" ||
						  getIndividualValues() == "1 1 1 1 1 1" ||
						  getLevel() < 1 || getLevel() > 100;

	/*
		Below is just to make sure that if one thing isn't set correctly then everything is reset to default.
		Just to make sure the user isn't misled into thinking that a correct stat calculation was performed
		by not seeing a error message.
	*/
	
	// Checks if the nature, base-stats, or iv isn't set correctly. If any of them is a default value they're all set to default.
	if (invalidPokemon)		
		setStatsToDefault(); // Sets the level, ev, and iv to the stats class default constructor value.
	else
		setStatsToCalc(); // Handles all the math to calculate and set the final stats.

	// Outputs the individual values.
	cout << "Individual Values " << endl;
	cout << "HP: " << iv_hp << endl;
	cout << "Attack: " << iv_attack << endl;
	cout << "Sp. Attack: " << iv_sp_attack << endl;
	cout << "Defense: " << iv_defense << endl;
	cout << "Sp. Defense: " << iv_sp_defense << endl;
	cout << "Speed: " << iv_speed << endl;

	cout << endl;

	// Outputs the effort values.
	cout << "Effort Values " << endl;
	cout << "HP: " << ev_hp << endl;
	cout << "Attack: " << ev_attack << endl;
	cout << "Sp. Attack: " << ev_sp_attack << endl;
	cout << "Defense: " << ev_defense << endl;
	cout << "Sp. Defense: " << ev_sp_defense << endl;
	cout << "Speed: " << ev_speed << endl;

	cout << endl;

	// Outputs the final stat calculation.
	cout << "Final Stat Calculation" << endl;
	cout << "Level: " << level << endl;
	cout << "HP: " << hp << endl;
	cout << "Attack: " << attack << endl;
	cout << "Sp. Attack: " << sp_attack << endl;
	cout << "Defense: " << defense << endl;
	cout << "Sp. Defense: " << sp_defense << endl;
	cout << "Speed: " << speed << endl;
}

void stats::printHighestHp()
{
	int i = 1;
	double average = 0;

	// Load the base stats from a file. (Can be database or file)
	loadBaseStats();

	// Sort basestats.txt by HP from highest to lowest. (Can be database or file)
	sort(aPokemon.begin(), aPokemon.end(), [](sPokemon& a, sPokemon& b) {return a.vhp > b.vhp; });

	cout << "HIGHEST BASE HP" << endl << endl;
	for (sPokemon const &start : aPokemon)
	{
		// Only worry about strings that begin with a capital letter.
		if (start.vname[0] <= 'Z')
		{
			// Format and print the pokemon name and hp.
			cout << setfill('0') << setw(3) << i << ") " << start.vname << " HP: " << start.vhp << endl;
			// Get the sum of all pokemons hp to calculate the average. 
			average += start.vhp;
			// Increament i to count the number of pokemon.
			i += 1;
		}		
	}
	// Minus i by 1 for correctness since i started at 1 when the loop began.
	i -= 1;

	// Round up the average due to truncation of decimals on integers.
	average = ((average) / i) + 0.50;

	// Output the highest hp of all pokemon. (ternary expression just makes sure the pokemon result begins with a capital letter)
	cout << endl << "Highest HP: " << (aPokemon[0].vname > aPokemon[1].vname ? aPokemon[1].vname : aPokemon[0].vname) << " " << aPokemon[0].vhp;

	// Output the average hp of all pokemon.
	cout << endl << "Average HP: " << static_cast<int>(average);

	// Output the lowest hp of all pokemon.
	/*
		Multiply i by 2 because the actual vector is double i. (due to storing pokemon with caps and lowercase for the 1st letter of their name.)
		Minus by 1 again because vector elements start at 0. Doing it like this makes sure adding more pokemon to the vector isn't a issue.
	*/
	i = (i * 2) - 1;

	// Make sure the first letter of the name is capitalized, and output the rest of the string starting at the second letter (position 1). Also output the hp value.
	cout << endl << "Lowest HP: " << static_cast<char>(toupper(aPokemon[i].vname[0])) << aPokemon[i].vname.substr(1) << " " << aPokemon[i].vhp << endl << endl;

	// Unload the basestat by clearing the vector.
	aPokemon.clear();
}

void stats::printHighestAttack()
{
	loadBaseStats();
	int i = 1;
	double average = 0;
	sort(aPokemon.begin(), aPokemon.end(), [](sPokemon& a, sPokemon& b) {return a.vattack > b.vattack; });

	cout << "HIGHEST BASE ATTACK" << endl << endl;
	for (sPokemon const &start : aPokemon)
	{
		if (start.vname[0] <= 'Z')
		{
			cout << setfill('0') << setw(3) << i << ") " << start.vname << " ATTACK: " << start.vattack << endl;
			average += start.vattack;
			i += 1;
		}
	}
	i -= 1;
	average = ((average) / i) + 0.50;
	cout << endl << "Highest Attack: " << (aPokemon[0].vname > aPokemon[1].vname ? aPokemon[1].vname : aPokemon[0].vname) << " " << aPokemon[0].vattack;
	cout << endl << "Average Attack: " << static_cast<int>(average);

	i = (i * 2) - 1;

	cout << endl << "Lowest Attack: " << static_cast<char>(toupper(aPokemon[i].vname[0])) << aPokemon[i].vname.substr(1) << " " << aPokemon[i].vattack << endl << endl;
	aPokemon.clear();
}

void stats::printHighestSpAttack()
{
	loadBaseStats();
	int i = 1;
	double average = 0;
	sort(aPokemon.begin(), aPokemon.end(), [](sPokemon& a, sPokemon& b) {return a.vsp_attack > b.vsp_attack; });
	cout << "HIGHEST BASE SPECIAL ATTACK" << endl << endl;
	for (sPokemon const &start : aPokemon)
	{
		if (start.vname[0] <= 'Z')
		{
			cout << setfill('0') << setw(3) << i << ") " << start.vname << " SP. ATTACK: " << start.vsp_attack << endl;
			average += start.vsp_attack;
			i += 1; 
		}
	}
	i -= 1;
	average = ((average) / i) + 0.50;
	cout << endl << "Highest Sp. Attack: " << (aPokemon[0].vname > aPokemon[1].vname ? aPokemon[1].vname : aPokemon[0].vname) << " " << aPokemon[0].vsp_attack;
	cout << endl << "Average Sp. Attack: " << static_cast<int>(average);

	i = (i * 2) - 1;

	cout << endl << "Lowest Sp. Attack: " << static_cast<char>(toupper(aPokemon[i].vname[0])) << aPokemon[i].vname.substr(1) << " " << aPokemon[i].vsp_attack << endl << endl;
	aPokemon.clear();
}

void stats::printHighestDefense()
{
	loadBaseStats();
	int i = 1;
	double average = 0;
	sort(aPokemon.begin(), aPokemon.end(), [](sPokemon& a, sPokemon& b) {return a.vdefense > b.vdefense; });
	cout << "HIGHEST BASE DEFENSE" << endl << endl;
	for (sPokemon const &start : aPokemon)
	{
		if (start.vname[0] <= 'Z')
		{
			cout << setfill('0') << setw(3) << i << ") " << start.vname << " DEFENSE: " << start.vdefense << endl;
			average += start.vdefense;
			i += 1; 
		}
	}
	i -= 1;
	average = ((average) / i) + 0.50;
	cout << endl << "Highest Defense: " << (aPokemon[0].vname > aPokemon[1].vname ? aPokemon[1].vname : aPokemon[0].vname) << " " << aPokemon[0].vdefense;
	cout << endl << "Average Defense: " << static_cast<int>(average);

	i = (i * 2) - 1;

	cout << endl << "Lowest Defense: " << static_cast<char>(toupper(aPokemon[i].vname[0])) << aPokemon[i].vname.substr(1) << " " << aPokemon[i].vdefense << endl << endl;

	aPokemon.clear();
}

void stats::printHighestSpDefense()
{
	loadBaseStats();
	int i = 1;
	double average = 0;
	sort(aPokemon.begin(), aPokemon.end(), [](sPokemon& a, sPokemon& b) {return a.vsp_defense > b.vsp_defense; });
	cout << "HIGHEST BASE SPECIAL DEFENSE" << endl << endl;
	for (sPokemon const &start : aPokemon)
	{
		if (start.vname[0] <= 'Z')
		{
			cout << setfill('0') << setw(3) << i << ") " << start.vname << " SP. DEFENSE: " << start.vsp_defense << endl;
			average += start.vsp_defense;
			i += 1;
		}
	}
	i -= 1;
	average = ((average) / i) + 0.50;
	cout << endl << "Highest Sp. Defense: " << (aPokemon[0].vname > aPokemon[1].vname ? aPokemon[1].vname : aPokemon[0].vname) << " " << aPokemon[0].vsp_defense;
	cout << endl << "Average Sp. Defense: " << static_cast<int>(average);

	i = (i * 2) - 1;

	cout << endl << "Lowest Sp. Defense: " << static_cast<char>(toupper(aPokemon[i].vname[0])) << aPokemon[i].vname.substr(1) << " " << aPokemon[i].vsp_defense << endl << endl;
	aPokemon.clear();
}

void stats::printHighestSpeed()
{
	loadBaseStats();
	int i = 1;
	double average = 0;
	sort(aPokemon.begin(), aPokemon.end(), [](sPokemon& a, sPokemon& b) {return a.vspeed > b.vspeed; });
	cout << "HIGHEST BASE SPEED" << endl << endl;
	for (sPokemon const &start : aPokemon)
	{
		if (start.vname[0] <= 'Z')
		{	
			cout << setfill('0') << setw(3) << i << ") " << start.vname << " SPEED: " << start.vspeed << endl;
			average += start.vspeed;
			i += 1;
		}
	}
	i -= 1;
	average = ((average) / i) + 0.50;
	cout << endl << "Highest Speed: " << (aPokemon[0].vname > aPokemon[1].vname ? aPokemon[1].vname : aPokemon[0].vname) << " " << aPokemon[0].vspeed;
	cout << endl << "Average Speed: " << static_cast<int>(average);

	i = (i * 2) - 1;

	cout << endl << "Lowest Speed: " << static_cast<char>(toupper(aPokemon[i].vname[0])) << aPokemon[i].vname.substr(1) << " " << aPokemon[i].vspeed << endl << endl;
	aPokemon.clear();
}

void stats::setIndividualValues(individualValues iv)
{
	if (iv.ivHp > 0 && iv.ivHp <= 31 &&
		iv.ivAttack > 0 && iv.ivAttack <= 31 &&
		iv.ivSpAttack > 0 && iv.ivSpAttack <= 31 &&
		iv.ivDefense > 0 && iv.ivDefense <= 31 &&
		iv.ivSpDefense > 0 && iv.ivSpDefense <= 31 &&
		iv.ivSpeed > 0 && iv.ivSpeed <= 31)
	{
		iv_hp = iv.ivHp;
		iv_attack = iv.ivAttack;
		iv_sp_attack = iv.ivSpAttack;
		iv_defense = iv.ivDefense;
		iv_sp_defense = iv.ivSpDefense;
		iv_speed = iv.ivSpeed;
	}
	else
	{
		cout << "ERROR: IV values must be greater than 0 and less than or equal to 31." << endl;
	}
}

void stats::setEffortValues(effortValues ev)
{
	if (
		ev.evHp +
		ev.evAttack +
		ev.evSpAttack +
		ev.evDefense +
		ev.evSpDefense +
		ev.evSpeed >= 0 &&
		ev.evHp +
		ev.evAttack +
		ev.evSpAttack +
		ev.evDefense +
		ev.evSpDefense +
		ev.evSpeed <= 510 &&
		ev.evHp >= 0 && ev.evHp <= 255 &&
		ev.evAttack >= 0 && ev.evAttack <= 255 &&
		ev.evSpAttack >= 0 && ev.evSpAttack <= 255 &&
		ev.evDefense >= 0 && ev.evDefense <= 255 &&
		ev.evSpDefense >= 0 && ev.evSpDefense <= 255 &&
		ev.evSpeed >= 0 && ev.evSpeed <= 255)
	{
		ev_hp = ev.evHp;
		ev_attack = ev.evAttack;
		ev_sp_attack = ev.evSpAttack;
		ev_defense = ev.evDefense;
		ev_sp_defense = ev.evSpDefense;
		ev_speed = ev.evSpeed;
	}
	else
	{
		cout << "ERROR: Effort values must not exceed 255, and the sum of all EV values combined must not exceed 510." << endl;
	}
}

void stats::setLevel(int pokeLevel)
{
	if (pokeLevel > 0 && pokeLevel <= 100)
	{
		level = pokeLevel;
	}
	else
	{
		cout << "ERROR: Pokemon level must be greater than 0 and less than or equal to 100." << endl;
	}
}

void stats::setBaseStats(string pokeName)
{
	bool validPokemon = false;

	// Load the base stats from a database or file into the vector. (2 different versions)
	loadBaseStats();

	// Sort the pokemon in alphabetical order (Ascending).
	sort(aPokemon.begin(), aPokemon.end(), [](const sPokemon& a, const sPokemon& b) {return a.vname < b.vname; });

	/*
		aPokemon.begin() is an iterator pointing to the first element in the vector.
		aPokemon.end() is an iterator pointing one past the last valid element in the vector.
		It is used by lower_bound to indicate the end of the range for the search.

		pokeName is the value that lower_bound is searching for in the vector in this case,
		but lower_bound can also be used with arrays or other random-access containers.

		Argument 4 is a lambda function that defines the comparison logic for lower_bound.
		In this case, it tells lower_bound to search the vector in ascending order by comparing a.vname < b.

		To sort in descending order, adjust both the sort function's comparison argument
		and the lower_bound lambda to use a.vname > b instead of a.vname < b.

		The 'b' in the lambda function represents pokeName, the value being searched for.
		The 'a.vname' represents each Pokémon's name as the lambda iterates through the vector.

		lower_bound should only be used after ensuring the vector is sorted, as it relies on the sorted order to function correctly.
		Using auto as the data-type in place of vector<sPokemon>::iterator works for all iterator types.
	*/
	vector<sPokemon>::iterator it = lower_bound(aPokemon.begin(), aPokemon.end(), pokeName, [](const sPokemon& a, const string& b) {return a.vname < b; });

	// If the lower_bound search finds pokeName set the stats and set validPokemon to true.
	if (it->vname == pokeName)
	{
		hp = it->vhp;
		attack = it->vattack;
		sp_attack = it->vsp_attack;
		defense = it->vdefense;
		sp_defense = it->vsp_defense;
		speed = it->vspeed;
		validPokemon = true;
	}

	// If validPokemon isn't true set the stats to default and output a error message.
	if (validPokemon != true)
	{
		setStatsToDefault();
		cout << "ERROR: " << pokeName << " is not a valid pokemon." << endl;
	}

	// Clear the vector elements. 
	aPokemon.clear();
}

string stats::getIndividualValues() const
{
	return to_string(iv_hp) + " " +
		to_string(iv_attack) + " " +
		to_string(iv_sp_attack) + " " +
		to_string(iv_defense) + " " +
		to_string(iv_sp_defense) + " " +
		to_string(iv_speed);
}

string stats::getIvHp() const
{
	return to_string(iv_hp);
}

string stats::getIvAttack() const
{
	return to_string(iv_attack);
}

string stats::getIvSpAttack() const
{
	return to_string(iv_sp_attack);
}

string stats::getIvDefense() const
{
	return to_string(iv_defense);
}

string stats::getIvSpDefense() const
{
	return to_string(iv_sp_defense);
}

string stats::getIvSpeed() const
{
	return to_string(iv_speed);
}

string stats::getEffortValues() const
{
	return to_string(ev_hp) + " " +
		to_string(ev_attack) + " " +
		to_string(ev_sp_attack) + " " +
		to_string(ev_defense) + " " +
		to_string(ev_sp_defense) + " " +
		to_string(ev_speed);
}

string stats::getEvHp() const
{
	return to_string(ev_hp);
}

string stats::getEvAttack() const
{
	return to_string(ev_attack);
}

string stats::getEvSpAttack() const
{
	return to_string(ev_sp_attack);
}

string stats::getEvDefense() const
{
	return to_string(ev_defense);
}

string stats::getEvSpDefense() const
{
	return to_string(ev_sp_defense);
}

string stats::getEvSpeed() const
{
	return to_string(ev_speed);
}

int stats::getLevel() const
{
	return level;
}

string stats::getBaseStats() const
{
	return to_string(hp) + " " +
		to_string(attack) + " " +
		to_string(sp_attack) + " " +
		to_string(defense) + " " +
		to_string(sp_defense) + " " +
		to_string(speed);
}

string stats::getFinalHp() const
{
	return to_string(hp);
}

string stats::getFinalAttack() const
{
	return to_string(attack);
}

string stats::getFinalSpAttack() const
{
	return to_string(sp_attack);
}

string stats::getFinalDefense() const
{
	return to_string(defense);
}

string stats::getFinalSpDefense() const
{
	return to_string(sp_defense);
}

string stats::getFinalSpeed() const
{
	return to_string(speed);
}
/*
void stats::loadBaseStats()
{
	
	MYSQL* conn = mysql_init(NULL); // Initialize database.
	connectDatabase(conn, "pokemon"); // Connect to the database. (Function uses my custom credentials)

	mysql_query(conn, "SELECT * FROM basestats;"); // Run a select query to retrieve data from the basestats table.
	MYSQL_RES* result = getQueryResult(conn); // Store the results of the query.
	MYSQL_ROW row; // Initialize row array.
	//int col = mysql_num_fields(result); // Get the number of total columns based on the query result.

	aPokemon.clear(); // If the vector has something in it you might want to delete it before running this operation.

	// Loop through the database until theirs no more rows.
	while (row = mysql_fetch_row(result))
	{
		// Variabilize and format the rows to be stored in the vector.
		string name = row[1]; // Start at 1 because in the database 0 is a primary key id.
		int hp = stoi(row[2]); // stoi = string to int. Everything from the database is a const char* by default. 
		int attack = stoi(row[3]);
		int sp_attack = stoi(row[4]);
		int defense = stoi(row[5]);
		int sp_defense = stoi(row[6]);
		int speed = stoi(row[7]);

		// Load the basestats into the aPokemon vector.
		aPokemon.emplace_back(name, hp, attack, sp_attack, defense, sp_defense, speed);
	}
	closeDatabase(conn); // Clean up by closing the database.
}
*/
// Load base stats from a simple text file.Above version is from a MySQL database.
void stats::loadBaseStats()
{
	ifstream file;
	string name;

	// Open the file.
	file.open("basestats.txt");

	// Check if the file is closed, output a debug message, and terminate the program.
	if (!file)
	{
		cout << "File could not open!" << endl;
		return;
	}

	// Clear the vector of all elements.
	aPokemon.clear();

	// While the file has data populate the vector.
	while (file >> name >> hp >> attack >> sp_attack >> defense >> sp_defense >> speed)
	{
		aPokemon.emplace_back(name, hp, attack, sp_attack, defense, sp_defense, speed);
	}

	// Close the file.
	file.close();
}

void stats::setStatsToCalc()
{
	// Check if the pokemon is shedinja based on the unique base stats.
	bool isShedinja = getBaseStats() == "1 90 30 45 30 40";
	// Hp stat calculations.(Shedinja always has 1 hp no matter what)
	if (isShedinja)
		hp = 1;
	else
		hp = (((2 * hp + iv_hp + (ev_hp / 4)) * level) / 100) + level + 10;

	// Attack stat calculations.
	if (getNature() == "Adamant" ||
		getNature() == "Brave" ||
		getNature() == "Lonely" ||
		getNature() == "Naughty" ||
		getNature() == "adamant" ||
		getNature() == "brave" ||
		getNature() == "lonely" ||
		getNature() == "naughty")
	{
		attack = static_cast<int>((((2 * attack + iv_attack + (ev_attack / 4)) * level) / 100 + 5) * 1.1);
	}
	else if (getNature() == "Bold" ||
		getNature() == "Calm" ||
		getNature() == "Modest" ||
		getNature() == "bold" ||
		getNature() == "calm" ||
		getNature() == "modest" ||
		getNature() == "Timid" ||
		getNature() == "timid")
	{
		attack = static_cast<int>((((2 * attack + iv_attack + (ev_attack / 4)) * level) / 100 + 5) * 0.9);
	}
	else
	{
		attack = static_cast<int>((((2 * attack + iv_attack + (ev_attack / 4)) * level) / 100 + 5) * 1.0);
	}

	// Sp. Attack stat calculations.
	if (getNature() == "Mild" ||
		getNature() == "Modest" ||
		getNature() == "mild" ||
		getNature() == "modest")
	{
		sp_attack = static_cast<int>((((2 * sp_attack + iv_sp_attack + (ev_sp_attack / 4)) * level) / 100 + 5) * 1.1);
	}
	else if (getNature() == "Jolly" ||
		getNature() == "Impish" ||
		getNature() == "Careful" ||
		getNature() == "Adamant" ||
		getNature() == "jolly" ||
		getNature() == "impish" ||
		getNature() == "careful" ||
		getNature() == "adamant")
	{
		sp_attack = static_cast<int>((((2 * sp_attack + iv_sp_attack + (ev_sp_attack / 4)) * level) / 100 + 5) * 0.9);
	}
	else
	{
		sp_attack = static_cast<int>((((2 * sp_attack + iv_sp_attack + (ev_sp_attack / 4)) * level) / 100 + 5) * 1.0);
	}

	// Defense stat calculations.
	if (getNature() == "Bold" ||
		getNature() == "Impish" ||
		getNature() == "Lax" ||
		getNature() == "Relaxed" ||
		getNature() == "bold" ||
		getNature() == "impish" ||
		getNature() == "lax" ||
		getNature() == "relaxed")
	{
		defense = static_cast<int>((((2 * defense + iv_defense + (ev_defense / 4)) * level) / 100 + 5) * 1.1);
	}
	else if (getNature() == "Mild" ||
		getNature() == "Lonely" ||
		getNature() == "Hasty" ||
		getNature() == "Gentle" ||
		getNature() == "mild" ||
		getNature() == "lonely" ||
		getNature() == "hasty" ||
		getNature() == "gentle")
	{
		defense = static_cast<int>((((2 * defense + iv_defense + (ev_defense / 4)) * level) / 100 + 5) * 0.9);
	}
	else
	{
		defense = static_cast<int>((((2 * defense + iv_defense + (ev_defense / 4)) * level) / 100 + 5) * 1.0);
	}

	// Sp. Defense stat calculations.
	if (getNature() == "Calm" ||
		getNature() == "Careful" ||
		getNature() == "Gentle" ||
		getNature() == "calm" ||
		getNature() == "careful" ||
		getNature() == "gentle")
	{
		sp_defense = static_cast<int>((((2 * sp_defense + iv_sp_defense + (ev_sp_defense / 4)) * level) / 100 + 5) * 1.1);
	}
	else if (getNature() == "Lax" ||
		getNature() == "lax")
	{
		sp_defense = static_cast<int>((((2 * sp_defense + iv_sp_defense + (ev_sp_defense / 4)) * level) / 100 + 5) * 0.9);
	}
	else
	{
		sp_defense = static_cast<int>((((2 * sp_defense + iv_sp_defense + (ev_sp_defense / 4)) * level) / 100 + 5) * 1.0);
	}

	// Speed stat calculations.
	if (getNature() == "Hasty" ||
		getNature() == "Jolly" ||
		getNature() == "hasty" ||
		getNature() == "jolly" ||
		getNature() == "Timid" ||
		getNature() == "timid")
	{
		speed = static_cast<int>((((2 * speed + iv_speed + (ev_speed / 4)) * level) / 100 + 5) * 1.1);
	}
	else if (getNature() == "Brave" ||
		getNature() == "brave")
	{
		speed = static_cast<int>((((2 * speed + iv_speed + (ev_speed / 4)) * level) / 100 + 5) * 0.9);
	}
	else
	{
		speed = static_cast<int>((((2 * speed + iv_speed + (ev_speed / 4)) * level) / 100 + 5) * 1.0);
	}
}

void stats::setStatsToDefault()
{
	level = 0;
	hp = 1;
	attack = 1;
	sp_attack = 1;
	defense = 1;
	sp_defense = 1;
	speed = 1;
	iv_hp = 1;
	iv_attack = 1;
	iv_sp_attack = 1;
	iv_defense = 1;
	iv_sp_defense = 1;
	iv_speed = 1;
	ev_hp = 0;
	ev_attack = 0;
	ev_sp_attack = 0;
	ev_defense = 0;
	ev_sp_defense = 0;
	ev_speed = 0;
}