#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"

int grid;
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';


void resetBoard();
void print_grid();
int checkFreeSpaces();
void player1Move();
void player2Move();
char row_covered();
void printWinner(char);


int main() {
  printf("Welcome!\n");
  printf("Enter board size: ");
  scanf("%d",&grid);
  char board[grid][grid];

  void resetBoard()
  {
    for (int i = 0; i < grid; i++)
    {
      for (int j = 0; j < grid; j++)
      {
        board[i][j] = '-';
      }
    }
  }

  int checkFreeSpaces()
  {
    int freeSpaces = pow(grid,2);

    for (int i = 0; i < grid; i++) {
      for (int j = 0; j < grid; j++) {
        if (board[i][j] != '-') {
          freeSpaces--;
        }
      }
    }
    return freeSpaces;
  }
  void player1Move()
  {
    int x;
    int y;

    do {
      printf("\nPlayer 1 - Place mark (x,y): ");
      scanf("%d,%d",&x,&y );
      x--;
      y--;

      if(board[x][y] != '-')
      {
        printf("Invalid move!\n");
      }
      else{
        board[x][y] = PLAYER1;
        break;
      }
    } while(board[x][y] != '-');
  }
  void player2Move()
  {
    int x;
    int y;

    do {
      printf("Player 2 - Place mark (x,y): ");
      scanf("%d,%d",&x,&y );
      x--;
      y--;

      if(board[x][y] != '-')
      {
        printf("Invalid move!\n");
      }
      else{
        board[x][y] = PLAYER2;
        break;
      }
    } while(board[x][y] != '-');
  }
  void print_grid()
  {
    for (size_t i = 0; i < grid; i++)
    {
      for (size_t j = 0; j < grid; j++) {
      printf("%c ",board[i][j] );
      }
      printf("\n");
    }

  }
  char row_covered()
  {
    int y = 0;
    int z = 0;
    int x = 0;
    int o = 0;
    //check rows
    for (int row = 0; row < grid; row++) {
      x = 0;
      o = 0;
      for (int col = 0; col < grid; col++) {
        if (board[row][col] == PLAYER1) {
          x++;}
          else{
            if (board[row][col] == PLAYER2) {
              o++;
            }
          }
          if (x == grid) {
            return PLAYER1;
          }
          else{
            if (o == grid) {
              return PLAYER2;
            }}
        }
      }

    //check coloumns
    for (int col = 0; col < grid; col++) {
      y = 0;
      z = 0;
      for (int row = 0; row < grid; row++) {
        if (board[row][col] == PLAYER1) {
          y++;}
          else{
            if (board[row][col] == PLAYER2) {
              z++;
            }
          }
          if (y == grid) {
            return PLAYER1;}
            else{
              if (z == grid) {
                return PLAYER2;}
            }
          }
        }

    //check diagonals
    int isEqual = 1;
    int isEqual2 = 1;

    for (int index = 0; index < grid; index++ )
    { if (board[index][index] != board[0][0])
      {
        isEqual = 0;
      }
    }
    if (isEqual == 1) {
      return board[0][0];
    }
    for (size_t j = grid-1,i = 0; i < grid; j--,i++) {
      if (board[j][i] != board[grid-1][0]) {
        isEqual2 = 0;
      }
    }
    if (isEqual2 == 1) {
      return board[grid-1][0];
    }

    return '-';
  }
  void printWinner(char winner)
  {
     if(winner == PLAYER1)
     {
       printf("Player 1 wins!");
     }
     else if (winner == PLAYER2)
     {
       printf("Player 2 wins!");
     }
     else
     {
       printf("It's a draw");
     }
  }
  char winner = '-';

  resetBoard();
  while (winner == '-' && checkFreeSpaces()!= 0) {
    print_grid();
    player1Move();
    winner = row_covered();
    if (winner != '-' || checkFreeSpaces() == 0) {
      break;
    }
    print_grid();
    player2Move();
    winner = row_covered();
    if (winner != '-' || checkFreeSpaces() == 0) {
      break;
    }
  }
  print_grid();
  printWinner(winner);

  return 0;
}
