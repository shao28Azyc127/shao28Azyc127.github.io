#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
int minn=-1;
bool viss[10001];
vector<int> vec[10001];
void dfs(int now,int cur){
    if(now==n){
        if(minn==-1) minn=cur;
        else minn=min(minn,cur);
        return ;
    }
    for(int i=0;i<vec[now].size();i++){
        if(viss[vec[now][i]]==0){
            viss[vec[now][i]]=1;
            dfs(vec[now][i],cur+1);
            viss[vec[now][i]]=0;
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >>n >>m >>k;
    int qp=0;
    for(int i=1;i<=m;i++){
        int l,r,v;
        cin >>l >>r >>v;
        vec[l].push_back(r);
        if(v==0) qp++;
    }
    if(qp!=m)cout <<"-1";
    else{
        dfs(1,0);
        if(minn%k!=0) minn+=(k-(minn%k));
        cout <<k+minn;
    }
    return 0;
}
