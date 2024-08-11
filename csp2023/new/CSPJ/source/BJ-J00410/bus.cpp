#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,d[10001][10001];
vector<int>v[10001];
int check(int t){
    queue<int>q;
    q.push(n);
    q.push(t);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        int y=q.front();
        q.pop();
        for(int i=0;i<v[x].size();++i){
            if(d[x][v[x][i]]<=y-1){
                if(v[x][i]==1&&(y-1)%k==0&&y-1!=0) return 1;
                q.push(v[x][i]);
                q.push(y-1);
            }
        }
    }
    return 0;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>a>>b>>c;
        d[b][a]=c;
        v[b].push_back(a);
    }
    int l=1,r=1000000/k+1,mid=-1,ans=-1;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid*k)){
            r=mid-1;
            ans=mid*k;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
