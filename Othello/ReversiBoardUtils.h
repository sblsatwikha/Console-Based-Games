typedef struct ReversiGame {
	char **board;	// char 'w' for whites, 'b' for blacks ' ' for empty 
	// do allocate memory for '\0' as it is character array.
	char *player1name;
	char *player2name;
	int whiteCount = 0;
	int blackCount = 0;
	int NumberofMoves = 0;
	int rows, cols;
	int turn = 1;   //1 for white, -1 for black
	int state = 0;  //0 for unfinished, 1 for game over
	int winner = 0; //1 for white, -1 for black
}ReversiGame;


void endGame(ReversiGame *game);
int hasMove(ReversiGame *game);
void modifyTurn(ReversiGame *game);


ReversiGame * createNewGame(int rows, int cols, char *player1, char *player2) {
	if (rows <= 0 || cols <= 0 || rows != cols || player1 == NULL || player2 == NULL)
	{
		return NULL;
	}
	ReversiGame *game = (ReversiGame *)malloc(sizeof(ReversiGame));
	char **firstIndexArray = (char **)malloc(sizeof(char *)*rows);
	for (int i = 0; i < rows; i++)
	{
		firstIndexArray[i] = (char *)malloc(sizeof(char)*(cols + 1));
	}
	game->board = firstIndexArray;
	game->player1name = player1;
	game->player2name = player2;
	game->rows = rows;
	game->cols = cols;
	game->NumberofMoves = 0;
	game->state = 0;
	game->turn = 1;
	game->winner = 0;
	game->whiteCount = 0;
	game->blackCount = 0;
	return game;
}


//Copy the tobeCopied Array into game->board .
void initializeReversiGame(ReversiGame *game, char *tobeCopiedBoard, int rows, int cols, int turn) {
	if (game != NULL&& tobeCopiedBoard != NULL && (turn == -1 || turn == 1))
	{
		game->state = 0;
		game->winner = 0;
		game->whiteCount = 0;
		game->blackCount = 0;
		game->turn = turn;
		int j, k = 0;
		for (int i = 0; i < rows; i++)
		{
			for (j = 0; j <= cols; j++)
			{
				if (tobeCopiedBoard[k] == 'w')
				{
					game->whiteCount = (game->whiteCount) + 1;
				}
				else if (tobeCopiedBoard[k] == 'b')
				{
					game->blackCount = (game->blackCount) + 1;
				}
				*(*(game->board + i) + j) = tobeCopiedBoard[k];
				k++;
			}
		}
		if ((game->blackCount + game->whiteCount) == (game->rows*game->cols) || (game->blackCount == 0) || (game->whiteCount == 0))
		{
			endGame(game);
		}
		if (hasMove(game) == 0)
			modifyTurn(game);
	}
}

/*
Check if the Current board is in End Position . Return 0 if the game is Ended, 1 if not .
Win Condition : Either all the squares are filled or a stalemate position (No one can Move)
*/

int checkReversiGameOver(ReversiGame *game){
	if (((game->blackCount + game->whiteCount) == (game->rows*game->cols)) || game->blackCount == 0 || game->whiteCount == 0)
	{
		endGame(game);
		return 0;
	}
	if (hasMove(game) == 0)
	{
		if (hasMove(game) == 0)
		{
			endGame(game);
			return 0;
		}
	}
	return 1;
}


/*
Sample output :
Game Turn: White
Whites Count : 5
Black Count : 4
Move Count : 9
*/
void printMoves(ReversiGame *game){
	if (game->turn == 1)
		printf("Game Turn: White\n");
	else if (game->turn == -1)
		printf("Game Turn: Black\n");
	printf("Whites Count : %d\n", game->whiteCount);
	printf("Black Count : %d\n", game->blackCount);
	printf("Move Count : %d\n", (game->whiteCount + game->blackCount));
	return;
}


void drawBoardOnScreen(ReversiGame *game) {
	for (int i = 0; i < game->rows; i++)
	{
		for (int j = 0; j < game->cols; j++)
		{
			char c = *(*(game->board + i) + j);
			if (c == ' ')
			{
				c = '.';
			}
			printf("%c\t", c);
		}
		printf("\n");
	}
	printMoves(game);
	return;
}


void clearScreen(ReversiGame *game){
	system("cls");
}


void clearAndRedrawScreen(ReversiGame *game){
	clearScreen(game);
	drawBoardOnScreen(game);
}


