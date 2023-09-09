#include<stdio.h>
#include<stdlib.h>

FILE *names;

struct team
{
   char teamname[20];
   
   
};
struct player
{
    char playername[50];
    char playerrole[50];
    int AvgRuns;
    int runs;
    int overs,wickets;
    int bowlingruns;
};
int main()
{
    int i,j,ch,sum1=0,sum2=0;
    int wickets1=0,wickets2=0;
    int overs1=0,overs2=0;
    int a=2,b=11;
    struct team teams[a];
    struct player players[2][b];
    printf("----------------------------------------------------------------------------\n");
    printf("                                SRM CRICKET                                 \n");
    printf("1.NEW SCORESHEET\n");
    printf("2.VIEW SCORE SHEET\n");
    printf("3.EXIT\n");
    printf("ENTER THE OPTION:");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
        for(i=0;i<2;i++)
        {
             printf("TEAM %d:\n",i+1);
             printf("ENTER TEAM NAME:\n");
             scanf("%s",teams[i].teamname);

             for(j=0;j<11;j++)
             {
                  if(i==0)
                  {
                      if(j==0)
                      {
                          names=fopen("Scoresheet.csv", "w");
                          fputs(teams[i].teamname,names);
                          fputs("\n",names);
                          fputs("Player Name\t",names);
                          fputs("Player Role\t",names);
                          fputs("AVG Runs\n",names);
                      }
                      
                      names=fopen("Scoresheet.csv", "a");
                      printf("PLAYER %d:\n",j+1);
                      printf("ENTER PLAYER NAME:\n");
                      scanf("%s",players[i][j].playername);
                      fputs(players[i][j].playername,names);
                      fputs("\t",names);
                      printf("ENTER PLAYER ROLE:\n");
                      scanf("%s",players[i][j].playerrole);
                      fputs(players[i][j].playerrole,names);
                      fputs("\t",names);
                      printf("Enter THE AVG RUNS:\n");
                      scanf("%d",&players[i][j].AvgRuns);
                      fprintf(names, "%d",players[i][j].AvgRuns);
                      fputs("\n",names);
                  }
                  else
                  {
                        if(j==0)
                      {
                          names=fopen("Scoresheet.csv", "a");
                          fputs(teams[i].teamname,names);
                          fputs("\n",names);
                          fputs("Player Name\t",names);
                          fputs("Player Role\t",names);
                          fputs("AVG Runs",names);
                          fputs("\n",names);
                      }
                      
                      names=fopen("scoresheet.csv", "a");
                      printf("PLAYER %d:\n",j+1);
                      printf("ENTER PLAYER NAME:\n");
                      scanf("%s",players[i][j].playername);
                      fputs(players[i][j].playername,names);
                      fputs("\t",names);
                      printf("ENTER PLAYER ROLE:\n");
                      scanf("%s",players[i][j].playerrole);
                      fputs(players[i][j].playerrole,names);
                      fputs("\t",names);
                      printf("Enter THE AVG RUNS:\n");
                      scanf("%d",&players[i][j].AvgRuns);
                      fprintf(names, "%d",players[i][j].AvgRuns);
                      fputs("\n",names);
                  }

                  }
             }
            for ( i = 0; i < 2; i++)
            {
                for ( j = 0; j < 11; j++)
                {
                    if(i==0)
                    {
                        if(j==0){
                        printf("\t\t\t\t\t\t");
                        puts(teams[i].teamname);
                        printf("\n");
                        printf("Name\t\tRole\t\tAVG Runs\n");
                        
                        }
                        
                        printf("%s\t\t%s\t\t%d\n",players[i][j].playername,players[i][j].playerrole,players[i][j].AvgRuns);
                        

                    }
                    if(i==1)
                    {
                         if(j==0){
                        printf("\t\t\t\t\t\t");
                        puts(teams[i].teamname);
                        printf("\n");
                        printf("Name\t\tRole\t\tAVG Runs\n");
                        
                        }
                        
                        printf("%s\t\t%s\t\t%d\n",players[i][j].playername,players[i][j].playerrole,players[i][j].AvgRuns);
                    }
                   
                }
                
            }
            printf("\t\t\t..............INNINGS 1...................\n");
            fputs("\n\nINNINGS 1...........\n",names);
            fputs("\nBatting Team:\t",names);
            fputs(teams[0].teamname,names);
            fputs("\nPlayer Name\t",names);
            fputs("Runs\n",names);
            printf("%s\n",teams[0].teamname);
                for ( j = 0,i=0; j <11;j++)
                {
                    printf("%s\n",players[i][j].playername);
                    fputs(players[i][j].playername,names);
                    fputs("\t",names);
                    printf("Enter the no.of Runs: ");
                    scanf("%d",&players[i][j].runs);
                    sum1=sum1+players[i][j].runs;
                    fprintf(names,"%d\n",players[i][j].runs);
                }
                printf("Enter the bowlers of %s team\n",teams[1].teamname);
                fputs("\nBowlers team :\t",names);
                fputs(teams[1].teamname,names);
                fputs("\nBowler Name\tRuns\tOvers\tWickets\n",names);
                 for ( j = 0,i=1; j <11;j++)
                {
                    printf("%s\n",players[i][j].playername);
                    fputs(players[i][j].playername,names);
                    fputs("\t",names);
                    printf("Enter the no.of given Runs: ");
                    scanf("%d",&players[i][j].bowlingruns);
                    fprintf(names,"%d\t",players[i][j].bowlingruns);
                    printf("Enter the no.of overs: ");
                    scanf("%d",&players[i][j].overs);
                    overs1=overs1+players[i][j].overs;
                    fprintf(names, "%d\t",players[i][j].overs);
                    printf("Enter the no.of wickets: ");
                    scanf("%d",&players[i][j].wickets);
                    wickets1=wickets1+players[i][j].wickets;
                    fprintf(names, "%d\n",players[i][j].wickets);
                    
                }
                fputs("Total Score:\t",names);
                fprintf(names, "%d\n",sum1);
                fputs("Total Wickets:\t",names);
                fprintf(names, "%d\n",wickets1);
                fputs("Total Overs:\t",names);
                fprintf(names, "%d\n",overs1);

                printf("\t\t\t..............INNINGS 2...................\n");
            fputs("\n\nINNINGS 2...........\n",names);
            fputs("\nBatting Team:\t",names);
            fputs(teams[1].teamname,names);
            fputs("\nPlayer Name\t",names);
            fputs("Runs\n",names);
            printf("%s\n",teams[1].teamname);
                for ( j = 0,i=1; j <11;j++)
                {
                    printf("%s\n",players[i][j].playername);
                    fputs(players[i][j].playername,names);
                    fputs("\t",names);
                    printf("Enter the no.of Runs: ");
                    scanf("%d",&players[i][j].runs);
                    sum2=sum2+players[i][j].runs;
                    fprintf(names,"%d\n",players[i][j].runs);
                }
                printf("Enter the bowlers of %s team\n",teams[0].teamname);
                fputs("\nBowlers team \t",names);
                fputs(teams[0].teamname,names);
                fputs("\nBowler Name\tRuns\tOvers\tWickets\n",names);
                 for ( j = 0,i=0; j <11;j++)
                {
                    printf("%s\n",players[i][j].playername);
                    fputs(players[i][j].playername,names);
                    fputs("\t",names);
                    printf("Enter the no.of given Runs: ");
                    scanf("%d",&players[i][j].bowlingruns);
                    fprintf(names,"%d\t",players[i][j].bowlingruns);
                    printf("Enter the no.of overs: ");
                    scanf("%d",&players[i][j].overs);
                    overs2=overs2+players[i][j].overs;
                    fprintf(names, "%d\t",players[i][j].overs);
                    printf("Enter the no.of wickets: ");
                    scanf("%d",&players[i][j].wickets);
                    wickets2=wickets2+players[i][j].wickets;
                    fprintf(names, "%d\n",players[i][j].wickets);
                    
                }
                fputs("Total Score:\t",names);
                fprintf(names, "%d\n",sum2);
                fputs("Total Wickets:\t",names);
                fprintf(names, "%d\n",wickets2);
                fputs("Total Overs:\t",names);
                fprintf(names, "%d\n",overs2);
                
            printf("\t\t\t..............INNINGS...1\n");
            printf("Batting Team : %s\n",teams[0].teamname);
            printf("Name\t\tRuns\n");
            for(j = 0,i=0; j <11;j++)
            {
                 printf("%s\t\t",players[i][j].playername);
                 printf("%d\n",players[i][j].runs);
            }
            printf("Bowling Team : %s\n",teams[1].teamname);
            printf("Name\t\tRuns\twickets\tovers\n");
            for(j = 0,i=1; j <11;j++)
            {
                 printf("%s\t\t",players[i][j].playername);
                 printf("%d\t",players[i][j].bowlingruns);
                 printf("%d\t",players[i][j].wickets);
                 printf("%d\n",players[i][j].overs);
            }
            printf("Total score : %d\n",sum1);
            printf("Total Overs: %d\tTotal wickets: %d\n",overs1,wickets1);
             printf("\t\t\t..............INNINGS...2\n");
            printf("Batting Team : %s\n",teams[1].teamname);
            printf("Name\t\tRuns\n");
            for(j = 0,i=1; j <11;j++)
            {
                 printf("%s\t\t",players[i][j].playername);
                 printf("%d\n",players[i][j].runs);
            }
            printf("Bowling Team : %s\n",teams[0].teamname);
            printf("Name\t\tRuns\twickets\tovers\n");
            for(j = 0,i=0; j <11;j++)
            {
                 printf("%s\t\t",players[i][j].playername);
                 printf("%d\t",players[i][j].bowlingruns);
                 printf("%d\t",players[i][j].wickets);
                 printf("%d\n",players[i][j].overs);
            }
            printf("Total score : %d\n",sum2);
            printf("Total Overs: %d\tTotal wickets: %d\n",overs2,wickets2);
            if(sum1>sum2)
            {
                printf("%s Team won the Match\n",teams[0].teamname);
                fputs("\nThe Winner is:\t",names);
                fputs(teams[0].teamname,names);
            }
            else
            {
                printf("%s Team won the Match\n",teams[1].teamname);
                 fputs("\nThe Winner is:\t",names);
                fputs(teams[1].teamname,names);
            }
            break;

            case 2 :
            names=fopen("scoreSheet.csv", "r");
            if(names==NULL)
            {
                printf("Please fill the ScoreSheet\n");
            }
            printf("Please check the file scoreSheet.csv\n");
            break;

            case 3 :printf("Thanks for using this application.");
                    exit(0);
                    break;
            default: printf("Please choose an option from 1 to 3");

        }
    }
