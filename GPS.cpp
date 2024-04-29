#include <bits/stdc++.h>
using namespace std;

vector <vector<pair<int, int>>> grafo;
vector<long long> gps(int N, int M, int comienzo, int fin, int K, vector<int> origen, vector<int> destino, vector<int> tiempo)
{
	grafo.resize(N+1);
    for (int i=0;i<M;i++){
    	grafo[origen[i]].push_back({destino[i], tiempo[i]});
	}
    priority_queue <pair<long long, int> > pq;
    vector <long long> dist; 
    pq.push({0, comienzo});
	vector <long long> procesado(N+1,0) ;
    while(dist.size()<K && pq.size())
    {
        long long nodo = pq.top().second;
        long long costoAct=-pq.top().first;
        if (nodo==fin)dist.push_back(-pq.top().first);  
        procesado[nodo]++;
        pq.pop();       
		if(procesado[nodo]>K) continue;    
              
        for(auto par:grafo[nodo]) 
        {      	
            long long vecino = par.first;
            long long costo = par.second;
            if (procesado[vecino]<=K)
            	pq.push({-(costoAct+costo), vecino});
			}      
            }
            return dist;
}

