#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//---------------------------------------------------------------//

#define ARR_SIZE 21 // maximum length of names
#define MAX_TEAMS_NUMBER 10 // maximum teams in the league
#define MAX_PLAYERS 5 // maximum players in a team
#define DEFAULT_AGE 25 // default age of a player
#define DEFAULT_ATTACK_POWER 50 // default attack power of a player
#define DEFAULT_DEFENSE_POWER 50 // default defense power of a player


//---------------------------------------------------------------//

typedef struct player
{
	char name[ARR_SIZE]; // player's name, up to 20 chars
	int age; // player's age, 0 - 120
	int defense; // defense power, 1 - 100
	int attack; // attack power, 1 - 100
}player;


//---------------------------------------------------------------//

typedef struct team
{
	char name[ARR_SIZE]; // team's name
	int numberOfPlayers; // number of players in the team, up to MAX_PLAYERS
	player teamPlayers[MAX_PLAYERS]; // array of the team players
	int points; // the team points in the league
	int wins; // number of wins
	int draws; // number of draws
	int losses; // number of losses
}team;

static int team_num = 0;


//---------------------------------------------------------------//

void print_start_page()
{
	printf("\n********************************\n");
	printf("Welcome to BORLAND Futsal league\n");
	printf("********************************\n");
	printf("League menu:\n");
	printf("        0. Exit\n");
	printf("        1. Print the menu again\n");
	printf("        2. Add a fustal team\n");
	printf("        3. Add a fustal player to a team\n");
	printf("        4. Play a game\n");
	printf("        5. Print the league table\n");
	printf("        6. Print team details\n");
}
//---------------------------------------------------------------//
//	Q1-Adding a team

void add_Team(team teams[])
{
	char team_name[ARR_SIZE];
	getchar();
	int name = 0;
	if (team_num < MAX_TEAMS_NUMBER)
	{
		printf("The new team name: ");
		scanf_s("%[^\t\n]", &team_name, ARR_SIZE);
		if (team_num != 0)
		{
			for (int i = 0; i < team_num; i++)
			{
				if (strcmp(teams[i].name, team_name) == 0) {
					printf("The team #%d-%s is already in the league\n", i + 1, team_name);
					name = 1;
				}
			}
		}
		if (name == 0) {
			int sum = 0;
			for (int i = 0; i < strlen(team_name); i++)
			{
				teams[team_num].name[i] = team_name[i];
				sum++;
			}
			teams[team_num].name[sum] = '\0';
			teams[team_num].numberOfPlayers = 0;
			teams[team_num].wins = 0;
			teams[team_num].points = 0;
			teams[team_num].losses = 0;
			teams[team_num].points = 0;
			teams[team_num].draws = 0;
			printf("A NEW team is in BORLAND league!\n");
			printf("Team ~%s~ , it's team #%d in the league\n", team_name, team_num + 1);
			team_num++;
		}
	}
	else
		printf("The league is full, you can't add a new team\n");
}



//---------------------------------------------------------------//
//	Q2-Adding a player

void add_Player(team teams[])
{
	if (team_num != 0)
	{
		int select_team = 0;
		int select_age = 0;
		char player_name[ARR_SIZE];
		getchar();
		printf("Select a team (from [%d-%d]) to add a player to: ", 1, team_num);
		scanf_s("%d", &select_team);
		getchar();
		if (teams[select_team - 1].numberOfPlayers <= MAX_PLAYERS)
		{
			teams[select_team - 1].numberOfPlayers++;
			player pl;
			printf("Enter player's name: ");//NEED TO CHECK LIMITATION ON NAME LENGTH AND EXISTENCE
			scanf_s("%[^\t\n]", pl.name, ARR_SIZE);
			printf("Enter player's age: ");
			scanf_s("%d", &pl.age);
			if (pl.age > 120 || pl.age < 0)
			{
				pl.age = DEFAULT_AGE;
				printf("wrong player's age, setting to default age of 25\n");
			}
			printf("Enter player's attack power (from [1-100]): ");
			scanf_s("%d", &pl.attack);
			if (pl.attack > 100 || pl.attack < 1)
			{
				pl.attack = DEFAULT_ATTACK_POWER;
				printf("wrong attack power, setting to default value of 50\n");
			}
			printf("Enter player's defense power (from [1-100]): ");
			scanf_s("%d", &pl.defense);
			if (pl.defense > 100 || pl.defense < 1)
			{
				pl.defense = DEFAULT_ATTACK_POWER;
				printf("wrong defense power, setting to default value of 50\n");
			}
			teams[select_team - 1].teamPlayers[teams[select_team - 1].numberOfPlayers - 1] = pl;
			printf("A NEW player ~%s~ is added to Team %s, it's player #%d in the team\n", pl.name, teams[select_team - 1].name, teams[select_team - 1].numberOfPlayers);
		}
		else
		{
			printf("Too much players");//NEED TO CHECK PRECISE OUTPUT
		}
	}
	else
	{
		printf("There are no teams in the league, add a team first before adding a player\n");
	}
}

//---------------------------------------------------------------//
void play_Game(team teams[],int matches_played[])
{
	if (team_num < 2)
		printf("You need minimum of 2 teams for a game, add teams first\n");
	else
	{
		int select_team1 = 0;
		int select_team2 = 0;
		printf("Choose the first team (from [%d-%d]): ", 1, team_num);
		scanf_s("%d", &select_team1);
		printf("Choose the second team (from [%d-%d]): ", 1, team_num);
		scanf_s("%d", &select_team2);
		if (select_team1 > team_num || select_team2 > team_num)
			printf("The team you asked for is not a real team\n");
		else if (select_team1 == select_team2)
			printf("Team can't play against itself\n");
		else
		{
			matches_played[select_team1 - 1]++;
			matches_played[select_team2 - 1]++;
			int power1 = 0;
			int power2 = 0;
			for (int i = 0; i < teams[select_team1 - 1].numberOfPlayers; i++)
			{
				int attack = teams[select_team1 - 1].teamPlayers[i].attack;
				int defense = teams[select_team1 - 1].teamPlayers[i].defense;
				int temp_power = attack + defense;
				power1 += temp_power;
			}
			for (int i = 0; i < teams[select_team2 - 1].numberOfPlayers; i++)
			{
				int attack = teams[select_team2 - 1].teamPlayers[i].attack;
				int defense = teams[select_team2 - 1].teamPlayers[i].defense;
				int temp_power = attack + defense;
				power2 += temp_power;
			}
			if (power1 > power2)
			{
				printf("Team #%d-%s WON the game", select_team1, teams[select_team1 - 1].name);
				teams[select_team1 - 1].points += 3;
				teams[select_team1 - 1].wins++;
				teams[select_team2 - 1].losses++;
			}
			if (power2 > power1)
			{
				printf("Team #%d-%s WON the game", select_team2, teams[select_team2 - 1].name);
				teams[select_team2 - 1].points += 3;
				teams[select_team2 - 1].wins++;
				teams[select_team1 - 1].losses++;
			}
			else
			{
				printf("Team #%d-%s and Team #%d-%s finished the match in a draw", select_team1, teams[select_team1 - 1].name, select_team2, teams[select_team2 - 1].name);
				teams[select_team1 - 1].points++;
				teams[select_team2 - 1].points++;
				teams[select_team1 - 1].draws++;
				teams[select_team2 - 1].draws++;
			}
		}
	}
}

//---------------------------------------------------------------//


void printSpaces(int num) {
	for (int i = 0; i < num;i++) {
		printf(" ");
	}
}

int numOfDigits(int num) {
	int n = 0;
	while (num>0) {
		n++;
		num = num / 10;
	}
	return n;
}

void print_League(team teams[], int matches_played[])
{
	int i = 0;
	if (team_num < 1)
		printf("No teams in the league, add teams first");
	else
	{
		printf("BORLAND Futsal league ranking:\n");
		printf("Rank    #(team number)-Team name        Matches played  Wins    draws   Losses\n");
		printf("Points\n");
		while(i<team_num){
			if (i == team_num)
				break;
			printf("%d",i+1);
			printSpaces(7+numOfDigits(i+1)-1);
			printf("#%d-%s", i + 1, &teams[i].name);
			printSpaces(29- strlen(teams[i].name));
			printf("%d", matches_played[i]);
			printSpaces(15 - numOfDigits(i + 1) - 1);
			printf("%d", teams[i].wins);
			printSpaces(7 - numOfDigits(i + 1) - 1);
			printf("%d", teams[i].draws);
			printSpaces(7 - numOfDigits(i + 1) - 1);
			printf("%d\n", teams[i].losses);
			i++;
			if(i==team_num)
				break;
			printf("0\n");
		}
	}
}

void table_sort(team teams[])
{
	team team_ezer;
	for (int i = team_num - 1; i > 0; i--)
	{
		for (int j = 0; j < 1; j++)
		{
			if (teams[j].points > teams[j + 1].points)
			{
				team_ezer = teams[j];
				teams[j] = teams[j + 1];
				teams[j + 1] = team_ezer;
			}
		}
	}
}

//---------------------------------------------------------------//
void print_Team(team teams[],int matches_played[]) {
	int select_team = 0;
	int i = 0;
	if (team_num > 0) {
		printf("Select a team (from [%d-%d]): ", 1, team_num);
		scanf_s("%d", &select_team);
		printf("Team #%d - %s: \n", select_team, teams[select_team - 1].name);
		printf("Matches played - %d      Wins - %d        draws - %d       Losses - %d      Points - %d\n", matches_played[select_team - 1], teams[select_team - 1].wins, teams[select_team - 1].draws, teams[select_team - 1].losses, teams[select_team - 1].points);
		if (teams[select_team - 1].numberOfPlayers > 0) {
			printf("Player number   Player name             Age     Attack  Defense\n");
			while (i < teams[select_team - 1].numberOfPlayers) {
				printf("#%d", i + 1);
				printSpaces(14 - numOfDigits(i + 1) + 1);
				printf("%s", &teams[select_team - 1].teamPlayers[i].name);
				printSpaces(24 - strlen(teams[select_team - 1].teamPlayers[i].name));
				printf("%d", teams[select_team - 1].teamPlayers[i].age);
				printSpaces(7 - numOfDigits(teams[select_team - 1].teamPlayers[i].age) + 1);
				printf("%d", teams[select_team - 1].teamPlayers[i].attack);
				printSpaces(7 - numOfDigits(teams[select_team - 1].teamPlayers[i].attack) + 1);
				printf("%d\n", teams[select_team - 1].teamPlayers[i].defense);
				i++;
			}
		}
		else {
			printf("There are no players in the team\n");
		}
	}
	else {
		printf("There are no teams in the league, add a team first\n");
	}
}

//---------------------------------------------------------------//

int main()
{
	team teams[MAX_TEAMS_NUMBER] = { NULL };
	int matches_played[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int choice = -1;
	print_start_page();
	while (choice != 0)
	{
		printf("\nPlease choose the desired option[0 - 6]: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			print_start_page();
			break;
		case 2:
			add_Team(teams);
			break;
		case 3:
			add_Player(teams);
			break;
		case 4:
			play_Game(teams,matches_played);
			break;
		case 5:
			print_League(teams,matches_played);
			break;
		case 6:
			print_Team(teams,matches_played);
			break;
		default:
			printf("\nInvalid option was chosen!!!");
			break;
		}

	}
}
