// Laborator 7 - PA
// Naumencu Mihai
// 322 CD

#include <stdio.h>
#include <stdlib.h>

struct nod {
	char nume;
	char parinte;
	char culoare;
	int d, f;
	struct nod** legaturi;
};

// Create a node
struct nod* createNode(char nume) {
	struct nod* newNode = malloc(sizeof(struct nod));
	newNode->nume = nume;
	newNode->parinte = NULL;
	newNode->culoare = 'a';
	newNode->d = 0;
	newNode->f = 0;
	newNode->next = NULL;
	return newNode;
}

struct Graph {
	int numarNoduri;
	struct node** listaNoduri;
};

// Create graph
struct Graph* createGraph(int dimensiune) {
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numarNoduri = dimensiune;
	graph->listaNoduri = malloc(dimensiune * sizeof(struct node*));

	for (int i = 0; i < dimensiune; i++) {
		graph->listaNoduri[i] = NULL;
	}
	return graph;
}

// DFS algo
void DFS(struct Graph* graph, int vertex) {
	struct node* adjList = graph->adjLists[vertex];
	struct node* temp = adjList;

	graph->visited[vertex] = 1;
	printf("Visited %d \n", vertex);

	while (temp != NULL) {
	int connectedVertex = temp->vertex;

	if (graph->visited[connectedVertex] == 0) {
		DFS(graph, connectedVertex);
	}
	temp = temp->next;
	}
}




// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
	// Add edge from src to dest
	struct node* newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	// Add edge from dest to src
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
	int v;
	for (v = 0; v < graph->numVertices; v++) {
		struct node* temp = graph->adjLists[v];
		printf("\n Adjacency list of vertex %d\n ", v);
		while (temp) {
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
	printf("\n");
	}
}

int main() {
	struct Graph* graph = createGraph(10);
	// A = 0, B = 1, C = 2, D = 3, E = 4, F = 5,
	// G = 6, H = 7, I = 8, J = 9
	addEdge(graph, 0, 1); 
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 7);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 7);
	addEdge(graph, 1, 8);
	addEdge(graph, 3, 9);
	addEdge(graph, 3, 4);
	addEdge(graph, 4, 5);
	addEdge(graph, 4, 6);
	addEdge(graph, 5, 6);
	addEdge(graph, 8, 0);
	addEdge(graph, 7, 8);
	addEdge(graph, 2, 3);
	
	printGraph(graph);

	DFS(graph, 0);

	return 0;
}