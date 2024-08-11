#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[100005],cnt;
int c,t;
int s[100005];
bool vis[100005];
struct cmp{
    int x,y,z;
};
cmp f[100005];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    for(int _=1;_<=t;_++){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            ans[i]=0;
            vis[i]=false;
        }
        for(int i=1;i<=m;i++){
            char a;
            cin>>a;
            if(a=='U'){
                cin>>f[i].z;
                f[i].x=0;
                f[i].y=0;
            }
            if(a=='T'){
                cin>>f[i].z;
                f[i].x=0;
                f[i].y=1;
            }
            if(a=='F'){
                cin>>f[i].z;
                f[i].x=0;
                f[i].y=-1;
            }
            if(a=='-'){
                f[i].x=-1;
                cin>>f[i].y>>f[i].z;
            }
            if(a=='+'){
                f[i].x=1;
                cin>>f[i].y>>f[i].z;
            }
            ans[f[i].z]=f[i].y;
            vis[f[i].z]=true;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==true&&ans[i]==0){
                cnt++;
            }
        }
        cout<<cnt<<endl;
        cnt=0;
    }
    return 0;
}
