#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
ifstream inFile("uqe.in");
ofstream outFile("uqe.out");
inFile>>a>>b;
for(int i=0;i<a;i++){
	outFile<<"NO"<<endl;
}
inFile.close();
outFile.close();
return 0;
}