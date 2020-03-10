#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define QNO 30
#define totques 10
#define size 200
struct Player {
  char name[20];
  int points;
};
int MAX;
void show_record();
void reset_score();
void analysis();
void addtoscoreboard(float , char []);
void sortScoreboard();
void asked(char option[size], const char option1[size], const char option2[size],
	const char option3[size], const char option4[size],const char correct[size], const char category[size],FILE * fp,int *);

void edit_score(float , char []);
int main()
     {
         char text[size],option1[size], option2[size], option3[size], option4[size], option[size], correct[size], category[size];
	char empty[256][256];
	int i,j,k;
	int arr[QNO],x,loc;
	time_t t;
	char line[256];
	int score=0;


    FILE * fp;
    FILE * output;

     int countr,r,r1,count,n;
     float sco;
     char choice;
     char playername[20];

     mainhome:
     system("cls");



     printf("\n\t\t\t      TAKE YOUR DSA TEST ");

     printf("\n\t\t  BASED ON DATA STRUCTURES AND ALGORITHMS  ") ;

     printf("\n\t\t Press S to start the test");
     printf("\n\t\t Press V to view the highest score  ");
     printf("\n\t\t Press B to view the scoreboard  ");
     printf("\n\t\t Press R to reset score");
     printf("\n\t\t Press A to view analysis");

     printf("\n\t\t Press Q to quit ");


     choice=toupper(getch());
     if (choice=='V')
	{
	show_record();
	goto mainhome;
	}
	 else if (choice=='B')
	{
	sortScoreboard();
	goto mainhome;
	}
else if (choice=='A')
	{
	analysis();
	goto mainhome;
	}
	else if (choice=='R')
	{reset_score();
	getch();
	goto mainhome;}
	else if (choice=='Q')
	exit(1);
    else if(choice=='S')
    {
     system("cls");

    printf("\n Register your name:");
    scanf("%s",playername);
    printf("\n  %s you are ready to start ",playername);
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D ");
    printf("\n\n\n Press any key to start the game!\n");


     if(toupper(getch())=='H')
		{goto game;}
game:

    fp = fopen("Quiz.txt","r");
    output = fopen("NewText.txt","w");
    if(fp == NULL)
    {
    	printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
		printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
	}
	k = 0;

	for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}

	for (j = 0; j < totques; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);

			}

				if(i==2)
				{
					fputs(line,output);
				}

				if(i == 3)
			strncpy(option1,line,30);

				if(i == 4)
			strncpy(option2,line,30);

				if(i == 5)
			strncpy(option3,line,30);

				if(i == 6)
			strncpy(option4,line,30);

			if (i >1&&i<=7)
			{
				printf("%s",line);

			}
			if (i == 8)
			strncpy(correct,line,30);

			if (i == 9)
			strncpy(category,line,30);
		}


		asked(option, option1, option2, option3, option4, correct, category,output,&score);

		if(j!=9)
		{

		if (arr[loc] + 10 < arr[3 * (j + 1)])
		  {
			for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
			fgets(empty[k],sizeof(empty[k]),fp);
				k++;
			}
		  }
		}


		system("cls");
	}

	fprintf(output," \n You got total %d out of 40 ",score);
	sco=(float)score;
	edit_score(sco,playername);
	addtoscoreboard(sco,playername);


	fclose(fp);

	fclose(output);

	output = fopen("Newtext.txt","r");

	while(fgets(line,sizeof(line),output))
	{
		printf(" %s",line);
	}

	fclose(output);
	system("pause");
}
goto mainhome;}



	void asked(char option[size], const char option1[size], const char option2[size], const char option3[size], const char option4[size],
	 const char correct[size], const char category[size],FILE * fp,int *score)
	{
		printf("Your Option : ");
		scanf("%str",&option[0]);
		option[1] = '\0';
		strupr(option);

			char correctanswer[size];
			char wronganswer[size];

			fprintf(fp,"%s \n",category);

		if (option[0] == correct[0])
		{
			if (option[0] == option1[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option1);
			if (option[0] == option2[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option2);
			if (option[0] == option3[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option3);
			if (option[0] == option4[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option4);

				*score += 4;

			fprintf(fp," \n You are awarded 4 marks for this correct answer \n ");
		}
		else
		{

			if (correct[0] == option1[0])
				strncpy(correctanswer, option1,24);
			if (correct[0] == option2[0])
				strncpy(correctanswer, option2,24);
			if (correct[0] == option3[0])
				strncpy(correctanswer, option3,24);
			if (correct[0] == option4[0])
				strncpy(correctanswer, option4,24);

			correctanswer[24] = '\0';

			if (option[0] == option1[0])
				strncpy(wronganswer, option1,24);
			if (option[0] == option2[0])
				strncpy(wronganswer, option2,24);
			if (option[0] == option3[0])
				strncpy(wronganswer, option3,24);
			if (option[0] == option4[0])
				strncpy(wronganswer, option4,24);

			wronganswer[24] = '\0';

			fprintf(fp," You entered     : %s \n", wronganswer);
			fprintf(fp," Correct answer  : %s \n", correctanswer);
			fprintf(fp," \n You are awarded 0 marks for this wrong answer \n ");
		}

			fprintf(fp," _____________________________________________________________________________\n");
			fprintf(fp," \n");
	}
void show_record()
    {system("cls");
	char name[20];
	float scr;
	FILE *f;
	f=fopen("score.txt","r");
	if(f==NULL)
	printf("No one has played yet. Start playing to set a new high score!");
	else{
	fscanf(f,"%s%f",&name,&scr);
	printf("\n\n\t\t %s has secured the Highest Score %0.2f",name,scr);
    fclose(f);}
	getch();}

void reset_score()
    {system("cls");
    float sc;
	char nm[20];
	FILE *f;
	remove("score.txt");
	}


void edit_score(float score, char plnm[20])
	{system("cls");
	float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&nm,&sc);
	if (score>=sc)
	  { sc=score;
	    fclose(f);
	    f=fopen("score.txt","w");
	    fprintf(f,"%s\n%.2f",plnm,sc);
	    fclose(f);}}

void addtoscoreboard(float numberOfGuesses, char name[20])
{
    FILE *outfile;
    outfile = fopen ("scoreboard.dat", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }

    struct Player player;
    player.points = numberOfGuesses;
    strcpy(player.name, name);

    fwrite (&player, sizeof(struct Player), 1, outfile);


    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

    fclose (outfile);

}


void sortScoreboard()
{
    system("cls");
    FILE *infile;
    struct Player player;
    infile = fopen ("scoreboard.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    int n=0;
    int p[20];
    char name[20][20];
    int temp;
    int tem[20];

    while(fread(&player, sizeof(struct Player), 1, infile)==1)
        {strcpy(name[n],player.name);
        p[n]=player.points;
        n++;}

    fclose(infile);

   for (int i = 0; i < n-1; i++)
       for (int j = 0; j < n-i-1; j++)
           {if (p[j] > p[j+1])
              {
                  temp = p[j];
                  p[j] = p[j+1];
                  p[j+1] = temp;
                  strcpy(tem,name[j]);
                  strcpy(name[j],name[j+1]);
                  strcpy(name[j+1],tem);
              }}
                 printf("\n\t\t    THE SCOREBOARD") ;
int k=1;
for (int i = n-1; i >= 0; i--)
{
printf("\n%dth position-->",k);
printf("name: %s, points: %d\n",name[i],p[i]);
k++;
}
getch();
}

void analysis()
{
    system("cls");
    FILE *infile;
    struct Player player;
    infile = fopen ("scoreboard.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    int n=0;
    int p[20];
    char name[20][20];
    int temp;
    int tem[20];
    float avg;
    int sum=0;
    float x;
    while(fread(&player, sizeof(struct Player), 1, infile)==1)
        {strcpy(name[n],player.name);
        p[n]=player.points;
        n++;}

    fclose(infile);

   for (int i = 0; i < n; i++)
   {
       sum=sum+p[i];
   }
   avg=sum/n;


                 printf("\n\t\t    The Average score is: %f",avg) ;
                 printf("\n\t\t Enter the passing mark: ");
                 scanf("%f",&x);
printf("\n\t\t List of students who passed:\n");
for (int i = n-1; i >= 0; i--)
{
if(p[i]>=x)
    printf("name: %s, marks: %d\n",name[i],p[i]);
}
printf("\n\t\t List of students who failed:\n");
for (int i = n-1; i >= 0; i--)
{
if(p[i]<x)
    printf("name: %s, marks: %d\n",name[i],p[i]);
}
getch();
}

