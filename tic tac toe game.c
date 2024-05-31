#include <stdio.h>

void print_board(char board[3][3]) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("[%c]", board[i][j]);
    }
    printf("\n");
  }
}

int insert(char player, char board[3][3]) {
  int row, col;

  do {
    printf("Player %c turn. Enter row (1-3) and column (1-3): ", player);
    scanf("%d %d", &row, &col);

    row--;
    col--;
  } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');


  board[row][col] = player;

  return 1;
}

int checkWin(char player, char board[3][3]) {

  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }
  return 0;
}

int checkboardspace(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  char board[3][3];
  char player = 'X';
  int gameOver = 0;


  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }

  while (!gameOver) {
    print_board(board);


    if (!insert(player, board)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }


    if (checkWin(player, board)) {
      gameOver = 1;
      printf("Player %c wins!\n", player);
      print_board(board);
    }

    player = (player == 'X') ? 'O' : 'X';


    if (!gameOver && checkboardspace(board)) {
      gameOver = 1;
      printf("It's a draw!\n");
    }
  }

  return 0;
}
