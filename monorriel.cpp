#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ff first 
#define sc second
using namespace std;

int monorriel(int C, vector<int> &a, vector<int> &b, vector<int> &reservas) {
    // AQUI SE DEBE IMPLEMENTAR LA SOL
	vector <pair <int,int>> subidas; 
	for (int i=0;i<a.size();i++){
		subidas.push_back({a[i], i}); 
	}
	sort(subidas.begin(), subidas.end()); 
	reservas.resize(reservas.size(), 1);
	multiset <pair<int,int>> bajadas;
	for (auto i:subidas){
		while (!ms.empty() && bajadas.begin()->first <=i.ff)  
			ms.erase(ms.begin());
		bajadas.insert({b[i.sc], i.sc}); 
		if (bajadas.size()>C){
			reservas[prev(ms.end()).sc]=0;
			ms.erase(prev(ms.end()));
		}

	}
    int tot=0;
    for (auto i:reservas) tot+=i; 
    return tot;
}
