#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ff first 
#define sc second
using namespace std;
vector<int> millas(int N, vector<int> &a, vector<int> &b, vector<int> &d, vector<int> &m){
	vector <pair<int,int>> vals (N+1, {1e8,1e8}); 
	for (int i=0;i<a.size();i++){
		if (b[i]==(a[i]+1)){
			if (m[i]!=-1 && m[i]<vals[a[i]].sc) vals[a[i]]={0,m[i]}; 
			else if (m[i]==-1 && vals[a[i]].sc==1e8 && d[i]<vals[a[i]].ff) vals[a[i]]={d[i], 1e8};
		}
	}
	int resD =0, resM=0;
	for (int i=1;i<N;i++){
		if (vals[i].sc!=1e8) resM+=vals[i].sc; 
		else resD+=vals[i].ff;
	}
	return {resD,resM};
}
