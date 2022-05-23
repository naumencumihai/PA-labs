/*
Laborator 11 - PA
Naumencu Mihai
322 CD
*/

#include <stdio.h>
#include <stdlib.h>

#define N 12
#define M 15

void initializare_matrice(int m[][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = 0;
}

void adauga_muchie(int m[][N], int sursa, int destinatie, int cost) {
    m[sursa][destinatie] = cost;
    m[destinatie][sursa] = cost; // Graf neorientat
}

void afisare_matrice_adiacenta(int m[][N]) {
    printf("\n\tMatricea de adiacenta:\n");
    printf("\n\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\tK\tL\n");
    printf("\t_\t_\t_\t_\t_\t_\t_\t_\t_\t_\t_\t_\n\n");
    for (int i = 0; i < N; i++) {
        printf("  %c |\t", i + 65);
        for (int j = 0; j < N; j++) {
        	if (i == j)
        		printf("\\\t");
        	else if (m[i][j] == 0)
        		printf("*\t");
        	else
            	printf("%d\t", m[i][j]);
        }
        printf("\n\n");
    }
}

void afisare_AMA(int AMA[][N]) {
	printf("\tAMA: { ");
	int muchie = 1;
	while (muchie < N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (AMA[i][j] == muchie) {
					printf("%c%c ", j + 65, i + 65);
					muchie++;
				}
			}
		}
	}
	printf("}\n\n\n");
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

void Prim (int m[][N], int s) {
	int d[N], p[N];
	int Q[N];
	int AMA[N][N];
	initializare_matrice(AMA);

	for (int i = 0; i < N; i++) {
        d[i] = 99999; // inf
        p[i] = 99999; // null
    }
    d[s] = 0;
    construieste_coada(Q, N);

    int index_min, pas = 1;
	for (int i = 0; i < N; i++) {
		if (m[s][i] != 0) {
			p[i] = s; // update parinti succesori s (I)
			d[i] = m[s][i]; // update distanta succesori s (I)
		}
	}
	
	printf("\n\n===  Problema 1 - Prim  ===\n\n");
	while (coada_nevida(Q, N)) { // cat timp coada e nevida
		printf("\nPasul %d:\n", pas);
		index_min = extrage_min(Q, d, N);
		if (pas == 1) // la primul pas se sare peste nodul s (I)
			index_min = extrage_min(Q, d, N);
		printf("\tNodul %c este extras din coada\n", index_min + 65);

		AMA[index_min][p[index_min]] = pas;

		for (int i = 0; i < N; i++) {
			if (m[index_min][i] && Q[i]) {
				printf("\t\tNodul %c este succesorul nodului %c\n", i + 65, index_min + 65);
				if (d[i] > m[index_min][i]) {
					d[i] = m[index_min][i]; // actualizare distanta
					p[i] = index_min; // actualizare parinte
                    printf("\t\t\tSe respecta conditia pentru actualizare si:\n");
                    printf("\t\t\td[%c] devine %d\n", i + 65, m[index_min][i]);
                    printf("\t\t\tp[%c] devine %c\n", i + 65, index_min + 65);
				}
			}
		}
		pas++;
	}
	printf("\nRezultat final:\n");
	afisare_AMA(AMA);
}

struct muchie {
	int nod1, nod2, cost;
};

void adauga_muchii (struct muchie E[], int m[][N]) {
	int index = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j ++) {
			if (m[i][j] != 0) {
				E[index].nod1 = i;
				E[index].nod2 = j;
				E[index].cost = m[i][j];
				index++;
			}
		}
	}
}

void sorteaza_muchii (struct muchie E[M]) {
	struct muchie tmp;

   	for (int i = 0; i < M - 1; i++) {
       	for (int j = 0; j < M - i - 1; j++) {
           	if (E[j].cost > E[j + 1].cost) {
              	tmp = E[j];
              	E[j] = E[j + 1];
              	E[j + 1] = tmp;
           	}
       	}
   	}
}

int verificare (int nod1, int nod2, int Arbori[][N]) {
	for (int i = 0; i < N; i++)
		if (Arbori[nod1][i] == 1 && Arbori[nod2][i] == 1)
			return 0;
	return 1;
}

void reunire (int nod1, int nod2, int Arbori[][N]) {
	Arbori[nod1][nod2] = 1;
	Arbori[nod2][nod1] = 1;
}

void Kruskal (int m[][N]) {
	struct muchie AMA[M];
	struct muchie E[M];
	adauga_muchii (E, m);
	sorteaza_muchii(E);
	int Arbori[N][N];
	initializare_matrice(Arbori);
	
	for (int i = 0; i < N; i++) {
		Arbori[i][i] = 1;
	}

	printf("\n===  Problema 2 - Kruskal  ===\n\n\n");

	for (int i = 0; i < N - 1; i++) {
		printf("Pasul %d:\n", i + 1);
		printf("\tMuchia %c - %c\n", E[i].nod2 + 65, E[i].nod1 + 65);
		if (verificare(E[i].nod1, E[i].nod2, Arbori)) {
			reunire(E[i].nod1, E[i].nod2, Arbori);
			AMA[i] = E[i];
			printf("\t\tNu se formeaza ciclu, muchie adaugata in AMA\n");
		}
	}
	printf("\nS-au executat N - 1 numar de pasi, nicio muchie nu se mai adauga in AMA\n");

	printf("\n\nRezultat final:\nAMA:\n");
	for (int i = 0; i < N - 1; i++) {
		printf("%c - %c\n", AMA[i].nod2 + 65, AMA[i].nod1 + 65);
	}

	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < N; j++) {
	// 		printf("%d ", Arbori[i][j]);
	// 	}
	// 	printf("\n");
	// }

}

int main(void) {
    int Matrice_adiacenta[N][N];
    int s = 8; // I
 
    initializare_matrice(Matrice_adiacenta);
    adauga_muchie(Matrice_adiacenta, 4, 5, 2);
    adauga_muchie(Matrice_adiacenta, 0, 8, 3);
    adauga_muchie(Matrice_adiacenta, 6, 7, 4);
    adauga_muchie(Matrice_adiacenta, 1, 2, 5);
    adauga_muchie(Matrice_adiacenta, 8, 9, 5);
    adauga_muchie(Matrice_adiacenta, 0, 7, 6);
    adauga_muchie(Matrice_adiacenta, 10, 11, 7);
    adauga_muchie(Matrice_adiacenta, 2, 3, 8);
    adauga_muchie(Matrice_adiacenta, 8, 11, 8);
    adauga_muchie(Matrice_adiacenta, 0, 1, 9);
    adauga_muchie(Matrice_adiacenta, 3, 5, 9);
    adauga_muchie(Matrice_adiacenta, 0, 6, 10);
    adauga_muchie(Matrice_adiacenta, 1, 6, 11);
    adauga_muchie(Matrice_adiacenta, 2, 4, 12);
    adauga_muchie(Matrice_adiacenta, 9, 10, 14);

    afisare_matrice_adiacenta(Matrice_adiacenta);

    Prim(Matrice_adiacenta, s);
    Kruskal(Matrice_adiacenta);

    return 0;
}

/*
A - 0
B - 1
C - 2
D - 3
E - 4
F - 5
G - 6
H - 7
I - 8
J - 9
K - 10
L - 11
*/