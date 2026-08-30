#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
int main(){
	ll n, pals; cin>>n>>pals; 
	vector <string> cols(n,""), filas(n,""); 
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			char letra; cin>>letra; 
			cols[j]+=letra, filas[i]+=letra; 
		}
	}
	vector <string> palabras(pals); 
	for (auto &i:palabras) cin>>i; 
	map <ll,char> resp; 
	for (int i=0;i<pals;i++){
		string palAct=palabras[i];
		for (auto j:filas){
			if (j.find(palAct)!=string::npos) resp[i+1]='E'; 
			else{
				reverse(j.begin(),j.end()); 
				if (j.find(palAct)!=string::npos) resp[i+1]='O'; 
			}
		}
		for (auto j:cols){
			if (j.find(palAct)!=string::npos) resp[i+1]='S'; 
			else{
				reverse(j.begin(),j.end()); 
				if (j.find(palAct)!=string::npos) resp[i+1]='N'; 
			}
		}
	}
	for (auto i:resp) cout<<i.first<<" "<<i.second<<endl;
}
	
