#include <bits/stdc++.h>
using namespace std;
int sed[5][10]={
	{5,0,3,4,3,-1},
	{7,0,4,3,0,1,0,-1},
	{5,7,0,0,4,-1},
	{6,0,1,4,4,0,-1}
	
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
	return k;
}
int main(){
	for(int i=0;i<=3;i++)
		printf("%c",mi(i));
	return 0;
}