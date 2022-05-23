/*
Laborator 5 - PA
Naumencu Mihai
322 CD
*/


#include <stdio.h>
#include <string.h>

#define MAX 100
#define X 10

void k_garduri(int n, int k) {
    int D[MAX];
    char gard[MAX][MAX];
    int len = 1;
    char oriz = '=', vert = '|';
    gard[0][0] = '|';
    D[0] = 1;
    D[1] = 1;
    printf("gard 1: %c\n", gard[0][0]);

    for (int i = 2; i <= n; i++) {
        int count = 0;
        D[i] = D[i - 1] + D[i - k];
        for (int j = 0; j < len; j++) {
            if (j > 0) {
                char aux[MAX];
                strcpy(aux, gard[j]);
                for(int q = strlen(aux); q >= 0; q--)
                    aux[q + 1] = aux[q];
                aux[0] = '|';
                strcpy(gard[len + count], aux);
                count++;
            }
            strncat(gard[j], &vert, 1);
        }
        if (!(i % 2)) {
            strcpy(gard[len], "");
            for (int j = 0; j < i / 2; j++)
                strncat(gard[len], &oriz, 1);
        }
        printf("gard %d: ", i);
        for (int j = 0; j < D[i]; j++)
            printf("%s ", gard[j]);
        printf("\n");
        len = D[i];
    }
}

void sume(int n, int k) {
    int v[X] = {3, 1, 2, 4};
    int D[X][X];

    for (int i = 0; i < k; i++)
    	D[0][i] = 0;

    for(int i = 0; i < n; i++) {
    	if (v[i] % k == 0) {
    		D[i+1][0] = 1 + 2 * D[i][0];
    		D[i+1][1] = 2 * D[i][1];
    		D[i+1][2] = 2 * D[i][2];
   		}
   		if (v[i] % k == 1) {
   			D[i+1][0] = D[i][0] + D[i][2];
   			D[i+1][1] = 1 + D[i][0] + D[i][1];
   			D[i+1][2] = D[i][1] + D[i][2];
   		}
   		if (v[i] % k == 2) {
   			D[i+1][0] = D[i][0] + D[i][1];
   			D[i+1][1] = D[i][2] + D[i][1];
   			D[i+1][2] = 1 + D[i][0] + D[i][2];
   		}
   	}

    printf("Matricea D:\n");
    for (int i = 1; i < n+1; i++) {
    	for (int j = 0; j < k; j++) 
    		printf("%d ", D[i][j]);
    	printf("\n");
    }
    printf("\nAvem %d solutii, sumele intre:\n", D[n][0]);

    for (int i = 0; i < n; i++)
    	printf("%d ", v[i]);
    printf("\n");

    for (int i = 0; i < n; i++) {
    	int sum = 0;
    	for (int j = i; j < n; j++) {
    		sum += v[j];
    		if (sum % 3 == 0) {
    			for (int q = j; q >= i; q--)
    				printf("%d ", v[q]);
    			printf("\n");
    		}
    	}
    }
}

int main () {
    int n2 = 6, k2 = 2;
    printf("\n-- Problema 2 --\n\n");
    k_garduri(n2, k2);


    printf("\n -- Problema 3 -\n\n");
    int n3 = 4, k3 = 3;
    sume(n3, k3);
}