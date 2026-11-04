#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long 
#define ff first 
#define sc second
using namespace std;

int cajero(vector<int> &billetes, int M, int C, vector<int> &respuesta){
	vector <pair<int,int>> cant (M+1,{0,0}); 
	cant[0]={1,0};
	for (int i=0;i<billetes.size();i++){
		for (int j=0;j<C;j++){
			for (int k=M;k>=billetes[i];k--){
				if (k-billetes[i]>=0 && cant[k-billetes[i]].ff ){
					if (cant[k-billetes[i]].ff+1>cant[k].ff) cant[k]={cant[k-billetes[i]].ff+1, billetes[i]};
				}
			}
		}
	}
	if (!cant[M].ff) return 0;

	map <int,int> indice; 
	for (int i=0;i<billetes.size();i++) indice[billetes[i]]=i; 
	respuesta.resize(billetes.size(),0);
	int numAct=M;
	while (numAct){
		respuesta[indice[cant[numAct].sc]]++; 
		numAct=numAct-cant[numAct].sc;
	}
	return cant[M].ff-1;
}
