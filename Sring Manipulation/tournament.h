#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TOURNAMENT_H_INCLUDED
#define TOURNAMENT_H_INCLUDED

typedef struct Player
{
    int team;
    char *f;
    char *l;
    int no;
    int offensive;
    int defensive;
}Player;

typedef struct Team
{
    char *name;
    Player *players;
}Team;


Player * draftPlayers(char *league, int team, int play);
Team * newTeam(char * name, Player * team);
Team * game(Team *, Team *);
Team * tournament(Team **, int);
Team * deleteTeam(Team *);



#endif 





