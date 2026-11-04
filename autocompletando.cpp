#include <bits/stdc++.h>
using namespace std;
int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto){
	int i=0; 
	map <string, int> indices; 
	for (auto j:r1){
		if (!indices.count(j)) indices[j]=i, i++;
	}
	for (auto j:r2){
		if (!indices.count(j)) indices[j]=i, i++;
	}
	for (auto j:r3){
		if (!indices.count(j)) indices[j]=i, i++;
	}
	vector <string> vecTexto; 
	string aux="";
	for (auto j:texto){
		if (j!=' ') aux+=j; 
		else {
			if (!indices.count(aux)) indices[aux]=i, i++;
			vecTexto.push_back(aux); 
			aux="";
		}
	}
	vecTexto.push_back(aux);
	if (!indices.count(aux)) indices[aux]=i, i++;
	map <pair <int,int>, set <int>> diccionario; 
	for (int j=0;j<r1.size();j++){
		int in1=indices[r1[j]], in2=indices[r2[j]], in3=indices[r3[j]]; 
		diccionario[{in1,in2}].insert(in3);
	}
	int nec=2; 
	int p1=indices[vecTexto[0]], p2=indices[vecTexto[1]]; 
	for (int j=2;j<vecTexto.size();j++){
		if (!diccionario[{p1,p2}].count(indices[vecTexto[j]])) nec++; 
		p1=p2, p2=indices[vecTexto[j]];
	}
	return !(nec>K);
}
