#include <iostream>
#include <fstream>
using namespace std;
int n,m,k,rs[20001],ra[20001],ro[20001],t,a[9996][9996];
int dfs(int i,int j,int t){
    for(int k=1;k<=m;k++){
        if(a[rs[i]][rs[j]] && a[rs[k]][rs[k]){
            t=max(maxx,k);
            dfs(a[rs[k][rs[k]);
        }
    }
}
int main(){
    ifstream inFile("bus.in");
    inFile>>n>>m>>k;
    for(int i=1;i<=m;i++){
        inFile>>rs[i]>>ra[i]>>ro[i];
        a[rs[i]][ra[i]]=ro[i];
    }
    inFile.close();
    dfs(i,j,t);
    ofstream outFile("bus.out");
    outFile<<t;
    outFile.close();
    return 0;
}
