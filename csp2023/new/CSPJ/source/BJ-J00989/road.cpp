#include<iostream>
#include<fstream>
using namespace std;
int s_=0,ans=100001,n,d;
int *v,*a;
void S(int s,int o,int pri,int p){
    if(p==n){
        ans=min(ans,pri);
        return;
    }
    for(int i=max(0,v[p]-d*o);i<=s;++i){
        S(s-v[p],o+i-v[p]/d,pri+i*a[p],p+1);
    }
}
int main(){
    ifstream fin("road.in");
    ofstream fout("road.out");
    fin>>n>>d;
    v=new int[n+1];
    a=new int[n+1];
    for(int i=1;i<=n;++i){
        fin>>v[i];
        s_+=v[i];
    }
    for(int i=1;i<=n;++i) fin>>a[i];
    S(s_,0,0,1);
    fout<<ans-1;
    return 0;
}
