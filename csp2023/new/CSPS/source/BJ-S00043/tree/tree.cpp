#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=N*2;
int h[N],e[M],ne[M],idx;
int n,maxday;
struct Field{
    int a;
    unsigned int b;
    int c;
}field[N];
bool planted[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int day){
    planted[u]=true;
    maxday=max(day,maxday);
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!planted[j]) dfs(j,day+1);
        day++;
    }
    return day;
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    memset(h,-1,sizeof h);
    cin>>n;
    //for(int i=0;i<n;i++){
    //    cin>>field[i].a>>field[i].b>>field[i].c;
    //}
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1,1);
    cout<<maxday;
    return 0;
}
