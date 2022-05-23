#include<stdio.h>
#include<math.h>

int n3, v3[100], sol;

void Afisare3() {
	int i, j, x; 
 	sol++; 
 	printf("\n Solutia %d \n", sol);
 	for (i = 1; i <= n3 ; i++) {
 		for (j = 1; j <= n3; j++) 
 			if (v[i] == j) 
 				printf("D ");
 			else 
 				printf("* ");
 		printf("\n");
 	}
}

int Valid3(int k) {
	int i; 
 	for (i = 1; i <= k - 1; i++) 
 		if (v3[i] == v3[k] || abs(v3[k] - v3[i]) == (k - i)) 
 			return 0; 
 	return 1;
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
	scanf("%d",&n3);
 	Back3(1);
}