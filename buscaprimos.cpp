#include <bits/stdc++.h>
using namespace std;
bool esPrimo(int n){
	if (!n) return false;
	if (n==1) return false;
	for (int i=2;i<=n/2;i++) if (n%i==0) return false; 
	return true;
}
vector<int> buscaprimos(string &s){
	string nums=s;
	vector <int> resp (4,0); 
	for (int i=1;i<=4;i++){
		if (i>s.size()) break;
		for (int j=0;j<=nums.size()-i;j++){
			string aux=nums.substr(j,i);
			if(aux[0]!='0') resp[i-1]+=esPrimo(stoi(aux));
		}
	}
	return resp;
}
