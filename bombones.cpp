#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool can (vector <int> &x, int K, ll c){
	ll sum=0, ki=0; 
	for (auto i:x){
		if (i>=c) ki++; 
		else sum+=i;
	}
	ki+=sum/c; 
	return ki>=K;
}
long long bombones(int K, vector<int> &x){
	ll sum=0; 
	for (auto i:x) sum+=i; 
	ll lo=0, hi=sum/K+1, mid; 
	while (hi-lo>1){
		mid=lo+((hi-lo)/2);
	//	cout<<"Mid: "<<mid<<endl<<lo<<endl<<hi<<endl; 
		if (can(x,K,mid)) lo=mid; 
		else hi=mid;
	}
	if (can(x,K,hi)) return hi; 
	else if (can(x,K,mid)) return mid; 
	else return lo;
}
