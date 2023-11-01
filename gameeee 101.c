
//Hi I am Nirjala Prajapati. I am reviewing your code.
#include<stdio.h>
#include<conio.h>
#include<windows.h>
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char n1[50][50],n2[50][50];
int row,column,draw=1;
int gameover();
char player='X';
void layout();
void turn();
void main()
{
	int i,j;
	system("COLOR 1F");
	printf("\n\n\n\n\n\n\n\n\n\t\t W E L C O M E   T O   T I C   T A C   T O E");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n press any key to continue_____");
	getch();
	system("cls");
	system("COLOR 0F");
	printf("Player 1 Please Enter Your Name:");
	gets(*n1);
	printf("Player 2 Please Enter Your Name:");
	gets(*n2);
	    while(gameover())
	    {
	    layout();
	    turn();
	    gameover();
	    layout();
	}
	//for the winner declaration
	if (player=='O'&& draw==1)
	printf("\t\tCONGRATULATIONS %s You win!!\n\t\t Better luck next time %s",*n1,*n2);
	else if(player=='X'&& draw==1)
	printf("\t\tCONGRATULATIONS %s You win!!\n\t\t Better luck next time %s",*n2,*n1);
    else
	printf("\t\tGAME DRAW");
}


//for the display of the play board
void layout()
{
	system("cls");
	printf("\t\t\t T I C  T A C  T O E\n");
     printf(" %s Your symbol is=[X]\n %s Your symbol is=[O]\n",n1,n2);
		printf("\t\t\t      |      |      \n");
	    printf("\t\t\t      |      |      \n");
	    printf("\t\t\t   %c  |   %c  |   %c  \n",board[0][0],board[0][1],board[0][2]);
	    printf("\t\t\t      |      |      \n");
	    printf("\t\t\t______|______|______\n");
	    printf("\t\t\t      |      |      \n");
	    printf("\t\t\t  %c   |   %c  |   %c \n",board[1][0],board[1][1],board[1][2]);
	    printf("\t\t\t      |      |      \n");
	    printf("\t\t\t______|______|______\n");
		printf("\t\t\t      |      |      \n");
		printf("\t\t\t  %c   |   %c  |   %c \n",board[2][0],board[2][1],board[2][2]);
		printf("\t\t\t      |      |      \n");
		printf("\t\t\t      |      |      \n");
		printf("\t\t\t      |      |      \n");

}
void turn()
{
	int choice;
	here:
	if (player=='X')
	{
		system("COLOR 0F");
		printf("It's your turn %s\nPlease enter your choice:",*n1);
	}
	if(player=='O')
	{
		system("COLOR F0");
		printf("It's your turn %s\nPlease enter your choice:",*n2);
	}
	scanf("%d",&choice);

	if(choice > 0 && choice < 10)
	{
		switch(choice)
		{
			case 1:
				row=0;column=0;
				break;
			case 2:
				row=0;column=1;
				break;
			case 3:
				row=0;column=2;
				break;
			case 4:
				row=1;column=0;
				break;
			case 5:
				row=1;column=1;
				break;
			case 6:
				row=1;column=2;
				break;
			case 7:
				row=2;column=0;
				break;
			case 8:
				row=2;column=1;
				break;
			case 9:
				row=2;column=2;
				break;
			default:
				printf("\t\t\tINVALID INPUT\n");
				break;
			}
		}
		else
        {
            printf("INVALID\n");
            goto here;
        }
		if(player=='X'&& board[row][column]!='X' && board[row][column]!='O')
		{
			board[row][column]='X';
			player='O';
		}
		else if(player=='O'&& board[row][column]!='X' && board[row][column]!='O')
		{
			board[row][column]='O';
			player='X';

		}
		else
		{
			printf("\t\t\tBOX ALREADY TAKEN!!! PLEASE TRY AGAIN\n");
			turn();
		}
	}

int gameover()
{
	//check for the win of any player
	int i,j;
	for(i=0;i<3;i++)
	{
		if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]||board[0][i]==board[1][i]&&board[0][i]==board[2][i])
		return 0;
	}
	 if(board[0][0]==board[1][1]&& board[0][0]==board[2][2]||board[0][2]==board[1][1]&& board[0][2]==board[2][0])
		return 0;
	//check if the boxes are filled
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		if(board[i][j]!='X'&&board[i][j]!='O')
		return 1;
}

	draw=0;
	return 0;
}
