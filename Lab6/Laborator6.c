/*
Laborator 6 - PA
Naumencu Mihai
322 CD
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int x1[10], n;  // P1
int x2[20], n2, nrsol = 0, v[20];  // P2
int n3, v3[100], sol;  // P3

void Afisare1() {
    for(int j = 1; j <= n; j++)
        printf("%d ", x1[j]);    
    printf("\n");
}

void Afisare2() {
    int i;
    for(i = 1; i <= n2; i++)
        if (x2[i] == 1) 
            printf("%d ", v[i]);;
        printf("\n");
     nrsol++;
}

void Afisare3() {
	int i, j, x; 
 	sol++; 
 	printf("\n Solutia %d \n", sol);
 	for (i = 1; i <= n3 ; i++) {
 		for (j = 1; j <= n3; j++) 
 			if (v3[i] == j) 
 				printf("D ");
 			else 
 				printf("* ");
 		printf("\n");
 	}
}

int Valid1(int k) {
    for(int i = 1; i < k; ++i)
        if(x1[k] == x1[i])
            return 0;
    return 1;
}

int Valid3(int k) {
	int i; 
 	for (i = 1; i <= k - 1; i++) 
 		if (v3[i] == v3[k] || abs(v3[k] - v3[i]) == (k - i)) 
 			return 0; 
 	return 1;
}

void Back1(int k) {
    for(int i = 1 ; i <= n ; ++i) {
        x1[k] = i;
        if(Valid1(k))
            if(k == n)
                Afisare1();
            else
                Back1(k + 1);
    }
}

void Back2(int k) {
  int i;
    for(i = 0; i <= 1; i++) {
        x2[k]=i;
        if (k == n2) 
            Afisare2();
        else 
            Back2(k+1);
    }
}

void Back3(int k) {
	int i; 
 	for (i = 1; i <= n3; i++) {
 		v3[k] = i; 
 		if (Valid3(k) == 1) {
 			if (k == n3) 
 				Afisare3();
 			else 
 				Back3(k + 1); 
 		} 
 	} 
}

int main() {
    // Problema 1 - Permutari
    printf("\n=== Problema 1 ===\n\nn = ");
    scanf("%d",&n);
    printf("\n");
    Back1(1);

    // Problema 2 - Submultimi
    printf("\n=== Problema 2 ===\n\nn = "); 
    scanf("%d",&n2);
    printf("\nMultime = ");
    for(int i = 1 ; i <=n2 ;i++)
        scanf("%d",&v[i]);
    Back2(1);
    printf("\nAvem %d solutii\n",nrsol);

    // Problema 3 - Dame
    printf("\n=== Problema 3 ===\n\nn = "); 
    scanf("%d", &n3);
    Back3(1);
    return 0;
}
