#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <vector <ll>> hijos;
int calcularCant (int hijos, int T){

	int cant=(hijos*T)/100;
	if ((hijos*T)%100) cant++;
	return cant; 
}
int dfs(int nodo, int T){
	if (!hijos[nodo].size()) return 1; 
	multiset <int> valores; 
	for (auto i:hijos[nodo]) valores.insert(dfs(i,T)); 
	int its=0, cant=calcularCant((int)hijos[nodo].size(), T); 
	int res=0;
	for (auto i:valores){
		res+=i; 
		its++;
		if (its==cant) break;
	}
	return res;
}
int petitorios(int T, vector<int> &jefes){
	int n=jefes.size();
	hijos.resize(n+1); 
	for (int i=0;i<n;i++){
		hijos[jefes[i]].push_back(i+1);
	}
	return dfs(0,T); 
}
