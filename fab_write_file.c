/*
 * Esempio di scrittura su file.
 * La procedura per scrivere su un file e' la seguente:
 *  - creare un file pointer con il comando fopen
 *  - scrivere sul file (per esempio con fprintf)
 *  - chiudere il file
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(){

    int contatore;
    const char * file_name = "file-di-prova.txt";

    // FILE e' un costrutto definito nella libreria standard C (in pratica definito in stdio.h) che rappresenta un file.
    FILE *output_file;

    // fopen serve per inizializzare la variabile output_file che rappresenta il file.
    // il primo argomento e' il nome del file
    // il secondo argomento e' il "modo" in cui viene aperto il file; in questo caso scrittura (Write), ci sono
    // diversi altri modi, vedere alla ULR sotto per i dettagli
    // https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm
    output_file = fopen(file_name, "w");

    // non e' detto che l'apertura del file vada a buon fine, e' quindi necessario controllare il valore di ritorno
    // di fopen
    if(output_file == NULL){
        // in caso di errore fopen ritorna NULL e la variabile globale di sistema "errno" viene impostata ad un codice
        // che descrive il tipo di errore.
        // la funziona strerror trasforma il codice di errore in una forma leggibile
        printf("Errore [%d] nell'apertura del file %s: %s\n", errno, file_name, strerror(errno));
    } else {
        printf("Il file %s e' stato aperto con successo\n", file_name);
    }

    for(int i = 0; i<= 10 ; i++){
        // una volta che il file e' aperto ci si puo' scrivere dentro similmente a come si scrive sulla console
        fprintf(output_file, "%d\n", i);

        // stampo anche su console per debug
        printf("%d\n", i);
    }

    // alla fine del progamma e' buona norma chiudere il file.
    // anche fclose ha un valore di ritorno, che e' buona norma controllare: 0 se tutto ok, altrimenti il valore
    // EOF viene ritornato e viene settata la variable errno
    if(fclose(output_file) != 0){
        printf("Errore [%d] nella chisura del file %s: %s\n", errno, file_name, strerror(errno));
        printf("Il contenuto del file potrebbe non essere stato scritto correttamente\n");
    }

}