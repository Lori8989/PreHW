// Author: justin0u0
#include <iostream>
#include <stdlib.h>
#include "function.h"
using namespace std;


Graph::Graph(int n){
	this->numberOfVertices = n;
	this->adjacencyList = (Vertex**)malloc(sizeof(Vertex*)*n);
	this->vertexInfo = (int*)malloc(sizeof(int)*n);

	for(int i=0 ; i<n ; i++ ){
		this->adjacencyList[i] = new Vertex(i);
		this->vertexInfo[i] = -1;
	}
}

void Graph::addEdge( int sourse, int des ){
	Vertex *tmp = this->adjacencyList[sourse];
	Vertex *dest = new Vertex(des);

	dest->nextVertex = tmp->nextVertex;//?????????????????????????????
	tmp->nextVertex = dest;
}
bool Graph::dfs( int vtxidx ){}
bool Graph::solver(){
	int n = this->numberOfVertices;
	Vertex **ptrarr = this->adjacencyList;
	int *info = this->vertexInfo;

	for(int i=0 ; i<n ; i++ ){
		Vertex *tmp = ptrarr[i];
		if( info[tmp->index] == -1 )
			info[tmp->index]=0;
	
		while(tmp->nextVertex != NULL){
			tmp = tmp->nextVertex;

			if(info[tmp->index] == -1)
				info[tmp->index] = !info[i];
			if(info[tmp->index] == info[i])
				return 0;
		}
	}
	return 1;
}
Graph::~Graph(){}










int main() {
	// iostream optimize
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	Graph G(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		G.addEdge(x, y);
		G.addEdge(y, x);
	}
	if (G.solver())
		cout << "Possible" << endl;
	else
		cout << "Not Possible" << endl;
	return 0;
}
