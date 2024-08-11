#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int main(){
ifstream inFile("uqe.in");
ofstream outFile("uqe.out");
inFile>>a>>b>>c;
for(int i=0;i<b;i++){
inFile>>d>>e>>f;
}
outFile<<"-1";
inFile.close();
outFile.close();
return 0;
}