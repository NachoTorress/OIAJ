#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n; cin>>n; 
	string str="";
	for (int i=0;i<n;i++){
		char aux; cin>>aux; str+=aux; 
	}
	string clave; cin>>clave;
	ll m=clave.size();
	bool resp=0; char ord; 
	for (int i=0;i<str.size()-m+1;i++){
		if (str.substr(i,m)==clave) resp=1, ord='I';
	}
	if (resp){
		cout<<"SI"<<endl<<ord;
		return 0;
	}
	reverse(str.begin(),str.end());
	for (int i=0;i<str.size()-m+1;i++){
		if (str.substr(i,m)==clave) resp=1, ord='D';
	}
	if (resp){
		cout<<"SI"<<endl<<ord;
		return 0;
	}
	else cout<<"NO";
}
