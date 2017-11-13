#include <stdio.h>
#include <math.h>

int vettore[100];
int i;

int main () {
  for (i=0; i<100; i++) {
    vettore[i] = i;
  }
  for (i=0; i<100; i++) {
    printf ("%d\n", vettore[i]);
  }
}
