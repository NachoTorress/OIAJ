#include <bits/stdc++.h>
using namespace std;
int bici(vector<int> &c){
	int b; 
	int sum=0; 
	for (auto i:c) sum+=i; 
	b=sum/c.size(); 
	sort (c.rbegin(), c.rend()); 
	int res=0; 
	for (auto i:c) if (i>b) res+=i-b; 
	return res; 
}
