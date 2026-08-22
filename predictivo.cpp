#include <bits/stdc++.h>
using namespace std;
int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    map <string,string> pals; 
    for (int i=0;i<r1.size();i++){
    	string prev=r1[i]+" "+r2[i]; 
    	pals[prev]=r3[i];
	}
	vector <string> tex; 
	string aux="";
	for (int i=0;i<texto.size();i++){
		if (texto[i]!=' ') aux+=texto[i]; 
		else tex.push_back(aux), aux="";
	}
	tex.push_back(aux);
	bool usada=false; 
	for (int i=2;i<tex.size();i++){
		string prev=tex[i-2]+" "+tex[i-1]; 
		if (pals[prev]!=tex[i]){
			if (usada) return false; 
			usada=1;
		}
	}
	return true;
}
