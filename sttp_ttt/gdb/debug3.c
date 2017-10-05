#include <stdio.h>

void print_sum(int i, int j) {
  printf("Sum = %d\n", (i + j));
}

int main(int argc, char** argv) {
  int i;
  
  for(i = 0; i < 10; i++) {
    print_sum(i, i + 1);
  }
}

