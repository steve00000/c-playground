#include <stdio.h>
#include <math.h>


double x;
double y;

double x2;
double y2;

double g;
double t;

double v0x_1;
double v0y_1;

double v0x_2;
double v0y_2;

int main () {

  //inizio velocita' del proiettile_1
  
  do{
    printf ( "Inserire la velocita' del primo proiettile sull'asse delle x in metri al secondo....." );
    scanf  ( "%lf", &v0x_1 );
    if     ( v0x_1<0 ) {
      printf ("La velocita' non deve essere negativa\n");
    }
  }
  while (v0x_1<0);

  do{
    printf ( "Inserire la velocita' del primo proiettile sull'asse delle y in metri al secondo....." );
    scanf  ( "%lf", &v0y_1 );
    if     ( v0y_1<0 ) {
      printf ("La velocita' non deve essere negativa\n");
    }
  }
  while (v0y_1<0);

  //inizio velocita' del proiettile_2
  
  do{
    printf ("Inserire la velocita' del secondo proiettile sull'asse delle x in metri al secondo...");
    scanf  ("%lf",&v0x_2);
    if     (v0x_2<0) {
      printf ("La velocita' non deve essere negativa\n");
    }
  }
  while (v0x_2<0);
  
  do{
    printf ("Inserire la velocita' del secondo proiettile sull'asse delle y in metri al secondo...");
    scanf  ("%lf",&v0y_2);
    if     (v0y_2<0) {
      printf ("La velocita' non deve essere negativa\n");
    }
  }
  while (v0y_2<0);

  //inizio fase dei calcoli
  
  g=9.8;

  t=0;

  printf("\n\n***** BANG *****\n\n\n");
  
  do{
    x = v0x_1*t;
    y = v0y_1*t-0.5*g*t*t;
    t = t+0.001;
    printf("x=%lf\n  y=%lf\n\n",x,y);
  }
  while(y>=0);
  printf("Il primo proiettile arriva a %lf metri di distanza\n",x);

  t=0;

  printf("\n\n***** BANG *****\n\n\n");
  
  do{
    x2 = v0x_2*t;
    y2 = v0y_2*t-0.5*g*t*t;
    t = t+0.001;
  }
  while(y2>=0);
  printf("Il secondo proiettile arriva a %lf metri di distanza\n",x);
}
