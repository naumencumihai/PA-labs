#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

struct Vertex {
    char label;
    bool visited;
};

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

struct Vertex* lstVertices_BFS[MAX];
struct Vertex* lstVertices_DFS[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;

// Functii pentru queue

void insert(int data) {
    queue[++rear] = data;
    queueItemCount++;
}

int removeData() {
    queueItemCount--;
    return queue[front++]; 
}

bool isQueueEmpty() {
    return queueItemCount == 0;
}

// Functii pentru Graf

void addVertex(char label) {
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    vertex->label = label;  
    vertex->visited = false;     
    lstVertices_BFS[vertexCount++] = vertex;
}

void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
    printf("%c ", lstVertices_BFS[vertexIndex]->label);
}       

int getAdjUnvisitedVertex(int vertexIndex) {
    int i;
	
    for(i = 0; i < vertexCount; i++) {
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices_BFS[i]->visited == false)
            return i;
    }
    return -1;
}

void BFS() {
    int i;

    //mark first node as visited
    lstVertices_BFS[0]->visited = true;

    //display the vertex
    displayVertex(0);   

    //insert vertex index in queue
    insert(0);
    int unvisitedVertex;

    while(!isQueueEmpty()) {
        //get the unvisited vertex of vertex which is at front of the queue
        int tempVertex = removeData();   

        //no adjacent vertex found
        while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {    
            lstVertices_BFS[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            insert(unvisitedVertex);               
        }	
    }   

    //queue is empty, search is complete, reset the visited flag        
    for(i = 0; i < vertexCount; i++) {
        lstVertices_BFS[i]->visited = false;
    }    
}

void DFS(int i) {
    displayVertex(i);

    lstVertices_DFS[i]->visited = true;

    for (int j = 0; j < n; j++) 
}

int main() {
    int i, j;

    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++)
            adjMatrix[i][j] = 0;
    }



    addVertex('A');  // 0
    addVertex('B');  // 1
    addVertex('C');  // 2
    addVertex('D');  // 3
    addVertex('E');  // 4
    addVertex('F');  // 5  
    addVertex('G');  // 6
    addVertex('H');  // 7
    addVertex('I');  // 8
    addVertex('J');  // 9
    
    addEdge(0, 1); 
    addEdge(0, 2);
    addEdge(0, 7); 
    addEdge(1, 3);
    addEdge(1, 4); 
    addEdge(1, 7); 
    addEdge(1, 8); 
    addEdge(2, 3);   
    addEdge(3, 4);
    addEdge(3, 9);
    addEdge(4, 5);
    addEdge(4, 6);
    addEdge(5, 6);
    addEdge(7, 8);
    addEdge(8, 0); 
        
    printf("\nBFS: ");
    BFS();

    printf("\nDFS: ");
    DFS(0);

    return 0;
}