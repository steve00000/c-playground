#include <stdio.h>
    
int main() {
    
  int N;
  int a;
  int b;  /*base*/
    
  do{
    printf  ("inserire numero intero ''N'' maggiore di 0\n");
    scanf   ("%d", &N);
  } 
  while(N<=0);
    
  do{
    printf  ("inserire la base ''b'' \n");
    scanf   ("%d", &b);
  } 
  while (2>b);
  printf("il numero convertito in base ''b'' è  ");
  do{
    a=N%b; 
    N=N/b;
    printf  ("%d",a);
  }
  while (N!=0);
  printf("\n");
}   
