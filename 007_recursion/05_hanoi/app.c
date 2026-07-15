#include <stdio.h>

// online game - https://www.mathsisfun.com/games/towerofhanoi.html
int MOVES_COUNT = 0;

void hanoi(int n, int from, int to, int temp)
{
  if (n == 1) {
    printf("Move from %d to %d\n", from, to);
    MOVES_COUNT++;
    return;
  }
  hanoi(n-1, from, temp, to);
  hanoi(1, from, to, temp);
  hanoi(n-1, temp, to, from);
}

int main()
{
  int n;
  if (scanf("%d",&n) != 1) {
    fprintf(stderr, "invalid input\n");
    return 1;
  }
  hanoi(n, 1, 3, 2);
  printf("Number of moves: %d\n", MOVES_COUNT);
  return 0;
}