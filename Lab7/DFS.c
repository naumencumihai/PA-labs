#include<stdio.h>

#define MAX 50

void DFS(int);
void BFS();

int G[MAX][MAX]; // Matricea de adiacenta
int visited[MAX];
int n;

// queue
int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

// Functii pentru queue

void insert(int data) {
    queue[++rear] = data;
    queueItemCount++;
}

int removeData() {
    queueItemCount--;
    return queue[front++]; 
}

int isQueueEmpty() {
    return queueItemCount == 0;
}

int getAdjUnvisited(int index) { // Noduri adiacente nevizitate
	for (int i = 0; i < n; i++) {
		if (G[index][i] == 1 && !visited[i])
			return i;
	}
	return -1;
}
 
void main() {
    printf("Numar de noduri: ");
	scanf("%d", &n);

	printf("\nMatricea de adiacenta:\n");
   
	for(int i = 0; i < n; i ++)
       for(int j = 0; j < n; j ++)
			scanf("%d", &G[i][j]);
 
   	for(int i = 0; i < n; i++) {
        visited[i] = 0;
	}

	printf("\nDFS:\n");
    DFS(0);

	for(int i = 0; i < n; i++) {
		visited[i] = 0;
	}

	printf("\n\nBFS:\n");
	BFS();
	printf("\n");
}
 
void DFS (int i) {
	printf("%d ", i);

    visited[i] = 1;
	
	for(int j = 0; j < n; j++)
       if(!visited[j] && G[i][j] == 1)
            DFS(j);
}

void BFS () {
	visited[0] = 1;

	printf("0 ");

	insert(0);
	int unvisited;

	while (!isQueueEmpty()) {
		// nodul de la inceputul queue-lui
		int tmp = removeData();

		while ((unvisited = getAdjUnvisited(tmp)) != -1) {
			visited[unvisited] = 1;
			printf("%d ", unvisited);
			insert(unvisited);
		}
	}
}