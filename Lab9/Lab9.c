/*
Laborator 9 - PA
Naumencu Mihai
322 CD
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define N 10

// Variabile globale
int culoare[N], d[N], low[N], parinte[N], subarb[N];
int timp;
int punte[N], art[N];

void initializare_matrice(int m[][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = 0;
}

void adauga_muchie(int m[][N], int sursa, int destinatie) {
    m[sursa][destinatie] = 1;
    m[destinatie][sursa] = 1; // Graf neorientat
}

void afisare_matrice_adiacenta(int m[][N]) {
    printf("\n\tMatricea de adiacenta:\n");
    printf("\n\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
    printf("\t_\t_\t_\t_\t_\t_\t_\t_\t_\t_\n\n");
    for (int i = 0; i < N; i++) {
        printf("  %d |\t", i);
        for (int j = 0; j < N; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n\n");
    }
}

void Exploreaza1(int u, int m[][N]) {
    // Initializari
    d[u] = timp;
    low[u] = timp;
    timp++;
    culoare[u] = 1; // 1 == gri

    for (int v = 0; v < N; v++) {
        if (m[u][v] == 1) { // daca e succesor
            if (culoare[v] == 0) { // daca e alb
                parinte[v] = u;
                subarb[u]++; // actualizare nr subarbori dominati de u
                Exploreaza1(v, m);
                if (low[v] < low[u])
                    // low(u) = min{low(u), low(v)}
                    low[u] = low[v];
                if (parinte[u] != -1 && low[v] >= d[u])
                    art[u] = 1;
            } else {
                if (parinte[u] != v) {
                    if (d[v] < low[u])
                        // low(u) = min{low(u), d(v)}
                        low[u] = d[v];
                }
            } 
        }
    }
}

void Exploreaza2(int u, int m[][N]) {
    // initializari
    d[u] = timp;
    low[u] = timp;
    timp++;
    culoare[u] = 1; // 1 == gri

    for (int v = 0; v < N; v++) {
        if (m[u][v] == 1) { // daca e succesor
            if (culoare[v] == 0) { // daca e alb
                parinte[v] = u;
                Exploreaza2(v, m);
                if (low[v] < low[u])
                    // low (u) = min{low(u), low(v)}
                    low[u] = low[v];
                if (low[v] > d[u])
                    punte[v] = 1;
            } else {
                if (parinte[u] != v) {
                    if (d[v] < low[u])
                        // low(u) = min{low(u), d(v)}
                        low[u] = d[v];
                }
            } 
        }
    }
}

void Puncte (int m[][N]) {
    printf("\n===  Problema 1 (Puncte de articulatie)  ===\n\n");

    timp = 0;
    for (int i = 0; i < N; i++) {
        culoare[i] = 0;
        d[i] = 0;
        parinte[i] = -1;
        low[i] = 0;
        subarb[i] = 0;
        art[i] = 0;
    }  

    for (int i = 0; i < N; i++) {
        if (culoare[i] == 0) {
            Exploreaza1(i, m);
            if (subarb[i] > 1) 
                art[i] = 1;
        }
    }

    // Afisare
    int nrArt = 0;
    for (int i = 0; i < N; i++) {
        printf("d:%d, low:%d, p:%d, subarb:%d, art:%d\n", 
            d[i], low[i], parinte[i], subarb[i], art[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        if (art[i] == 1) nrArt++;
    }
    printf("Rezultat: %d puncte de articulatie:\n", nrArt);
    for (int i = 0; i < N; i++) {
        if (art[i] == 1) 
            printf("%d\n", i);;
    }
    printf("\n");
}

void Punti (int m[][N]) {
    printf("\n===  Problema 2 (Punti)  ===\n\n");

    timp = 0;
    for (int i = 0; i < N; i++) {
        culoare[i] = 0;
        d[i] = 0;
        parinte[i] = -1;
        low[i] = 0;
        punte[i] = 0;
    }  

    for (int i = 0; i < N; i++) {
        if (culoare[i] == 0) {
            Exploreaza2(i, m);
        }
    }

    // Afisare
    int nrPunti = 0;
    for (int i = 0; i < N; i++) {
        printf("d:%d, low:%d, p:%d, punte:%d\n", d[i], low[i], parinte[i], punte[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        if (punte[i] == 1)
            nrPunti++;
    }
    printf("Rezultat: %d punti:\n", nrPunti);
    for (int i = 0; i < N; i++) {
        if (punte[i] == 1) 
            printf("%d - %d\n", d[i], parinte[i]);;
    }
}

int main() {
    int Matrice_adiacenta[N][N];

    initializare_matrice(Matrice_adiacenta);

    adauga_muchie(Matrice_adiacenta, 0, 1);
    adauga_muchie(Matrice_adiacenta, 0, 9);
    adauga_muchie(Matrice_adiacenta, 2, 1);
    adauga_muchie(Matrice_adiacenta, 8, 1);
    adauga_muchie(Matrice_adiacenta, 3, 2);
    adauga_muchie(Matrice_adiacenta, 4, 2);
    adauga_muchie(Matrice_adiacenta, 7, 2);
    adauga_muchie(Matrice_adiacenta, 4, 3);
    adauga_muchie(Matrice_adiacenta, 5, 3);
    adauga_muchie(Matrice_adiacenta, 6, 5);
    adauga_muchie(Matrice_adiacenta, 7, 8);

    afisare_matrice_adiacenta(Matrice_adiacenta);

    Puncte(Matrice_adiacenta); // (1)
    Punti(Matrice_adiacenta);  // (2)

    return 0;
}