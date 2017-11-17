// [FM] Tutti i commenti che cominciano per [FM] sono delle indicazioni di stile, vanno rimossi dal programma finale
// [FM] All'inizio di ogni file metti un commento che spiega cosa fa il file.
// [FM] Opzionalmente e' una buona idea mettere data e autore (ci sono degli standard, non ce li ho freschi per il
// [FM] C, saranno oggetto di una prossima lezione)

/*
 * Programma per il calcolo della traiettoria di un proiettile.
 *
 * Fabio Moratti
 * 17/11/2017
 */

#include <stdio.h>

// [FM] Dove sono le mie variabili? Se dichiari le variabili qui le rendi globali, questo significa che vengono viste
// [FM] da tutte le funzioni: questo e' male per l'incapsulamento e il riuso del codice - a voce i dettagli

// [FM] g e' un valore costante: usa il modificatore const: in questo modo il valore della variabile non puo' essere
// [FM] modificato, neanche per errore

// [FM] Dai un nome autoesplicativo alle variabili: tra sei mesi e' facile che hai dimenticato che significa g, mentre
// [FM] un nome piu' esplicativo e' sicuramente piu' facile da ricordare

/* Accellerazione di gravita' (m/s^2)*/
const double EARTH_GRAVITY_ACCELLERATION = 9.8;

// [FM] la lettura delle velocita' e' fatta usando del codice identico, quindi e' una buona idea fattorizzarlo in
// [FM] una funzione che puo' essere chiamata piu' volte

// [FM] le fuzioni possono essere raccolte in un file separato in modo da creare una libreria, che a sua volta
// [FM] puo' essere usata in diversi programmi (e' quello che succede per esempio con la libreria standart).
// [FM] Come fare lo vediamo in una prossima lezione */

// [FM] Esiste una sintassi standard per scrivere la documentazione delle funzioni, questo permette di generare in
// [FM] maniera automatica la documentazione - lo vediamo in una delle prossime lezioni

/*
 * Funzione per la lettura della velocita' iniziale.
 * La velocita' letta non deve essere minore di zero.
 *
 * Parametri: prompt: stringa con il messaggio da presentare all'utente.
 * Ritorna: la velocita' inserita
 *
 */
double leggi_velocita(const char *prompt) {

    double velocita_iniziale;

    do {
        printf("%s", prompt);
        scanf("%lf", &velocita_iniziale);
        if (velocita_iniziale < 0) {
            printf("La velocita' non deve essere negativa\n");
        }
    } while (velocita_iniziale < 0);

    return velocita_iniziale;
}

double calcola_traiettoria(double velocita_iniziale_x_1, double velocita_iniziale_y_1){

    // [FM] Metti sempre un commento che spiega che cosa sono le variabili
    /* Coordinate (x, y) del proiettile */
    double x;
    double y;

    // [FM] le variabili devono avere un nome autoesplicativo
    /* Tempo della simulazione */
    double time = 0;

    // [FM] non e' mai una buona idea lasciare dei numeri nel codice, se hai bisogno di cambiarli diventa noioso e
    // [FM] possibile fonte di errori
    const double time_step = 0.001;

    printf("\n\n***** BANG *****\n\n\n");

    do {
        x = velocita_iniziale_x_1 * time;
        y = velocita_iniziale_y_1 * time - 0.5 * EARTH_GRAVITY_ACCELLERATION * time * time;
        // [FM] in alternativa, puoi usare l'operatore di autoincremento
        // [FM] time = time + time_step;
        time += time_step;

        // [FM] stampa l'output in maniera ordinata in modo che, per esempio, possa essere letto da un'altro
        // [FM] programma, per esempio per graficare il risultato
        printf("t=%lf, x=%lf, y=%lf\n", time, x, y);
    } while (y >= 0);

    return x;
}

int main() {

    /* valori delle velocita' iniziali, vengono lette e inizializzate da tastiera */
    double velocita_iniziale_x_1 = leggi_velocita("Inserire la velocita' del primo proiettile sull'asse delle x in metri al secondo.....");
    double velocita_iniziale_y_1 = leggi_velocita("Inserire la velocita' del primo proiettile sull'asse delle y in metri al secondo.....");
    double velocita_iniziale_x_2 = leggi_velocita("Inserire la velocita' del secondo proiettile sull'asse delle x in metri al secondo...");
    double velocita_iniziale_y_2 = leggi_velocita("Inserire la velocita' del secondo proiettile sull'asse delle y in metri al secondo...");
    
/*
    //inizio velocita' del proiettile_1

    do {
        printf("Inserire la velocita' del primo proiettile sull'asse delle x in metri al secondo.....");
        scanf("%lf", &velocita_iniziale_x_1);
        if (velocita_iniziale_x_1 < 0) {
            printf("La velocita' non deve essere negativa\n");
        }
    } while (velocita_iniziale_x_1 < 0);

    do {
        printf("Inserire la velocita' del primo proiettile sull'asse delle y in metri al secondo.....");
        scanf("%lf", &velocita_iniziale_y_1);
        if (velocita_iniziale_y_1 < 0) {
            printf("La velocita' non deve essere negativa\n");
        }
    } while (velocita_iniziale_y_1 < 0);

    //inizio velocita' del proiettile_2

    do {
        printf("Inserire la velocita' del secondo proiettile sull'asse delle x in metri al secondo...");
        scanf("%lf", &velocita_iniziale_x_2);
        if (velocita_iniziale_x_2 < 0) {
            printf("La velocita' non deve essere negativa\n");
        }
    } while (velocita_iniziale_x_2 < 0);

    do {
        printf("Inserire la velocita' del secondo proiettile sull'asse delle y in metri al secondo...");
        scanf("%lf", &velocita_iniziale_y_2);
        if (velocita_iniziale_y_2 < 0) {
            printf("La velocita' non deve essere negativa\n");
        }
    } while (velocita_iniziale_y_2 < 0);
*/

    //inizio fase dei calcoli

    // [FM] anche in questo caso il codice e' ripetuto, vale la pena introdurre una funzione

    double distanza = calcola_traiettoria(velocita_iniziale_x_1, velocita_iniziale_y_1);
    printf("Il primo proiettile arriva a %lf metri di distanza\n", distanza);

    distanza = calcola_traiettoria(velocita_iniziale_x_2, velocita_iniziale_y_2);
    printf("Il second proiettile arriva a %lf metri di distanza\n", distanza);

    /*time = 0;


    printf("\n\n***** BANG *****\n\n\n");

    do {
        x = velocita_iniziale_x_1 * time;
        y = velocita_iniziale_y_1 * time - 0.5 * EARTH_GRAVITY_ACCELLERATION * time * time;
        // [FM] in alternativa, puoi usare l'operatore di autoincremento
        // [FM] time = time + time_step;
        printf("x=%lf\n  y=%lf\n\n", x, y);
    } while (y >= 0);
    printf("Il primo proiettile arriva a %lf metri di distanza\n", x);

    time = 0;

    printf("\n\n***** BANG *****\n\n\n");

    do {
        x2 = velocita_iniziale_x_2 * time;
        y2 = velocita_iniziale_y_2 * time - 0.5 * EARTH_GRAVITY_ACCELLERATION * time * time;

        time = time + time_step;
    } while (y2 >= 0);
    printf("Il secondo proiettile arriva a %lf metri di distanza\n", x);*/
}
