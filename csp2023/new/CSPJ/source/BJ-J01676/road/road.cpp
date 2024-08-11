#include <bits/stdc++.h>
using namespace std;
int a,b,y,m,t,aa[100000],bb[100000];
int main(){
ofstream outFile("apple.out");
ifstream inFile("apple.in");
inFile>>a>>b;
for(int i=0;i<a-1;i++){
	inFile>>aa[i];
	y+=aa[i];
}
for(int i=0;i<a;i++){
	inFile>>bb[i];
}
outFile<<ceil(y/b)*bb[0];
inFile.close();
outFile.close();
return 0;
}
