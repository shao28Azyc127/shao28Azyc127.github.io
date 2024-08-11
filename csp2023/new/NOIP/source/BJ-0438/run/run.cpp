#include <bits/stdc++.h>
using namespace std;
int sed[5][15]={
	{5,3,4,0,1,2},
	{11,0,0,1,0,2,0,0,0,0,1,-1},
	{5,2,0,0,8,-1},
	{6,0,8,0,0,1,-1},
	{10,0,1,0,1,0,1,0,1,1,-1}
	
};
int out(int k){
	bitset<32> s;
	s = k;
	cout<<s<<"\n";
}
int mi(int index){
	int k = 0;
	for(int i=1;i<=sed[index][0];i++){
		k = (k+1)<<(sed[index][i]+1);
		//out(k);
	}
	out(k);
	return k;
}
int main(){
	for(int i=0;i<=4;i++)
		printf("%c",mi(i));
	return 0;
}