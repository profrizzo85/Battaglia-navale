#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int inizializzaGriglia(char vet[], int dim);
void stampaGriglia(char vet[], int righe, int colonne);
int generaNavi(char vet[], int dim, int nNavi);

int main()
{
    const int DIM_MAX = 100;
    int nColonne, nRighe, dimensione, numeroNavi;
    char griglia[DIM_MAX];
    do
    {
        cout << "Inserisci il numero di righe ";
        cin >> nRighe;
        cout << "Inserisci il numero di colonne ";
        cin >> nColonne;
    }while(nRighe>10 || nColonne>10);
    dimensione = nRighe*nColonne;
    inizializzaGriglia(griglia, dimensione);
    stampaGriglia(griglia, nRighe, nColonne);
    cout << "Inserisci il numero di navi da generare";
    cin >> numeroNavi;
    generaNavi(griglia, dimensione, numeroNavi);
    stampaGriglia(griglia, nRighe, nColonne);
}
int inizializzaGriglia(char vet[], int dim)
{
    int i;
    for(i=0; i<dim; i++)
    {
        vet[i]='A';
    }
    return 1;
}
void stampaGriglia(char vet[], int righe, int colonne)
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

