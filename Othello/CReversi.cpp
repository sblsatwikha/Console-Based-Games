#include "Headers.h"


void main(){
	
	int rows = 4, cols = 4;

	char table1[4][5] =
	{
		"    ",
		" wb ",
		" bw ",
		"    "
	};

	char player1[20], player2[20];
	scanf("%s%s", player1, player2);

	//Create a game using  createNewGame(int,int,char *,char *) with rows,cols and  two players
	ReversiGame *game = createNewGame(rows, cols, player1, player2);

	//Initalize the game with table ,Pass it as (char *)table along with the turn
	initializeReversiGame(game, (char *)table1, rows, cols, 1);

	//First Clear and Redraw the Screen
	clearAndRedrawScreen(game);

	//Use a Loop which repeatedly takes input(Reversi Move) from User and calls playMove function. Till the Game is Ended
	while (checkReversiGameOver(game))
	{
		ReversiMove *move = inputMove(game);
		playMove(game, move);
		clearAndRedrawScreen(game);
	}

}


