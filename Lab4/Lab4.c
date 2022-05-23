// Laborator 4 - PA
// Naumencu Mihai
// 322 CD

#include <stdio.h>

int max (int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

void cel_mai_lung_subsir(int sir[], int N) {
    int D[N];

    for(int i = 0; i < N; i++)
        D[i] = 0;

    D[0] = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if (sir[j] < sir[i])
                D[i] = max(D[i], D[j] + 1);
        }
    }
    int ans = 1;
    for(int i = 0; i < N; i++)
        ans = max(ans, l[i]);

    int c = 0;
    printf("Subsir:  { %d ", D[0]);
    for(int i = 1; i < N; i++) {
        if (D[i] != D[c]) {
            printf("%d ", D[i]);
            c = i;
        }
    }
    printf("}\nLungime: %d\n\n", ans);
}

void rucsac(int M, int m[], int v[], int n)
{
    int i, j;
    int D[n + 1][M + 1];
 
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) {
            if (i == 0 || j == 0)
                D[i][j] = 0;
            else if (m[i - 1] <= j)
                D[i][j] = max(v[i - 1] + D[i - 1][j - m[i - 1]], D[i - 1][j]);
            else
                D[i][j] = D[i - 1][j];
        }
    }
    // Afisare matrice rezultate
    for (int linie = 0; linie <= n; linie++) {
        for (int coloana = 0; coloana <= M; coloana += 10) {       
            if (linie == 0 && coloana == 0)
                printf("  \\ ");
            else if (linie == 0)
                printf("%d    ", coloana);
            else if (coloana == 0)
                printf("%d | ", linie);
            else {
                printf("%d   ", D[linie][coloana]);
                if (D[linie][coloana] < 100)
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("\nValoare maxima in rucsac: $%d\n", D[n][M]);
}

int parantezare_matrice(int p[], int n) {
    int j, count;
    int D[n][n];

    for (int i = 1; i < n; i++)
        D[i][i] = 0;
    
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            j = i + l - 1;
            D[i][j] = 9999;
            for (int k = i; k < j; k++) {
                count = D[i][k] + D[k + 1][j] + p[i - 1] * p[k] * p[j];
        
                if (count < D[i][j])
                    D[i][j] = count;
            }
        }
    }

    // Afisare matrice rezultate
    for (int linie = 0; linie < n; linie++) {
        for (int coloana = 0; coloana < n; coloana++) {       
            if (linie == 0 && coloana == 0)
                printf("\\   ");
            else if (linie == 0)
                printf("%d    ", coloana);
            else if (coloana == 0)
                printf("%d | ", linie);
            else if (linie > coloana)
                printf("x    ");
            else
                printf("%d   ", D[linie][coloana]);
        }
        printf("\n");
    }
    return D[1][n - 1];
}

int main (){
    int p[] = {2, 4, 3, 5, 2};

    int M = 50;
    int m[] = {10, 30, 20};
    int v[] = {60, 120, 100};

    int sir[7] = {1, 2, 9, 3, 8, 4, 7};

    printf("\nProblema 1:\n\n");
    printf("\nNr. minim de inmultiri: %d\n", parantezare_matrice(p, (sizeof(p) / sizeof(p[0]))));
    printf("\n\nProblema 2:\n\n");
    rucsac(M, m, v, 3);
    printf("\n\nProblema 3:\n\n");
    cel_mai_lung_subsir(sir, 7);
    return 0;
}