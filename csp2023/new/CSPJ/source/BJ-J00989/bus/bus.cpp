#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,k;
int *u,*v,*a,*ans;
int main(){
    ifstream fin("bus.in");
    ofstream fout("bus.out");
    fin>>n>>m>>k;
    u=new int[m+1];
    v=new int[m+1];
    a=new int[m+1];
    ans=new int[m+1];
    for(int i=1;i<=m;++i) fin>>u[i]>>v[i]>>a[i];
    for(int i=1;i<=n;++i){
        ans[i]=100001;
        for(int j=1;j<=m;++j){
            if(v[j]==i&&ans[v[j]]!=-1){
                if(ans[u[j]]>=a[j]) ans[i]=min(ans[i],ans[u[j]]+k);
            }
        }
        if(ans[i]==100001) ans[i]=-1;
    }
    fout<<ans[n]<<endl;
    fin.close();
    fout.close();
    return 0;
}
