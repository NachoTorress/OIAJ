#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;
vector <ll> primos;
vector <ll> compuesto;
int maxCad(int a){
	int sum=a;
	int act=a; 
	if (a==1) return 1;
	if (!compuesto[a]) return a+1;
	while (act!=1){
		if (!compuesto[act]){
			sum++;
			break;
		}
		sum+=act/compuesto[act]; 
		act=act/compuesto[act];
		}	
	return sum;
}
vector<int> cadenas(vector<int> &a){
	int maxi=-1; 
	for (auto i:a) maxi=max(maxi,i); 
	compuesto.resize(maxi+1,0); 
	for (ll i=2;i<maxi;i++){
		if (!compuesto[i]){
			primos.push_back(i); 
			for (ll j=(i*i);j<=maxi;j+=i)
				if (!compuesto[j])compuesto[j]=i;
		}
	}
	vector <int> resp; 
	for (auto i:a)resp.push_back(maxCad(i));
	return resp;	
}
