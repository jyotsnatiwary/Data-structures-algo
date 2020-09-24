#include <stdio.h>

void swapByValue(int, int);

int main()
{
  int n1 = 10, n2 = 20;

  swapByValue(n1, n2);
  printf("n1: %d, n2: %d\n", n1, n2);
}

void swapByValue(int a, int b)
{
  int t;
  t = a; a = b; b = t;
}
