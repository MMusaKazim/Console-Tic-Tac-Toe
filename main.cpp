#include <iostream>
#include <conio.h>
#include <windows.h>

int fill = 0;
char arr[9] = {
	'1', '2', '3',
	'4', '5', '6',
	'7', '8', '9'
};

void EndGame();
void gotoxy(short, short);
void Mark(int, int);
void Draw();
void CheckWin();


int main() {
	int player_one = 1;
	int player_two = 2;
	int input = 0;
	int loop = 1;
	while (1) {
		Draw();
		do {
			std::cout << "\n\tPlayer 1 : ";
			std::cin >> input;
			if (input >= 1 && input <= 9) {
				loop = 0;
			}else
				std::cout << "\n\tEnter a number Between 1 - 9";
		} while (loop == 1);
	
		Mark(player_one, input);
		Draw();
		CheckWin();
		
		loop = 1;
		do {
			std::cout << "\n\tPlayer 2 : ";
			std::cin >> input;
			if (input >= 1 && input <= 9) {
				loop = 0;
			}
			else
				std::cout << "\n\tEnter a number Between 1 - 9";
		} while (loop == 1);

		Mark(player_two, input);
		Draw();
		CheckWin();

	}
	return 0;
}



void EndGame() {
	std::cout << "\n\n\tThank You For Playing.\n\t< A game by M Musa Kazim >\n\n";
	exit(1);
}
void gotoxy(short x, short y) {
	COORD coord{};
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(handle, coord);
}
void Mark(int player, int locv) {
	int loc = locv - 1;
	if (player == 1) {
		if ((arr[loc] != 'X') && (arr[loc] != 'O')) {
			arr[loc] = 'X';
		}
	}
	else if (player == 2) {
		if ((arr[loc] != 'X') && (arr[loc] != 'O')) {\
			arr[loc] = 'O';
		}
	}
	else
		std::cout << "\n\tInvalid Player.";
	fill++;
}
void Draw() {
	gotoxy(0, 0);
	std::cout << "\tWelcome to Tic Tac Toe\n\n";
	int i = 0;
	for (int row = 0; row <= 2; row++) {
		for (int column = 0; column <= 2; column++) {
			std::cout <<"\t"<< arr[i];
			i++;
			if(column < 2)
			std::cout << " |";
		}
		
		std::cout << "\t\n";
		std::cout << "\t--------------------\n";
	
	}
}

void CheckWin() {
	//Player 1 Row win Check
	if (arr[0] == 'X' && arr[1] == 'X' && arr[2] == 'X') {
		std::cout << "Player 1 Wins";
		EndGame();
	} else if (arr[3] == 'X' && arr[4] == 'X' && arr[5] == 'X') {
		std::cout << "Player 1 Wins";
		EndGame();
	}else if (arr[6] == 'X' && arr[7] == 'X' && arr[8] == 'X') {
		std::cout << "Player 1 Wins";
		EndGame();
	}
	//player 1 Column Win Check
	else if (arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X') {
		std::cout << "Player 1 Wins";
		EndGame();
	}
	else if (arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X') {
		std::cout << "Player 1 Wins";
		EndGame();
	}
	else if (arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X') {
		std::cout << "Player 1 Wins";
		EndGame();
	}
	//Player 1 Diagonal Win Check 
	else if (arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X') {
		std::cout << "Player 1 Wins";
		EndGame();
	}
	else if (arr[2] == 'X' && arr[4] == 'X' && arr[6] == 'X') {
		std::cout << "Player 1 Wins";
		EndGame();
	}
	
	// Player 2 Row Win Check
	else if (arr[0] == 'O' && arr[1] == 'O' && arr[2] == 'O') {
		std::cout << "Player 2 Wins";
		EndGame();
	}
	else if (arr[3] == 'O' && arr[4] == 'O' && arr[5] == 'O') {
		std::cout << "Player 2 Wins";
		EndGame();
	}
	else if (arr[6] == 'O' && arr[7] == 'O' && arr[8] == 'O') {
		std::cout << "\t < Player 2 Wins >";
		EndGame();
	}
	//Player 2 Column Win Check
	else if (arr[0] == 'O' && arr[3] == 'O' && arr[6] == 'O') {
		std::cout << "Player 2 Wins";
		EndGame();
	}
	else if (arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O') {
		std::cout << "Player 2 Wins";
		EndGame();
	}
	else if (arr[2] == 'O' && arr[5] == 'O' && arr[8] == 'O') {
		std::cout << "Player 2 Wins";
		EndGame();
	}
	//Player 2 Diagonal Win Check
	else if (arr[0] == 'O' && arr[4] == 'O' && arr[8] == 'O') {
		std::cout << "Player 2 Wins";
		EndGame();
	}
	else if (arr[2] == 'O' && arr[4] == 'O' && arr[6] == 'O') {
		std::cout << "Player 2 Wins";
		EndGame();
	}

	//Draw Check
	else {
		if (fill == 9) {
			std::cout << "\t< Match Draw >";
			EndGame();
		}
	}

}