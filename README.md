# Battaglia-navale
Una semplice Battaglia Navale realizzata in C++
Versione iniziale della Battaglia Navale. Le funzioni implementate in questa versione sono:
int inizializzaGriglia(char[], int);
char stampaGriglia(char[], int, int);
int generaNavi(char[], int int);
In questa versione, le funzione inizializzaGriglia() resetta il tabellone con il carattere "-". Viene rimossa la stampa del tabellone con le navi generate (perchè dovranno essere nascoste all'utente). La funzione stampaGriglia() restituirà un char che sarà la lettera dell'ultima colonna generata.
Vengono aggiunte le seguenti funzioni.
int convertiColonnaInNumero(char);
int calcolaCella(int, int, int);
