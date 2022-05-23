// Laborator 3 - PA
// Naumencu Mihai
// 322 CD

#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void rucsac(int m[], int v[], int M, int n) {
    int cur_M;
    float tot_v;
    int max;
    int folosit[3];
 
    for (int i = 0; i < n; i++)
        folosit[i] = 0;
 
    cur_M = M;
    while (cur_M > 0) { 
        // Cat timp mai este loc
        // Gaseste obiectul
        max = -1;
        for (int i = 0; i < n; i++)
            if ((folosit[i] == 0) &&
                ((max == -1) || ((float)v[i] / m[i] > (float)v[max] / m[max])))
                max = i;
 
        folosit[max] = 1; // Obiectul i este folosit
        cur_M -= m[max]; // Scade capacitatea ramasa
        tot_v += v[max]; // Creste valoarea totala

        if (cur_M >= 0) {
            printf("Obiectul %d (%d, %dKg) adaugat. \nSpatiu ramas: %d.\n", max + 1, v[max], m[max], cur_M);
        } else {
            printf("Adaugat %d%% din obiectul %d (%d, %dKg)\n", (int)((1 + (float)cur_M / m[max]) * 100),
                                                                    max + 1, v[max], m[max]);
            tot_v -= v[max];
            tot_v += (1 + (float)cur_M / m[max]) * v[max];
        }
    }
 
    printf("Valoare totala: %.2f\n", tot_v);
}

void spectacole(int s[], int t[], int l) {
    // Sortare dupa t
    for (int i = 0; i < l - 1; i++) {
        for (int j = i; j < (l - i - 1); j++) {
            if (t[j] > t[j + 1]) {
                swap(&t[j], &t[j + 1]);
                swap(&s[j], &s[j + 1]);
            }
        }
    }

    // Selectare spectacole si afisare
    printf("\nSpectacole:\n");
    int final = s[0];
    for (int i = 0; i < l; i++) {
        if (s[i] >= final) {
            printf("Ora inceput: %d:00, Ora final: %d:00\n", s[i], t[i]);
            final = t[i];
        }
    }
}
 
int main() {
    int m[3] = {10, 30, 20};
    int v[3] = {60, 120, 100};
    int M = 50;
    int n = sizeof(m) / sizeof(m[0]);

    int s[6] = {10, 11, 12, 14, 16, 17};
    int t[6] = {11, 13, 13, 18, 17, 19};
    int l = sizeof(t) / sizeof(t[0]);

    printf("--- Subiectul 2 ---\n\n");
    rucsac(m, v, M, n);
    printf("\n--- Subiectul 3 ---\n");
    spectacole(s, t, l);
    
    return 0;
}