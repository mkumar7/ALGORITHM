#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tournament.h"

#define NUM_TEAMS 32
#define NUM_PLAYERS 10
Player *draftPlayers(char *league, int team, int play)
{
    Team * swap = NULL;
    swap= malloc(sizeof(Team));
    swap->name = NULL;

    Player * players = NULL;
    players = malloc(sizeof(Player)*play);
    int j = 0;
   
    do{
        players[j].team=0;
        players[j].f="";
        players[j].l="";
        players[j].no=0;
        players[j].offensive=0;
        players[j].defensive=0;
        j++;
    }
     while(j<play);
    swap->players = NULL;
    swap->players = malloc(sizeof(Player)*NUM_PLAYERS*NUM_TEAMS);
    FILE * fp = fopen(league, "r");
    
        char x[25], y[25];
        int k=0;
        
        do{
             
            while(fscanf(fp,"%d,%[^,],%[^,],%d,%d,%d",&swap->players[j].team,x,
                                                y,&swap->players[j].no,
                                                &swap->players[j].offensive,&swap->players[j].defensive) == 6)
            {

                swap->players[j].f=x;
                swap->players[j].l=y;

                while(swap->players[j].team == team && k<play)
                {

                        players[k].team = swap->players[j].team;
                        players[k].f = strdup(swap->players[j].f);
                        players[k].l = strdup(swap->players[j].l);
                        players[k].no = swap->players[j].no;
                        players[k].offensive = swap->players[j].offensive;
                        players[k].defensive = swap->players[j].defensive;
                        k++;
                 }
            }
            j++;
        }
        while(j<(NUM_PLAYERS*NUM_TEAMS));
            fclose(fp);

    return ((Player *)(players));
    free(players[k].f);
    free(players[k].l);
    free(swap->players);
    free(swap->name);
    free(swap);
    free(players);
    
}
 
Team * newTeam(char * name, Player * team)
{
    Team *x = NULL;
    x=malloc(sizeof(Team));
    x->name = name;
    x->players = team;
    return x;
    free(x->players);
    free(x->name);   
}

Team * game(Team *qualifier1, Team *qualifier2)
{
    int one_defen=0,two_offen=0;
  
    while(qualifier1==NULL && qualifier2==NULL)
    {
     if(qualifier1==qualifier2)
     {
        return qualifier1;
    }
    else if(qualifier1=NULL)
    {
        return qualifier2;
    }
    else if(qualifier2==NULL)
    {
        return qualifier1;
    }
    else
    {
        int try = 0;
        do
        {
            one_defen += qualifier1->players[try].defensive;
            two_offen += qualifier2->players[try].offensive;
            try++;
        }
        while(try<NUM_PLAYERS);
        if(one_defen >= two_offen)
        {
            return qualifier1;
        }
        else
        {
            return qualifier2;
        }
    }
  }
}

Team * tournament(Team **team,int squad){
    Team *qualifier1=NULL;
    while(!((squad & (squad - 1))) && (squad!=0))
    {
        Team **qualifier2 = NULL;
        qualifier2 = malloc(sizeof(Team)*(squad*0.5));
        int i =0;
        int j =0;
        do
        {
            qualifier2[i]=game(team[j],team[j+1]);
            j = j + 2;
            i++;
        }
        while(j<squad);
    
        qualifier1=qualifier2[rand()%(squad/2)];
        free(qualifier2);
        return qualifier1;
    }
        return NULL;
        free(team);
}

Team * deleteTeam(Team * team)
{
  for(int i=0;i<10;i++)
  {
    free((team->players[i].f));
    free((team->players[i].l));
  }
  free(team->players);
  free(team);
}
