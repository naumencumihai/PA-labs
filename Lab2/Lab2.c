// Laborator 2 - PA
// Naumencu Mihai
// 322 CD

#include <stdio.h>

void turnurile_din_hanoi(int n, char sursa, char destinatie, char auxiliar) {
	if (n == 1) {
		printf("	Se muta discul 1 din %c in %c\n", sursa, destinatie);
		return;
	}
	turnurile_din_hanoi(n - 1, sursa, auxiliar, destinatie);
	printf("	Se muta discul %d din %c in %c\n", n, sursa, destinatie);
	turnurile_din_hanoi(n - 1, auxiliar, destinatie, sursa);
}

int maxim(int vector[], int stanga, int dreapta) {
	if (dreapta - stanga == 1)
   		return vector[stanga];
   	int mijloc = (stanga + dreapta) / 2;
   	int u = maxim(vector, stanga, mijloc);
   	int v = maxim(vector, mijloc, dreapta);
   	return u > v ? u : v;    
}

void combina(int vector[], int stanga, int mijloc, int dreapta) {
	int i, j, k;
	int n1 = mijloc - stanga + 1;
	int n2 = dreapta - mijloc;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = vector[stanga + i];
	for (j = 0; j < n2; j++)
		R[j] = vector[mijloc + 1 + j];
	i = 0;
	j = 0;
	k = stanga;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vector[k] = L[i];
			i++;
		} else {
			vector[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		vector[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		vector[k] = R[j];
		j++;
		k++;
	}
}

void interclasare(int vector[], int stanga, int dreapta) {
	if (stanga < dreapta) {
		int mijloc = stanga + (dreapta - stanga) / 2;
		interclasare(vector, stanga, mijloc);
		interclasare(vector, mijloc + 1, dreapta);

		combina(vector, stanga, mijloc, dreapta);
	}
}

int cautarebinara(int vector[], int stanga, int dreapta, int x)  { 
    if (dreapta >= stanga) {
        int mijloc = stanga + (dreapta - stanga) / 2; 
        if (vector[mijloc] == x) 
            return mijloc; 
        if (vector[mijloc] > x) 
            return cautarebinara(vector, stanga, mijloc - 1, x); 
        return cautarebinara(vector, mijloc + 1, dreapta, x); 
    } 
    return -1;
}

int aparitii(int vector[], int stanga, int dreapta, int x) {
	if ((stanga > dreapta) || (stanga == dreapta && vector[stanga] != x))
		return 0;
	if (stanga == dreapta && vector[stanga] == x)
		return 1;
	return aparitii(vector, stanga, (stanga + dreapta) / 2, x) +
			aparitii(vector, 1 + (stanga + dreapta) / 2, dreapta, x);
}

int main () {
	printf("(1) Mutari turnurile din Hanoi:\n");
	turnurile_din_hanoi(3, 'A', 'B', 'C');

	int vector2[] = {3, 2, 5, 2, 4};
	int dim2 = sizeof(vector2) / sizeof(int);
	printf("\n(2) Maximul elementor din vector: %d", maxim(vector2, 0, dim2));

	int vector3[] = {3, 2, 1, 4, 3, 5, 2};
	int dim3 = sizeof(vector3) / sizeof(int);
	interclasare(vector3, 0, dim3);
	printf("\n\n(3) Vectorul sortat prin interclasare: ");

	for (int i = 0; i < dim3; i++) {
		printf("%d ",vector3[i]);
	}

	int vector4[] = {1, 3, 4, 5, 7, 8, 9}, x4 = 3;
	int dim4 = sizeof(vector4) / sizeof(int);
	printf("\n\n(4) Elementul %d se afla pe pozitia %d", x4, cautarebinara(vector4, 0, dim4, x4));

	int vector5[] = {2, 1, 3, 1, 1, 4, 2, 1, 8, 1}, x5 = 1;
	int dim5 = sizeof(vector5) / sizeof(int);
	printf("\n\n(5) Numar aparitii element %d: %d\n\n", x5, aparitii(vector5, 0, dim5, x5));
}