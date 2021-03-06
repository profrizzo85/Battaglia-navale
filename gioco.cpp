#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int inizializzaGriglia(char vet[], int dim);
char stampaGriglia(char vet[], int righe, int colonne);
int generaNavi(char vet[], int dim, int nNavi);
int convertiColonnaInNumero(char colonna);
int calcolaCella(int riga, int colonna, int fineColonna);
int controllaCella(char vet[], char vetUtente[], int posizioneArray);
int incrementaPunti(int puntiUtente, int valoreIncremento);

int main()
{
    const int DIM_MAX = 100;
    int nColonne, nRighe, dimensione, numeroNavi, rigaScelta;
    int colonnaConvertita, ultimaColonnaConvertita, posizioneScelta;
    int esito, punti=0;
    char griglia[DIM_MAX], grigliaUtente[DIM_MAX], colonnaScelta, ultimaColonna;
    char continuare;
    do
    {
        cout << "Inserisci il numero di righe ";
        cin >> nRighe;
        cout << "Inserisci il numero di colonne ";
        cin >> nColonne;
    }while(nRighe>10 || nColonne>10);
    dimensione = nRighe*nColonne;
    inizializzaGriglia(griglia, dimensione);
    inizializzaGriglia(grigliaUtente, dimensione);
    ultimaColonna = stampaGriglia(griglia, nRighe, nColonne);
    cout << "Inserisci il numero di navi da generare";
    cin >> numeroNavi;
    generaNavi(griglia, dimensione, numeroNavi);
    cout << "E' il tuo turno scegli una cella" << endl;
    cout << "Indica la riga: ";
    cin >> rigaScelta;
    cout << "Indica la colonna: ";
    cin >> colonnaScelta;
    //individuo il numero corrispondente alla colonna scelta dall'utente
    colonnaConvertita = convertiColonnaInNumero(colonnaScelta);
    //converto il carattere dell'ultima colonna della griglia in numero
    ultimaColonnaConvertita = convertiColonnaInNumero(ultimaColonna);
    //calcolo la posizione della cella (corrisponde alla posizione dell'array)
    posizioneScelta = calcolaCella(rigaScelta, colonnaConvertita, ultimaColonnaConvertita);
    //stampaGriglia(griglia, nRighe, nColonne);
    esito = controllaCella(griglia, grigliaUtente, posizioneScelta);
    //stampa la griglia aggiornata dell'utente
    stampaGriglia(grigliaUtente, nRighe, nColonne);
    //calcola il punteggio
    if (esito==1)
        punti = incrementaPunti(punti, 1);
    cout << "Il punteggio del Giocatore e' " << punti << endl;
    do{
        cout << "Sei pronto per il prossimo turno? (s per continuare, qualsiasi tasto per aspettare)";
        cin >> continuare;
    }while(continuare!='s');
    system("cls");
    //stampa la griglia aggiornata dell'utente
    stampaGriglia(grigliaUtente, nRighe, nColonne);
}



int inizializzaGriglia(char vet[], int dim)
{
    int i;
    for(i=0; i<dim; i++)
    {
        vet[i]='-';
    }
    return 1;
}
char stampaGriglia(char vet[], int righe, int colonne)
{
    int i, j, posizione=0;
    char letteraColonna='A';
    cout << "  ";
    for(i=0;i<colonne;i++)
        cout << letteraColonna++ << "|";
    cout << endl;
    for(i=0; i<righe; i++)
    {
        for(j=0; j<colonne; j++)
        {
            if(j==0) cout << i+1 << "|";
            cout << vet[posizione] << "|";
            posizione++;
        }
        cout << endl;
    }
    cout << endl;
    return letteraColonna-1; //restituisce la lettera finale della griglia
}
int generaNavi(char vet[], int dim, int nNavi)
{
    srand(time(NULL));
    int i, j, r;
    for(i=0; i<nNavi; i++)
    {
        r = rand()%dim;
        if (vet[r]=='N')
            i--;
        else
            vet[r]='N';
    }
    return 1;
}
/* Trova il numero corrispondente ad una lettera
   esempio alla A corrisponde 1, alla B corrisponde 2, ecc */
int convertiColonnaInNumero(char colonna){
    int numero;
    numero = colonna - 64;
    return numero;
}
/* Calcola la posizione della cella partendo da 0
   utile per identificare l'elemento dell'array
*/
int calcolaCella(int riga, int colonna, int fineColonna){
    int posizione;
    posizione = (colonna + (riga -1) * fineColonna)-1;
    return posizione;
}
int controllaCella(char vet[], char vetUtente[], int posizioneArray)
{
    if (vet[posizioneArray]=='N')
    {
        cout << "Hai colpito una nave!" << endl;
        vet[posizioneArray]='X';
        vetUtente[posizioneArray]='X';
        return 1;
    }
    else
    {
        cout << "Il tuo colpo è andato a vuoto!" << endl;
        vet[posizioneArray]='A';
        vetUtente[posizioneArray]='A';
        return 0;
    }
}
int incrementaPunti(int puntiUtente, int valoreIncremento)
{
    return puntiUtente + valoreIncremento;
}
