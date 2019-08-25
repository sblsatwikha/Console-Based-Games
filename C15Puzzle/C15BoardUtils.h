

//Board Struct which holds all the data of the Puzzle
typedef struct Board {
	//Stores the Actual table of all values ,which are being displayed
	int **table;

	//No of rows of Table
	int rows;

	//No of cols of Table
	int cols;

	//Row postion of the emptyTile ie the 0's row position in table,ie if table[2][4] is 0,emptyTileRow will be 2
	int emptyTileRow;

	//Col postion of the emptyTile ie the 0's col position in table,ie if table[2][4] is 0,emptyTileCol will be 4
	int emptyTileCol;
}Board;


Board * createBoard(int rows, int cols){
	if (rows <= 0 || cols <= 0)
	{
		return NULL;
	}
	Board *board = (Board*)malloc(1 * sizeof(Board));
	int **arr = (int**)malloc(rows*sizeof(int*));
	for (int i = 0; i < rows; i++)
	{
		arr[i] = (int*)malloc(cols*sizeof(int));
	}
	board->table = arr;
	board->rows = rows;
	board->cols = cols;
	board->emptyTileRow = 0;
	board->emptyTileCol = 0;
	return board;
}


void initializeBoard(Board * source, int *tobeCopiedArray, int rows, int cols){
	if (rows <= 0 || cols <= 0)
	{
		return;
	}
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			source->table[i][j] = tobeCopiedArray[k];
			if (tobeCopiedArray[k] == 0)
			{
				source->emptyTileRow = i;
				source->emptyTileCol = j;
			}
			k += 1;
		}
	}
	source->rows = rows;
	source->cols = cols;
}

//Check if the Current board is in Win / Loss Condition . Return 1 if it is Win conditon , 0 if not .
int checkBoard(Board * board){
	int k = 1;
	for (int i = 0; i < board->rows; i++)
	{
		for (int j = 0; j < board->cols&&k<board->rows*board->cols; j++)
		{
			if (k != board->table[i][j])
				return 0;
			k++;
		}
	}
	if (board->table[board->rows - 1][board->cols - 1] == 0)
		return 1;
}



void drawBoardOnScreen(Board *board){

	/*
	Example  : Print the current board like
	1  2  3  4
	5  6  7  8
	9 10 11 12
	13 14  0 15
	----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------
	*/
	for (int k = 0; k < board->rows; k++)
	{
		for (int j = 0; j < board->cols; j++)
		{
			printf("%d  ", board->table[k][j]);
		}
		printf("\n");
	}
	printf("----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------\n");

}


void clearScreen(){
	system("cls");
}


void clearAndRedrawScreen(Board * board){
	clearScreen();
	drawBoardOnScreen(board);
}
