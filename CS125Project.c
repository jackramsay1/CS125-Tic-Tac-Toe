#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define ROWS 100
#define COLUMN 100
void playerGo(int playerPos, char playerLetter, char grid[ROWS][COLUMN]);
int selectPosition(char);


void print_array(char grid[ROWS][COLUMN]);

int testfordraw(char grid[ROWS][COLUMN])
{
	int tie;
	if ((grid[0][5] == 'X' || grid[0][5] == 'O') && 
		(grid[2][5] == 'X' || grid[2][5] == 'O') &&
		(grid[4][5] == 'X' || grid[4][5] == 'O') &&
		(grid[0][10] == 'X'|| grid[0][10] == 'O') && 
		(grid[2][10] == 'X'|| grid[2][10] == 'O') &&
		(grid[4][10] == 'X'|| grid[4][10] == 'O') &&
		(grid[0][14] == 'X'|| grid[0][14] == 'O') &&
		(grid[2][14] == 'X'|| grid[2][14] == 'O') &&
		(grid[4][14] == 'X'|| grid[4][14] == 'O'))
		{
			tie=1;
		}
		
		return tie;
}

int testforwin(char grid[ROWS][COLUMN])//*This function tests for the winner*//
{
    int value;
    if ((grid[0][5] == 'X' && grid[0][10] == 'X' && grid[0][14] == 'X') ||
	(grid[0][5] == 'X' && grid[2][5] == 'X' && grid[4][5] == 'X') ||
	(grid[0][10] == 'X' && grid[2][10] == 'X' && grid[4][10] == 'X') ||
	(grid[0][14] == 'X' && grid[2][14] == 'X' && grid[4][14] == 'X') ||
	(grid[2][5] == 'X' && grid[2][10] == 'X' && grid[2][14] == 'X') ||
	(grid[4][5] == 'X' && grid[4][10] == 'X' && grid[4][14] == 'X') ||
	(grid[0][5] == 'X' && grid[2][10] == 'X' && grid[4][14] == 'X') ||
	(grid[4][5] == 'X' && grid[2][10] == 'X' && grid[0][14] == 'X')) {

	value = 1;
    } else if ((grid[0][5] == 'O' && grid[0][10] == 'O'
	       && grid[0][14] == 'O') || (grid[0][5] == 'O'
	       && grid[2][5] == 'O' && grid[4][5] == 'O')
	       || (grid[0][10] == 'O' && grid[2][10] == 'O'
	       && grid[4][10] == 'O') || (grid[0][14] == 'O'
	       && grid[2][14] == 'O' && grid[4][14] == 'O')
	       || (grid[2][5] == 'O' && grid[0][10] == 'O'
	       && grid[0][14] == 'O') || (grid[4][5] == 'O'
	       && grid[4][10] == 'O' && grid[4][14] == 'O')
	       || (grid[0][5] == 'O' && grid[2][10] == 'O'
	       && grid[4][14] == 'O') || (grid[4][5] == 'O'
	       && grid[2][10] == 'O' && grid[0][14] == 'O')) {
	value = 2;
    } else if (testfordraw(grid)==1){
		value = 3;
	}
	else 
		value = 0;
    return value;
}


//* This function is what is inputed by the player to see where they want to move*//
int selectPosition(char player) {    
	int x;
    int numRead;
    printf("\n");
    scanf("%*c");       //read in \n                                                         
    printf("Enter your position to move(%c): ", player);//*Player is defined in main by O or X*//
    scanf("%d", &x);
    while(x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6 && x!=7 && x!=8 && x!=9){
         printf("Not a valid choice! Choose 1-9\n");
         printf("Enter your position to move(%c): ", player);
      scanf("%*[^\n]");
         scanf("%d", &x);
    }

     return x;
}

void playerGo(int playerPos, char playerLetter, char grid[ROWS][COLUMN]){
  int legalMove = 0;
  int x=0, y=5;
  int pos= playerPos;

  while (legalMove == 0){
	switch (pos) {
	case 1:    //1  =>  grid[0][5]
	   x = 0;
           y = 5;
           break; 
        case 2:    //2 => grid[0][10]
           x = 0;
           y = 10;
           break; 
        case 3:   //3 => grid[0][14]
           x = 0;
           y = 14; 
           break;
	case 4:    //4  =>  grid[2][5]
	  x = 2;
	  y = 5;
	  break;
        case 5:    //5 => grid[2][10]
	  x = 2;
	  y = 10;
	  break;
        case 6:   //6 => grid[2][14]
          x = 2;
	  y = 14;
	  break;
	case 7:   //7  =>  grid[4][5]                                                                       
	  x = 4;
	  y = 5;
	  break;
        case 8:    //8 => grid[4][10]
	  x = 4;
	  y = 10;
	  break;
        case 9:   //9 => grid[4][14]
	  x = 4;
	  y = 14;
	  break;
	}
	if ((grid[x][y] == 'X')||(grid[x][y] == 'O')){
	  printf("This position is taken \n");
          pos=selectPosition(playerLetter);
	}  
        else {
          legalMove = 1; //they went somewhere no one else has gone
	}
	//printf("in while pos=%d\n", pos);
  }
  grid[x][y]= playerLetter;
}



void print_array(char grid[ROWS][COLUMN])
{
    int x;
    for (x = 0; x < 5; x++) {
	printf("%s\n", grid[x]);
    };

}

int main()
{
    int player_count = 2;
    char player;
    char player1;
    char player2;
    int u=0;
    int over=0;
    int v;
    int j;
	int draw;
	

char title1[ROWS][COLUMN] = {

"╭╮╭╮╭╮╱╱╭╮╱╱╱╱╱╱╱╱╱╱╱╱╱",
"┃┃┃┃┃┃╱╱┃┃╱╱╱╱╱╱╱╱╱╱╱╱╱",
"┃┃┃┃┃┣━━┫┃╭━━┳━━┳╮╭┳━━╮",
"┃╰╯╰╯┃┃━┫┃┃╭━┫╭╮┃╰╯┃┃━┫",
"╰╮╭╮╭┫┃━┫╰┫╰━┫╰╯┃┃┃┃┃━┫",
"╱╰╯╰╯╰━━┻━┻━━┻━━┻┻┻┻━━╯",
};


for(j=0; j<=5; j++){
printf("%s", title1[j]);
printf("\n");
}
printf("\n");


char title2[ROWS][COLUMN] = {

" ╭╮╱╱╱╱",
"╭╯╰╮╱╱╱",
"╰╮╭╋━━╮",
" ┃┃┃╭╮┃",
" ┃╰┫╰╯┃",
"╱╰━┻━━╯",
};

for(j=0; j<=6; j++){
printf("%s", title2[j]);
printf("\n");
}
printf("\n");


char title3[ROWS][COLUMN] = {

"╭━━━━╮╱╱╱╭━━━━╮╱╱╱╭━━━━╮     ",
"┃╭╮╭╮┃╱╱╱┃╭╮╭╮┃╱╱╱┃╭╮╭╮┃     ",
"╰╯┃┃┣╋━━╮╰╯┃┃┣┻━┳━┻┫┃┃┣┻━┳━━╮",
"╱╱┃┃┣┫╭┳┻━╮┃┃┃╭╮┃╭━╯┃┃┃╭╮┃┃━┫",
"╱╱┃┃┃┃╰┻┳━╯┃┃┃╭╮┃╰━╮┃┃┃╰╯┃┃━┫",
"╱╱╰╯╰┻━━╯╱╱╰╯╰╯╰┻━━╯╰╯╰━━┻━━╯",
};

for(j=0; j<=6; j++){
printf("%s", title3[j]);
printf("\n");
}
printf("\n");
    FILE *Record = fopen("GameRecord.txt", "a");//*Write to the file the winning games*//
    
    if (player_count == 2) {
	    printf("Welcome to Tic Tac Toe!\n");
	    printf("Player 1 choose x or o:\n");
	    scanf("%s", &player1);
	    while (player1 != 'x' && player1 != 'o') {
		printf("Enter only x or o\n");
		scanf("%*c");	//read in \n
		printf("Choose x or o.\n");
		scanf("%s", &player1);
	
	    }
	    if (player1 == 'x') {
		player2 = 'o';
		printf("Player 1 is x\n");
		printf("Player 2 is o\n");
	    } else if (player1 == 'o') {
		player2 = 'x';
		printf("Player 1 is o\n");
		printf("Player 2 is x\n");
	    }
    }
	    char grid[ROWS][COLUMN] = {
		"     1  | 2 | 3",
		" -------------------",
		"     4  | 5 | 6",
		" -------------------",
		"     7  | 8 | 9",
	    };
	    printf("\n");
while(u!=1 && u!=2){
	    while (over !=1 && over!=2) {
		print_array(grid);
		int pos = selectPosition('X'); //playerinput(grid);
		playerGo(pos, 'X', grid);
                print_array(grid); 
		printf("\n");
		over = testforwin(grid);//** Over is defined in the testforwin function**//
		if (over == 1) {
		    printf("Player X won\n");
		    print_array(grid);
		    break;
		} else if (over == 2) {
		   printf("Player O won\n");
		    print_array(grid);
		    break;
		}
		else if(over ==3){
			printf("Tie Game!\n");
			print_array(grid);
			break;
		}
                pos=selectPosition('O');
		playerGo(pos, 'O', grid);
                //print_array(grid);
		printf("\n");
		over = testforwin(grid);
		if (over == 1) {
		    printf("Player X won\n");
		    print_array(grid);
		    break;
		} else if (over == 2) {
		    printf("Player O won\n");
		    print_array(grid);

		    break;
		} else if(over==3){
			printf("Tie game!\n");
			print_array(grid);
			break;
		}
		
	    }




        int x;
        fprintf(Record,"\n");
	    for (x=0; x < 5; x++) {
		fprintf(Record, "%s\n", grid[x]);//** This prints the grid on the file I/O**//
	    }
	   
	printf("Would you like to play again? (1)yes (2)no ");//** Reprompt to play again**//
	scanf("%d", &v);
	if (v==1){
	    u=0;
	    over=0;
	}
	else if(v==2){
		printf("the game is now over");
	break;
	}
	
		
	
        strcpy(grid[0], "     1  | 2 | 3");//**Reprints the original grid**//
        strcpy(grid[1], " -------------------");
        strcpy(grid[2], "     4  | 5 | 6");
        strcpy(grid[3], " -------------------");
        strcpy(grid[4], "     7  | 8 | 9" );

	
	}
	

    
    fclose(Record);

    return 0;
}
