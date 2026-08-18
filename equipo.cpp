#include <bits/stdc++.h>
using namespace std; 
#define ll int
#define ff first
#define sc second
struct Nodo {
	array <pair<ll,ll>,26> hijo;
	Nodo(){
		for (int i=0;i<26;i++) hijo[i]={-1,0};
	}
};
string strMax; ll numMax; 
vector <Nodo> trie;
void insertar(string pal){
	ll nodo=0;
	string res="";
	for (int i=0;i<pal.size();i++){
		ll x=pal[i]-'a';
		res+=pal[i];
		if (trie[nodo].hijo[x].ff==-1){
			trie[nodo].hijo[x]={trie.size(),1}; 
			trie.push_back(Nodo());
		}
		else {
			trie[nodo].hijo[x].sc++;
		ll val=trie[nodo].hijo[x].sc*(i+1)*(i+1);
			if (val>numMax) strMax=res, numMax=val;
		}
		nodo=trie[nodo].hijo[x].ff;
	}
}
int main(){
	ll p, n; cin>>p>>n;
	strMax="", numMax=0;
	trie.reserve(500*5000+5);
	trie.push_back(Nodo()); 
	for  (int i=0;i<n;i++){
		string respuestas; 
		cin>>respuestas;
		insertar(respuestas);
	}
	cout<<numMax<<endl<<strMax;
}
