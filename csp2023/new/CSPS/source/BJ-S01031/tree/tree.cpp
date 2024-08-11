#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005],h[100005];
int v[20005][20005],f[100005],n;
void dfs(int x,long long d){
    if(x==n){
        int f=0;
        for(int i=1;i<=n;i++){
            if(h[i]<a[i]){
                f=1;
                break;
            }
        }
        if(f==0){
            cout<<d-1;
            exit(0);
        }
        else{
            int flag=0;
            while(flag==0){
                f=1;
                for(int i=1;i<=n;i++){
                    h[i]+=max(b[i]+d*c[i],1ll);
                    if(h[i]<a[i]) f=0;
                }
                d++;
                flag=f;
            }
            cout<<d-1;
            exit(0);
        }
    }
    for(int k=1;k<=n;k++){
        if(f[k]==0&&(k==1&&x==0)) continue;
        for(int i=1;i<=n;i++){
            if(v[k][i]==1&&f[i]==0){
                f[i]=1;
                for(int i=1;i<=n;i++){
                    if(f[i]==1)h[i]+=max(b[i]+d*c[i],1ll);
                }
                d++;
                dfs(x+1,d);
            }
        }
    }

}
int main(){
    freopen("tree.in","r","stdin");
    freopen("tree.out","w","stdout");
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        v[x][y]=v[y][x]=1;
    }
    dfs(0,0);
    return 0;
}