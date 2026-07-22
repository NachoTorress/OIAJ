#include <bits/stdc++.h>
#define ll long long
using namespace std;
string convertir (int numero, int base )
{
	ll i=0; 
	ll aux=base;
	while (aux<numero) aux*=base, i++; 
	if (numero==0) return "0";
	string res="";
	for (int j=i; j>=0;j--){
		ll flag;
		if (numero>=aux) flag=numero/aux, numero%=aux; 
		else flag=0; 
		res+=to_string(flag); 
		if (flag==0 && res.size()==1) res="";
		aux/=base;
	}
	ll flag;
		if (numero>=aux) flag=numero/aux, numero%=aux; 
		else flag=0; 
		res+=to_string(flag);
	return res; 
}
vector<string> cambiabase(vector<int> &numeros, int base){
	vector <string> res;
	for (auto i:numeros)res.push_back(convertir(i,base));
	return res;
}
