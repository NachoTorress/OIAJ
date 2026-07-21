#include <bits/stdc++.h>
#define ff first
#define sc second
using namespace std;
vector<int> inout(vector<int> &t, vector<int> &e){
	vector <pair<int,int>> flechas; 
	flechas.push_back({1,2}); 
	int nodo=3, flecha=2; 
	for (int i=0;i<t.size();i++){
		int op=t[i], x=e[i]; x--; 
		if (op==1){
			flechas.push_back({flechas[x].ff,nodo});
			flechas[x].ff=nodo;
			nodo++, flecha++;
		}
		else{
			flechas.push_back({flechas[x].ff,nodo}); 
			flechas.push_back({nodo,flechas[x].sc});
			flecha+=2;
			nodo++;
		}
	}
	vector <int> resp(nodo-1);
	for (auto i:flechas){
		resp[i.ff-1]++; resp[i.sc-1]--;
	}
	return resp;
}
