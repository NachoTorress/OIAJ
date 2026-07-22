#include <iostream>
#include <string>
#include <vector>

using namespace std;

int vuelto(int V){
	int res=0, val=V; 
	res+=val/100; val%=100;
	res+=val/50; val%=50;
	res+=val/25; val%=25;
	res+=val/10; val%=10;
	res+=val/5; val%=5;
	res+=val/2; val%=2;
	res+=val;
	return res;
}
