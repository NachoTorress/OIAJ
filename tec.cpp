#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
struct arista{
	int hacia;
	int desde;
};
vector <vector <int>> ady;
vector <arista> edges;
vector <int> ID;
vector <vector <int>> comp;
vector <long long> dist;
vector <int> padres;
int n;
bool unionFind(int a, int b){
	int x=ID[a], y=ID[b];
	if (x==y) return false;
	if (comp[x].size()<comp[y].size()){
		swap(a,b); swap(x,y);
	}
	for (auto i:comp[y]){
		ID[i]=x;
		comp[x].push_back(i);
	}
	return true;
}
void BFS (int nodo){
	dist[nodo]=0;
	padres[nodo]=nodo;
	queue <int> cola;
	cola.push(nodo);
	while (cola.size()){
		int nodoAct=cola.front(); cola.pop();
		for (auto i:ady[nodoAct]){
			if (dist[nodoAct]+1<dist[i]){
				dist[i]=dist[nodoAct]+1;
				cola.push(i);
				padres[i]=nodoAct;
			}
		}
	}
}
void tablero(int N, vector<int> &A, vector<int> &B) {
	// SOLUCION
 n=N;
	ID.resize(N+1), comp.resize(N+1); ady.resize(N+1); dist.resize(N+1, INF); padres.resize(N+1);
	for (int i=1;i<=N;i++){
		comp[i].push_back(i);
		ID[i]=i;
	}
	for (int i=0;i<A.size();i++){
		if (unionFind(A[i], B[i])){
			ady[A[i]].push_back(B[i]);
			ady[B[i]].push_back(A[i]);
		}
	}
	for (int i=1;i<=N;i++){
		if (dist[i]==INF) BFS(i);
	}
}
int con_quien_comercio(vector<int> &controlados){
	vector <bool> vis (n+1, false);
	queue <int> cola;
	for (auto i:controlados){
	 vis[i]=true;
	 cola.push(i);
	}
	while (cola.size()){
		int nodoAct=cola.front(); cola.pop();
		for (auto i:ady[nodoAct]) if(!vis[i]) return i;
	}
	return -1;
}
