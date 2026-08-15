#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void intercambiar (string &texto){
	for (auto &i:texto) if (i>=97) i-=32; else i+=32;
}
void rotar (string &texto ){
	if (!texto.size()) return;
	char pri=texto[0];
	texto=texto.substr(1,texto.size()-1); 
	texto+=pri;
}
void mayuscula (string &texto){
	for (auto &i:texto) if (i>=97) i-=32; 
}
void chauAgus (string &texto){
	int n=texto.size();
	for (int i=0;i+3<n;i++){
		string str=texto.substr(i,4); 
		mayuscula(str); 
		if (str=="AGUS"){
			texto=texto.substr(0,i)+texto.substr(i+4,texto.size()-i-4);
			break;
		}
	}
}
void borra (string &texto, string &par){
	int pos=stoi(par);
	pos--; 
	texto=texto.substr(0,pos)+texto.substr(pos+1,texto.size()-pos-1); 
}
void chau (string &texto, string &par){
	int tamPar=par.size();
	if (tamPar>texto.size()) return;
	if (!tamPar) return;
	for (int i=0;i<texto.size()-(tamPar-1);i++){
		string str=texto.substr(i,par.size()); 
		if (str==par){
			texto=texto.substr(0,i)+texto.substr(i+tamPar,texto.size()-i-tamPar);
			break;
		}
	}
}
void dup (string &texto, string &par){
	int pos=par.find('-',0); 
	int i=stoi(par.substr(0,pos)), j=stoi(par.substr(pos+1,par.size()-pos-1)); 
	i--; j--;
	texto=texto.substr(0,i)+texto.substr(i,j-i+1)+texto.substr(i,j-i+1)+texto.substr(j+1,texto.size()-j-1);
}
void invertir (string &texto, string &par){
	int pos=par.find('-',0); 
	int i=stoi(par.substr(0,pos)), j=stoi(par.substr(pos+1,par.size()-pos-1)); 
	i--; j--;
	reverse(texto.begin()+i, texto.begin()+j+1);
}
string procesatexto(string &texto, vector<string> &comandos){
	for (auto i:comandos){
		if (texto.size()>1000) return "MemoryLimitExceeded";
		if (i=="INTERCAMBIA") intercambiar(texto);
		else if (i=="BORRAULTI"){if (texto.size()) texto.pop_back();}
		else if (i=="BORRAPRI") {if (texto.size()>0) texto=texto.substr(1,texto.size()-1);}
		else if (i=="DUP") texto+=texto;
		else if (i=="ROTA") rotar(texto);
		else if (i=="INVERTIR") reverse(texto.begin(),texto.end()); 
		else if (i=="CHAUAGUS") chauAgus(texto);
		int pos=i.find('-', 0);
		if (pos==string::npos) continue;
		string comando=i.substr(0,pos); 
		string par=i.substr(pos+1,i.size()-pos-1);
		//cout<<"comando: "<<comando<<"par: "<<par<<endl;
		if (comando=="AGREGA") texto+=par;
		else if (comando=="BORRA") borra(texto,par);
		else if (comando=="CHAU") chau(texto,par);
		else if (comando=="DUP") dup(texto,par);
		else if (comando=="INVERTIR") invertir(texto,par);		
	}
	if (texto.size()>1000) return "MemoryLimitExceeded";
	return texto;
}
