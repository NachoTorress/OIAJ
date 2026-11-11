#include <bits/stdc++.h>
using namespace std;
#define sc second
vector<int> generala(int a, int b, int c, int d, int e){
	vector <int> nums= {a,b,c,d,e}; 
	sort (nums.begin(), nums.end()); 
	vector <int> resp (10,0); 
	map <int,int> cants;
	for (auto i:nums) resp[i-1]+=i, cants[i]++;
	if (nums==vector<int>{1,2,3,4,5}) resp[6]=20;
	if (nums==vector<int>{2,3,4,5,6}) resp[6]=20;
	if (nums==vector<int>{1,3,4,5,6}) resp[6]=20;
	if (cants.size()==2){
		for (auto i:cants) if (i.sc==3) resp[7]=30;
	}
	for (auto i:cants){
		
	 if (i.sc>=4) resp[8]=40; 
	 if (i.sc==5) resp[9]=50;
	}
	return resp;
}
