#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct arista {
	int desde;
	int hacia;
	int costo;
};
vector <arista> edges;
vector <vector <int>> ady;
int corto(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    arista a; a.costo=0; a.desde=0;a.hacia=0;
    edges.resize(t.size()*2+5,a );
    ady.resize(t.size()+3);
   	int cantNodos=t.size()+2;
   	edges[0].costo=1, edges[0].hacia=2; edges[0].desde=1;
   	int s=1;
   	for (int i=0;i<t.size();i++){
   		int nodoAct=i+3;
   		if (t[i]==1){
   			arista flecha=edges[e[i]-1];
   			edges[e[i]-1].desde=nodoAct;
   			arista aIns;
   			aIns.costo=s+1;
   			s++;
   			aIns.desde=flecha.desde;
   			aIns.hacia=nodoAct;
   			edges[s-1]=aIns;
		   }
		   else if (t[i]==2){
			arista flecha=edges[e[i]-1];
			arista aIns;
			aIns.costo=s+1;
			aIns.desde=flecha.desde;
			aIns.hacia=nodoAct;
			edges[s]=aIns;
			aIns.costo=s+2;
			aIns.desde=nodoAct;
			aIns.hacia=flecha.hacia;
			edges[s+1]=aIns;
			s+=2;
		   }
	   }
    for (int i=0;i<edges.size();i++){
    	arista flecha =edges[i];
    	ady[flecha.desde].push_back(flecha.hacia);
	}
	int n=t.size()+2;
	int INF=1e9;
	queue <int>  pq;
    ;
    vector <long long> dist(n+1, INF); // INF=valor muy alto
    pq.push(1); //otra manera de insertar un pair
    dist[1] = 0;
    while(pq.size())
    {
    	int nodo=pq.front(); pq.pop();
    	for (auto i:ady[nodo]){
    		if (dist[nodo]+1<dist[i]){
    			dist[i]=dist[nodo]+1;
    			pq.push(i);
			}
		}
	}
		return dist[2];
}
