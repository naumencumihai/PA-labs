/*
Laborator 10 - PA
Naumencu Mihai
322 CD
*/

#include <stdio.h>
#include <stdlib.h>

#define N 7

void initializare_matrice(int m[][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = 0;
} 

void adauga_muchie(int m[][N], int sursa, int destinatie, int cost) {
    m[sursa][destinatie] = cost;
}

void afisare_matrice_adiacenta(int m[][N]) {
    printf("\n\tMatricea de adiacenta:\n");
    printf("\n\t1\t2\t3\t4\t5\t6\t7\n");
    printf("\t_\t_\t_\t_\t_\t_\t_\n\n");
    for (int i = 0; i < N; i++) {
        printf("  %d |\t", i + 1);
        for (int j = 0; j < N; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n\n");
    }
}

void construieste_coada(int Q[], int n) {
    for (int i = 0; i < n; i++)
        Q[i] = 1; 
        // Cand Q[i] = 0, elementul nu se mai regaseste in coada
}

int extrage_min(int Q[], int d[], int n) {
    int index;
    for (int j = 0; j < n; j++) {
        if (Q[j]) {
            index = j;
            break;
        }
    }
    for (int j = 1; j < n; j++) {
        if (Q[j] == 1) {
            if (d[j] < d[index]) {
                index = j;
            }
        }
    }
    Q[index] = 0;
    return index;
}

int coada_nevida (int Q[],  int n) {
    for (int i = 0; i < N; i++) {
        if (Q[i] == 1)
            return 1;
    }
    return 0;
}

void dijkstra(int m[][N], int s) {
    int d[N], p[N];
    int Q[N];

    for (int i = 0; i < N; i++) {
        d[i] = 99999;
        p[i] = 0;
    }
    d[s] = 0;
    construieste_coada(Q, N);

    int index_min, pas = 1;
    printf("\n\n===  Problema 1 (Dijkstra)  ===\n");
    while (coada_nevida(Q, N)) {
        printf("\nPasul %d:\n", pas);
        index_min = extrage_min(Q, d, N);

        printf("\tNodul %d este extras din coada\n", index_min + 1);
        for (int i = 0; i < N; i++) {
            // Daca e succesor
            if (m[index_min][i]) {
                printf("\t\tNodul %d este succesorul nodului %d\n", i + 1, index_min + 1);
                // m[index_min][i] == cost(u,v)
                if (d[i] > (d[index_min] + m[index_min][i])) {
                    d[i] = d[index_min] + m[index_min][i]; // actualizeaza distanta
                    p[i] = index_min; // actualizeaza parinte
                    printf("\t\t\tSe respecta conditia pentru relaxare si:\n");
                    printf("\t\t\td[%d] devine %d\n", i + 1, d[index_min] + m[index_min][i]);
                    printf("\t\t\tp[%d] devine %d\n", i + 1, index_min + 1);
                } else {
                    printf("\t\t\tNU se respecta conditia pentru relaxare\n");
                }
            }
        }
        pas++;
    }
    // Rezultate finale
    printf("\nRezultate finale:\n\n");
    for (int i = 0; i < N; i++) {
        printf("Nod %d:\t", i + 1);
        if (i != 0)
            printf("d[%d] = %d;\tp[%d] = %d\n", i + 1, d[i], i + 1, p[i] + 1);
        else
            printf("d[1] = %d;\tp[1] = null\n", d[0]);
    }
    printf("\n\n");
}

void bellman_ford (int m[][N], int s) {
    int d[N], p[N];
    int E[N];

    for (int i = 0; i < N; i++) {
        d[i] = 99999;
        p[i] = 0;
        E[i] = 0; // lista nodurilor considerate
    }
    d[s] = 0;
    E[s] = 1; // Nod initial considerat

    printf("\n===  Problema 2 (Bellman-Ford)  ===\n");
    for (int i = 0; i < N - 1; i++) {
        printf("\nPasul %d:\n", i + 1);
        for (int j = 0; j < N; j++) {
            if (E[j]) {
                E[j] = 0;
                printf("\tPentru arcele care pleaca din nodul %d:\n", j + 1);
                for (int k = 0; k < N; k++) {
                    if (m[j][k]) { // Nod k succesor al nodului j
                        E[k] = 1;
                        printf("\t - Arcul (%d, %d):\n", j + 1, k + 1);
                        if (d[k] > (d[j] + m[j][k])) {
                            d[k] = d[j] + m[j][k]; // Actualizare distanta
                            p[k] = j; // Actualizare parinte
                            printf("\t\t\tSe respecta conditia de relaxare si:\n");
                            printf("\t\t\td[%d] devine %d\n", k + 1, d[j] + m[j][k]);
                            printf("\t\t\tp[%d] devine %d\n", k + 1, j + 1);
                        } else {
                            printf("\t\tNU se respecta conditia de relaxare\n");
                        }
                    }
                }
            }
        }
    }

    printf("\n\nRezultate finale:\n\n");
    for (int i = 0; i < N; i++) {
        printf("Nod %d:\t", i + 1);
        if (i != 0)
            printf("d[%d] = %d;\tp[%d] = %d\n", i + 1, d[i], i + 1, p[i] + 1);
        else
            printf("d[1] = %d;\tp[1] = null\n", d[0]);
    }
    printf("\n");
}

int main(void) {
    int Matrice_adiacenta[N][N];
    int s = 0;
 
    initializare_matrice(Matrice_adiacenta);
    adauga_muchie(Matrice_adiacenta, 0, 1, 3);
    adauga_muchie(Matrice_adiacenta, 0, 2, 4);
    adauga_muchie(Matrice_adiacenta, 0, 4, 1);
    adauga_muchie(Matrice_adiacenta, 0, 5, 10);
    adauga_muchie(Matrice_adiacenta, 0, 6, 3);
    adauga_muchie(Matrice_adiacenta, 1, 2, 2);
    adauga_muchie(Matrice_adiacenta, 2, 3, 2);
    adauga_muchie(Matrice_adiacenta, 2, 5, 2);
    adauga_muchie(Matrice_adiacenta, 4, 3, 3);
    adauga_muchie(Matrice_adiacenta, 4, 6, 1);
    adauga_muchie(Matrice_adiacenta, 5, 3, 2);
    adauga_muchie(Matrice_adiacenta, 6, 2, 1);
    adauga_muchie(Matrice_adiacenta, 6, 3, 10);
    adauga_muchie(Matrice_adiacenta, 6, 4, 2);

    afisare_matrice_adiacenta(Matrice_adiacenta);

    dijkstra(Matrice_adiacenta, s);
    bellman_ford(Matrice_adiacenta, s);
    return 0;
}