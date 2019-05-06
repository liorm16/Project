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
//	Q1-Adding a team

void add_Team(team teams[])
{
	if (team_num <= MAX_TEAMS_NUMBER) 
	{
		team_num++;
		char team_name[ARR_SIZE];
		printf("The new team name: ");//NEED TO CHECK LIMITATION ON NAME LENGTH 
		scanf_s("%s", team_name,ARR_SIZE);
		printf("A NEW team is in BORLAND league! Team ~%s~, it's team #%d in the league", team_name, team_num);
		team lol = { .name = team_name };
		teams[team_num-1] = lol;
	}
	else 
	{
		printf("The league is full, you can't add a new team");
	}
}



//---------------------------------------------------------------//
//	Q2-Adding a player

void add_Player(team teams[])
{
	if (team_num!=0)
	{
		int select_team = 0;
		int select_age = 0;
		char player_name[ARR_SIZE];
		printf("Select a team (from [%d-%d]) to add a player to: ", 1, team_num);
		scanf_s("%d", &select_team);
		if (teams[select_team].numberOfPlayers <= MAX_PLAYERS)
		{
			teams[select_team].numberOfPlayers++;
			player pl;
			printf("Enter player's name: ");//NEED TO CHECK LIMITATION ON NAME LENGTH AND EXISTENCE
			scanf_s("%s", pl.name,ARR_SIZE);
			printf("Enter player's age: ");
			scanf_s("%d", &pl.age);
			printf("Enter player's attack power (from [1-100]): ");
			scanf_s("%d", &pl.attack);
			printf("Enter player's defense power (from [1-100]): ");
			scanf_s("%d", &pl.defense);
			teams[select_team].teamPlayers[teams[select_team].numberOfPlayers - 1] = pl;
			printf("A NEW player ~%s~ is added to Team %s, it's player #%d in the team",pl.name,teams[select_team].name,teams[select_team].numberOfPlayers);
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
void play_Game() {}

//---------------------------------------------------------------//
void print_League() {}

//---------------------------------------------------------------//
void print_Team() {}

//---------------------------------------------------------------//

int main()
{
	team teams[MAX_TEAMS_NUMBER] = {NULL};
	int choice = -1;
	printf("\n********************************\nWelcome to BORLAND Futsal league\n********************************\nLeague menu:\n        0. Exit\n        1. Print the menu again\n        2. Add a futsal team\n        3. Add a futsal player to a team\n        4. Play a game\n        5. Print the league table\n        6. Print team details\n");
	while (choice != 0) 
	{
		if (choice != 1) 
		{
			printf("\nPlease choose the desired option [0-6]: ");
			scanf_s("%d", &choice);
		}
		if (choice == 1) 
		{
			printf("\n********************************\nWelcome to BORLAND Futsal league\n********************************\nLeague menu:\n        0. Exit\n        1. Print the menu again\n        2. Add a futsal team\n        3. Add a futsal player to a team\n        4. Play a game\n        5. Print the league table\n        6. Print team details\n");
			printf("\nPlease choose the desired option [0-6]: ");
			scanf_s("%d", &choice);
		}
		if (choice == 2) 
		{
			add_Team(teams);
		}
		if (choice == 3) 
		{
			add_Player(teams);
		}
		if (choice == 4) {
			play_Game();
		}
		if (choice == 5) 
		{
			print_League();
		}
		if (choice == 6) 
		{
			print_Team();
		}

	}
}
