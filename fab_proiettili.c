// [FM] Tutti i commenti che cominciano per [FM] sono delle indicazioni di stile, vanno rimossi dal programma finale
// [FM]
// [FM] Un modo semplice per rimuovere i miei commenti di stile e' eseguire il seguente comando da shell:
// [FM] grep -v "\[FM\]" fab_proiettili.c > fab_proiettili_clean.c
// [FM] Il comando grep serve a filtrare un file selezionando le righe che contengono un certo pattern.
// [FM] L'opzione -v inverte la selezione e quindi toglie tutte le righe che contengono [FM] lasciando le altre.
// [FM] L'operatore > serve a redirezionare l'uscita del comando grep (in questo caso le righe di fab_proiettili.c)
// [FM] che non hanno questi commenti di stile in un nuovo file.
// [FM]
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

// [FM] Questo comando del preprocessore serve definisce una sorta di variabile
// [FM] La variabile viene utilizzata nel codice per includere o meno delle stampe di debug nella compilazione
// [FM] Cancellando o commentando questa riga e' possibile "accendere" o "spegnere" le stampe di debug.
// [FM] Se si cancella la riga, e' comunque possibile definire la variabile a tempo di compilazione passando
// [FM] l'opzione -D al compilatore.
// [FM] In altre parole si puo' cancellare questa riga (disabilitando il debug) e abilitare il debug con il comando:
// [FM] gcc -DF_DEBUG_MESSAGE -o fab_proiettili fab_proiettili.c
#define F_DEBUG_MESSAGE

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

#ifdef F_DEBUG_MESSAGE
    printf("\n\n***** BANG *****\n\n\n");
#endif

    do {
        x = velocita_iniziale_x_1 * time;
        y = velocita_iniziale_y_1 * time - 0.5 * EARTH_GRAVITY_ACCELLERATION * time * time;
        // [FM] in alternativa, puoi usare l'operatore di autoincremento
        // [FM] time = time + time_step;
        time += time_step;

        // [FM] stampa l'output in maniera ordinata in modo che, per esempio, possa essere letto da un'altro
        // [FM] programma, per esempio per graficare il risultato
        // [FM] Con queste direttive di preprocessore posso includere/escludere dalla compilazione l'istruzione di
        // [FM] print, questo mi consente di stampare solo il risultato finale e non tutti i risultati intermedi.
#ifdef F_DEBUG_MESSAGE
        printf("t=%lf, x=%lf, y=%lf\n", time, x, y);
#endif
    } while (y >= 0);

    return x;
}

int main() {

    /* valori delle velocita' iniziali, vengono lette e inizializzate da tastiera */
    double velocita_iniziale_x_1 = leggi_velocita("Inserire la velocita' del primo proiettile sull'asse delle x in metri al secondo.....");
    double velocita_iniziale_y_1 = leggi_velocita("Inserire la velocita' del primo proiettile sull'asse delle y in metri al secondo.....");
    double velocita_iniziale_x_2 = leggi_velocita("Inserire la velocita' del secondo proiettile sull'asse delle x in metri al secondo...");
    double velocita_iniziale_y_2 = leggi_velocita("Inserire la velocita' del secondo proiettile sull'asse delle y in metri al secondo...");

    //inizio fase dei calcoli

    // [FM] anche in questo caso il codice e' ripetuto, vale la pena introdurre una funzione

    double distanza = calcola_traiettoria(velocita_iniziale_x_1, velocita_iniziale_y_1);
    printf("Il primo proiettile arriva a %lf metri di distanza\n", distanza);

    distanza = calcola_traiettoria(velocita_iniziale_x_2, velocita_iniziale_y_2);
    printf("Il second proiettile arriva a %lf metri di distanza\n", distanza);
}
